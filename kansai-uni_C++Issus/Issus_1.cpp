
#include <iostream>
#include <iomanip>
//#include <vector>

void arrangement()
{
    std::cout.setf(std::ios::left);
    for (int x = 0; x < 100; x++) {
        if ((x + 1) % 10 == 0)
            std::cout << x << std::endl;
        else
            std::cout << std::setw(3) << x << " ";
        //setw(n)
        //etw() 函数只对紧接着的输出产生作用。
        //当后面紧跟着的输出字段长度小于 n 的时候，在该字段前面用空格补齐，当输出字段长度大于 n 时，全部整体输出。
    }
}

int main()
{
    arrangement();
    int x_, y_;
    std::cin >> x_ >> y_;
    std::cout << ((x_-1) * 10) + (y_-1) << std::endl;
}


