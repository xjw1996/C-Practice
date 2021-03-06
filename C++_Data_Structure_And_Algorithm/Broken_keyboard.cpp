#include <iostream>
#include <string>
#include <list>//链表
#include <algorithm>

class broken_keyboard {
public:
    void input();
    void solve(std::string s);
    void print() { std::cout << "I am s_" << s_ << std::endl; }
private:
    std::string s_;
};

void broken_keyboard::solve(std::string s)
{
    std::list<char> test;
    std::list<char>::iterator arr_ptr = test.begin();// 这道题的指针需要初始化
    int len = s.size();
    for (int i = 0;i < len;i++) {
        if (s[i] =='[') {// <-- Single quotes here.双引号是 C++ 中 c 字符串的快捷语法。如果要比较单个字符，则必须改用单引号
            arr_ptr = test.begin();
        }
        if (s[i] == ']') {
            arr_ptr = test.end();
        }
        if (s[i] != '[' && s[i] != ']') {
            test.insert(arr_ptr, s[i]);
        }
    }
    for (arr_ptr = test.begin();arr_ptr != test.end();arr_ptr++) 
        std::cout << *arr_ptr;
    std::cout <<  "------------------------" << std::endl;
}

void broken_keyboard::input()
{
    while (std::cin >> s_) {
        solve(s_);
        //std::cin.clear();
        this->s_.clear();
        print();
      /*  arr_ptr = test.begin();*/
    }
    
}


int main()
{
    broken_keyboard bk;
    bk.input();
}

