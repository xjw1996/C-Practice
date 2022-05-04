
#include <iostream>
#include<string>
#include<vector>

int main()
{
    //参考文献https://www.sejuku.net/blog/25765
    int i = 1,j = 6;
    std::string test = "2";
    //atoiは整数値の文字列型データをint型に変換する関数です
    //数値の文字列型データを数値データに変換する関数は他にもatol、atofがあります。
    //atolは数値の文字列型データをlong型に変換し、atofはfloat型に変換します
    int inum = std::atoi(test.c_str());
    int a;
    a = i - inum;
    std::cout << a << std::endl;


    std::vector<int> v = { 3, 1, 4 ,5 ,7 ,8 ,9 ,10 ,2 ,6 };

    //std::cout << v.size() << std::endl;
    // イテレート中に要素削除をするような場合には、
    // 範囲for文は使用できない
    bool TF = false;
    //false为 0，true为 1
    for (auto it = v.begin(); it != v.end();) {
        // 条件一致した要素を削除する
        if (*it == 0) {
            // 削除された要素の次を指すイテレータが返される。
            //it = v.erase(it);
            TF = true;
            break;
        }
        // 要素削除をしない場合に、イテレータを進める
        else {
            //std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << TF << std::endl;

    // 
    // 
    //v.erase(v.begin() + 2);
    ////std::cout << v.size() << std::endl;

    //for (const auto& x : v) {
    //    std::cout << x << std::endl;
    //}

}

