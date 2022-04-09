#include <iostream>
#include <string>
#include <vector>

//这个例子太经典了 F11一步一步运行程序就会看的很明白
std::vector<std::string> split(std::string str, char del) {
    int first = 0;
    int last = str.find_first_of(del);
    //std::cout << last << std::endl;
    std::vector<std::string> result;

    //最终因为找不目标del位置，last被赋值字符串本身的长度 在进行加1的运算之后会超过字符串的长度
    //超过字符串长度跳出循环 返回result
    while (first < str.size()) {
        /*
        substr関数の使い方
        std::string str = 文字列;
        str.substr(開始位置, 取り出す長さ);*/
        std::string subStr(str, first, last - first);
        //str传入string流的字符串，first表示从第几位开始，last - first代表 取り出す長さ
        //std::cout << subStr << std::endl;
        result.push_back(subStr);

        first = last + 1;
        //find_first_of 代表字符串str中第first的位置开始往后（从前往后）找出del在字符串中的第几个位置
        last = str.find_first_of(del, first);
        //std::cout << last << std::endl;
        //何も見つからなかった場合は-1を返しくれる 找不到就会返回-1
        
        //見つかればその位置を返し、見つからない場合は basic_string::npos を返す
        if (last == std::string::npos) {
            last = str.size();
            //std::cout << last <<"-------------"<< std::endl;
        }
    }

    return result;
}

int main() {
    std::string str = "samurai,engineer,programmer,se";
    char del = ',';
    //类似于for循环
    //https://cpprefjp.github.io/lang/cpp11/range_based_for.html
    for (const auto &subStr : split(str, del)) {
        std::cout << subStr << std::endl;
        
    }

    return 0;
    //参考文献
    //https://blog.csdn.net/qq_36251561/article/details/107752098
    //https://www.sejuku.net/blog/58892
    //https://www.sejuku.net/blog/49378
    //https://tora-k.com/2019/07/07/file-output/
    //https://qiita.com/7shi/items/cac7b3e9b90bf91b00cc
  
    //Youtube 视频
    //https://www.youtube.com/watch?v=hkJT-209AuI&t=126
    
}
