
#include <iostream>
#include <vector>
#include <algorithm>//std::sort
#include <functional>//std::greater
#include <numeric>//std::accumulate
#include <math.h> //平方pow(), //开方sqrt(), //绝对值abs(),//浮点数绝对值 float double fabs()

class statistic{
public:
    int Max_value(int& a,int& b,int& c);
    int Min_value(int& a, int& b, int& c);
    float average(int& a, int& b, int& c);
    float variance(int& a, int& b, int& c, float& ave);
    void M();
private:
    int m_a = 10, m_b = 100, m_c = 1000;
    float ave;
};

int statistic::Max_value(int& a, int& b, int& c) {
    // std::greater<int>()
    //http://www.cplusplus.com/reference/functional/greater/
    //Member function returning whether the first argument compares greater than the second (x>y).
    std::vector<int> max_sort = { a,b,c };
    std::sort(max_sort.begin(), max_sort.end(), std::greater<int>());
    return max_sort[0];
}

int statistic::Min_value(int& a, int& b, int& c) {
    std::vector<int> min_sort = { a,b,c };
    std::sort(min_sort.begin(), min_sort.end());
    return min_sort[0];
}

float statistic::average(int& a, int& b, int& c) {
    std::vector<int> arr = { a,b,c };
    int sum=std::accumulate(arr.begin(), arr.end(), 0);
    //The result of accumulating init and all the elements in the range [first,last).
    //http://www.cplusplus.com/reference/numeric/accumulate/
    this->ave = sum / arr.size();
    return ave;
}

float statistic::variance(int& a, int& b, int& c,float& ave) {
    std::vector<int> arr = { a,b,c };
    float var = (std::pow((ave - a), 2) + std::pow((ave - b), 2) + std::pow((ave - c), 2)) / arr.size();
    return var;
}

void statistic::M() {
    std::cout << "Max number is" << Max_value(m_a, m_b, m_c) << std::endl;
    std::cout << "Min number is" << Min_value(m_a, m_b, m_c) << std::endl;
    std::cout << "Average number is" << average(m_a, m_b, m_c) << std::endl;
    std::cout << "Variance number is" << variance(m_a, m_b, m_c, ave) << std::endl;
}

int main()
{
    statistic s;
    s.M();
}


