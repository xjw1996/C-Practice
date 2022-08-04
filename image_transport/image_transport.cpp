
#include "image_transport/image_transport.hpp"

#include <memory>

#include <pluginlib/class_loader.hpp>

#include "image_transport/camera_common.hpp"
#include "image_transport/loader_fwds.hpp"
#include "image_transport/publisher_plugin.hpp"
#include "image_transport/subscriber_plugin.hpp"

namespace image_transport
{

struct Impl
{
  PubLoaderPtr pub_loader_;
  SubLoaderPtr sub_loader_;

  Impl()
  : pub_loader_(std::make_shared<PubLoader>("image_transport", "image_transport::PublisherPlugin")),
    sub_loader_(std::make_shared<SubLoader>("image_transport", "image_transport::SubscriberPlugin"))
  {
  }
};

static Impl * kImpl = new Impl();

Publisher create_publisher(
  rclcpp::Node * node,
  const std::string & base_topic,
  rmw_qos_profile_t custom_qos)
{
  return Publisher(node, base_topic, kImpl->pub_loader_, custom_qos);
}

Subscriber create_subscription(
  rclcpp::Node * node,
  const std::string & base_topic,
  const Subscriber::Callback & callback,
  const std::string & transport,
  rmw_qos_profile_t custom_qos,
  rclcpp::SubscriptionOptions options)
{
  return Subscriber(node, base_topic, callback, kImpl->sub_loader_, transport, custom_qos, options);
}

CameraPublisher create_camera_publisher(
  rclcpp::Node * node,
  const std::string & base_topic,
  rmw_qos_profile_t custom_qos)
{
  return CameraPublisher(node, base_topic, custom_qos);
}

CameraSubscriber create_camera_subscription(
  rclcpp::Node * node,
  const std::string & base_topic,
  const CameraSubscriber::Callback & callback,
  const std::string & transport,
  rmw_qos_profile_t custom_qos)
{
  return CameraSubscriber(node, base_topic, callback, transport, custom_qos);
}

std::vector<std::string> getDeclaredTransports()
{
  std::vector<std::string> transports = kImpl->sub_loader_->getDeclaredClasses();
  // Remove the "_sub" at the end of each class name.
  for (std::string & transport: transports) {
    transport = erase_last_copy(transport, "_sub");
  }
  return transports;
}

std::vector<std::string> getLoadableTransports()
{
  std::vector<std::string> loadableTransports;

  for (const std::string & transportPlugin: kImpl->sub_loader_->getDeclaredClasses() ) {
    // If the plugin loads without throwing an exception, add its
    // transport name to the list of valid plugins, otherwise ignore
    // it.
    try {
      std::shared_ptr<image_transport::SubscriberPlugin> sub =
        kImpl->sub_loader_->createUniqueInstance(transportPlugin);
      loadableTransports.push_back(erase_last_copy(transportPlugin, "_sub")); // Remove the "_sub" at the end of each class name.
    } catch (const pluginlib::LibraryLoadException & e) {
		(void) e;
    } catch (const pluginlib::CreateClassException & e) {
		(void) e;
    }
  }

  return loadableTransports;
}

struct ImageTransport::Impl
{
  rclcpp::Node::SharedPtr node_;
};

ImageTransport::ImageTransport(rclcpp::Node::SharedPtr node)
: impl_(std::make_unique<ImageTransport::Impl>())
{
  impl_->node_ = node;
}

ImageTransport::~ImageTransport() = default;

Publisher ImageTransport::advertise(const std::string & base_topic, uint32_t queue_size, bool latch)
{
  // TODO(ros2) implement when resolved: https://github.com/ros2/ros2/issues/464
  (void) latch;
  rmw_qos_profile_t custom_qos = rmw_qos_profile_default;
  custom_qos.depth = queue_size;
  return create_publisher(impl_->node_.get(), base_topic, custom_qos);
}

Subscriber ImageTransport::subscribe(
  const std::string & base_topic, uint32_t queue_size,
  const Subscriber::Callback & callback,
  const VoidPtr & tracked_object,
  const TransportHints * transport_hints)
{
  (void) tracked_object;
  rmw_qos_profile_t custom_qos = rmw_qos_profile_default;
  custom_qos.depth = queue_size;
  return create_subscription(impl_->node_.get(), base_topic, callback,
           getTransportOrDefault(transport_hints), custom_qos);
}

CameraPublisher ImageTransport::advertiseCamera(
  const std::string & base_topic, uint32_t queue_size,
  bool latch)
{
  // TODO(ros2) implement when resolved: https://github.com/ros2/ros2/issues/464
  (void) latch;
  rmw_qos_profile_t custom_qos = rmw_qos_profile_default;
  custom_qos.depth = queue_size;
  return create_camera_publisher(impl_->node_.get(), base_topic, custom_qos);
}

CameraSubscriber ImageTransport::subscribeCamera(
  const std::string & base_topic, uint32_t queue_size,
  const CameraSubscriber::Callback & callback,
  const VoidPtr & tracked_object,
  const TransportHints * transport_hints)
{
  (void) tracked_object;
  rmw_qos_profile_t custom_qos = rmw_qos_profile_default;
  custom_qos.depth = queue_size;
  return create_camera_subscription(impl_->node_.get(), base_topic, callback,
           getTransportOrDefault(transport_hints), custom_qos);
}

std::vector<std::string> ImageTransport::getDeclaredTransports() const
{
  return image_transport::getDeclaredTransports();
}

std::vector<std::string> ImageTransport::getLoadableTransports() const
{
  return image_transport::getLoadableTransports();
}

std::string ImageTransport::getTransportOrDefault(const TransportHints * transport_hints)
{
  std::string ret;
  if (nullptr == transport_hints) {
    TransportHints th(impl_->node_.get());
    ret = th.getTransport();
  } else {
    ret = transport_hints->getTransport();
  }
  return ret;
}

} //namespace image_transport