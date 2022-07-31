#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(string name = "", int age = 0, float score = 0.0f);  //普通构造函数
    Student(const Student& stu);  //拷贝构造函数
    ~Student();//析构
public:
    Student& operator=(const Student& stu);  //重载=运算符
    void display();
    void func(Student s) {
        //TODO:
    }
private:
    string m_name;
    int m_age;
    float m_score;
    

};

Student::Student(string name, int age, float score) : m_name(name), m_age(age), m_score(score) { }

//拷贝构造函数
Student::Student(const Student& stu) {
    cout << "拷贝构造---被调用类的地址" << this << "\t" << "形参传进来类的地址" << &stu << endl;
    this->m_name = stu.m_name;
    this->m_age = stu.m_age;
    this->m_score = stu.m_score;
    cout << "Copy constructor was called." << endl;
}

//重载=运算符
Student& Student::operator=(const Student& stu) {
    if (this == &stu) {
        cout << "指向同一块地址" << endl;
        return *this;
    }
    //可以用cout<<" " <<endl; 也可以用制表符:“\t”在字符常量和字符串常量中是代表一定的距离(比如8个空格),而在其它地方只是代表一个间隔,不代表固定大小的空白距离。”
    cout << "运算符重载---被调用类的地址"<< this <<"\t" <<"形参传进来类的地址"<< &stu << endl;
    this->m_name = stu.m_name;
    this->m_age = stu.m_age;
    this->m_score = stu.m_score;
    cout << "operator=() was called." << endl;

    return *this;
}

void Student::display() {
    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
}

int main() {
    //stu1、stu2、stu3都会调用普通构造函数Student(string name, int age, float score)
    Student stu1("小明", 16, 90.5);
    Student stu2("王城", 17, 89.0);
    Student stu3("陈晗", 18, 98.0);

    Student stu4 = stu1;  //调用拷贝构造函数Student(const Student &stu)
    stu4 = stu2;  //调用operator=()
    stu4 = stu3;  //调用operator=()

    Student stu5;  //调用普通构造函数Student()
    stu5 = stu1;  //调用operator=()
    stu5 = stu2;  //调用operator=()

  /*  
            *****运算符重载在terminal里面的输出**********
            * 拷贝构造函数与运算符重载的运行结果可以看出从，当两种函数背调用时候，拷贝与运算符重载都会开辟一块新的内存
    拷贝构造---被调用类的地址006FF724       形参传进来类的地址006FF7A8
    Copy constructor was called.
    运算符重载---被调用类的地址006FF724     形参传进来类的地址006FF77C
    operator=() was called.
    运算符重载---被调用类的地址006FF724     形参传进来类的地址006FF750
    operator=() was called.
    运算符重载---被调用类的地址006FF6F8     形参传进来类的地址006FF7A8
    operator=() was called.
    运算符重载---被调用类的地址006FF6F8     形参传进来类的地址006FF77C
    operator=() was called.
    拷贝构造---被调用类的地址006FF57C       形参传进来类的地址006FF7A8
    Copy constructor was called.
    
    */



    Student stu6;
    //类的对象是不可以访问私有成员函数变量的，只有类的公有成员函数才可以访问私有的成员变量
    //继承类成员函数可以访问 protect  类型
    stu6.func(stu1);//函数的形参为类的类型的时候，默认调用的是拷贝构造函数。

    return 0;
}
