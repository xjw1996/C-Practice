#include <iostream>
#include<cmath>
#include<vector>


class test {
public:
    void print();
    std::vector<int> BubbleSort(std::vector<int> A, int n);
private:
    int arr[5] = { 10,2,18,56,29 };
    std::vector<int> vector_arr;

};


void test::print() {
    std::vector<int> tem;

    for (int i = 0;i < 5;i++) 
        vector_arr.push_back(arr[i]);

    tem=BubbleSort(vector_arr, vector_arr.size());

    for (int j=0;j< tem.size();j++)
        std::cout << tem[j] << " ";
}
std::vector<int> test::bubbleSort(std::vector<int> A, int n)
{
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]); 
            }  

    return A;
}

int main()
{
    test t;
    t.print(); 
}

