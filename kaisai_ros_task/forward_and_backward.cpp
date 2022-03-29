#include <ros/ros.h>
#include <math.h>
#include <std_msgs/String.h>
#include <iostream>
#include <string>
#include <vector>
#include <geometry_msgs/Twist.h>

struct move_param
{
  double x;
  double z;
};
class forward_and_backward{
  public:
    forward_and_backward();
    ros::Time GetBegainTime() const {return m_BegainTime;}
    void mainloop();
    move_param control_twist(double dt);
  private:  
    geometry_msgs::Twist twist_msg();
    ros::NodeHandle nh;
    ros::Time init_time;
    ros::Duration past_time;
    ros::Publisher twist_pub;
    const ros::Time m_BegainTime = ros::Time::now();
    double whill_lineaX;
    double whill_angularZ;
    std::string pub_cmd_vel_topic;
};

forward_and_backward::forward_and_backward()
{
  ros::NodeHandle ph_("~");
  ph_.param("whill_lineaX", whill_lineaX, 0.1);
  ph_.param("whill_angularZ", whill_angularZ, 0.1);
  ph_.param("pub_cmd_vel_topic", pub_cmd_vel_topic, std::string("/vmegarover/diff_drive_controller/cmd_vel"));
  ROS_INFO("BegainTime is: [%f]", GetBegainTime());
  twist_pub = nh.advertise<geometry_msgs::Twist>(pub_cmd_vel_topic, 1);
}
//指针传递编译可通过，到主循环里会报错 process has died 日后再解决
move_param forward_and_backward::control_twist(double dt)
{
  move_param mp;
  ROS_INFO("control_twist Fuction called by mainloop !!!!!!!");

  if(dt<=15){
    mp.x=whill_lineaX;
    mp.z=0.0;
  }else if(dt>=15 && dt<=20){
    mp.x=-whill_lineaX;
    mp.z=0.0;
  }else if(dt>=20 && dt<=36){
    mp.x=-0.0;
    mp.z=whill_angularZ;
  }
  return mp;

}

void forward_and_backward::mainloop()
{
  ROS_INFO("start moving");
  ros::Rate rate(10.0);
  // past_time = ros::Time::now() - GetBegainTime();
  // ROS_INFO("Past_time is: [%f]", past_time);
  while (ros::ok())
  {
    init_time = GetBegainTime();
    past_time = ros::Time::now() - init_time;
    move_param mp_;
    // ROS_INFO("Past_time is: [%f]", past_time);
    double dt=past_time.toSec();
    ROS_INFO("Past_time is: [%f]", dt);
    mp_=control_twist(dt);
    ROS_INFO("mpx is: [%f]", mp_.x);
    ROS_INFO("mpz is: [%f]", mp_.z);
    geometry_msgs::Twist twist;
    twist.linear.x = mp_.x;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = mp_.z;
    twist_pub.publish(twist);
    rate.sleep();
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "forward_and_backward");
  forward_and_backward FB;
  FB.mainloop();
  ros::spin();
}
