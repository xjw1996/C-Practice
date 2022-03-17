#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <numeric>



//C++でファイル入力出力には，fstreamを使う。
//ifstreamクラスでファイルから入力
//ofstreamクラスでファイルへ出力する

class Center_of_Gravity {
public:
    void readfile();
    void Calculate_COG(std::vector<int> A, std::vector<int> B);
private:
    std::ifstream file;
    std::string path = "D:\\program\\data.csv";
    std::vector<int> A;
    std::vector<int> B;
    double ave1;
    double ave2;
    /*std::string* path = new  std::string;
    path = &s;*/
};

void Center_of_Gravity::readfile() {
    file.open(path);
    //ダブルスラッシュ　double slash
    /*Keep in mind that when written in C++ source code,
    you must use the double backslash because the backslash character
    itself means something special inside double quoted strings.
    So the above refers to the file C : \Demo.txt.*/
    /*「\」が１個ずつ足りないのだ。CやC++の文字列定数の中ではタブ「\t」，
     改行「\n」やナルキャラクタ「\0」という記法を許しているため，文字「\」は何らかの特別な意味を持ってしまう。
     文字「\」そのものを文字列定数の中に指定したいときは，「\」を２つ並べて「\\」のように書く必要がある。*/

    if (!file.is_open())
    {
        std::cout << "Error opening file";
        exit(1);
        //引数値が 1 の exit 関数は、失敗した終了を示すために使用されます。
        // 成功した呼び出しステータスコードの値を返す一部の関数は、戻り値を検証し、
        // エラーが発生した場合にプログラムを終了する条件ステートメントと組み合わせることができます。
        //exit(1) は exit(EXIT_FAILURE) を呼び出すのと同じであることに注意してください。
    }
    //数据的按行读取，使用函数getline，但需要引入头文件#include <string>
    std::string buf;
    int tem_a, tem_b;
    while (std::getline(file, buf))//getline(file,buf,',') 数据可以不用逗号隔开
    {
        sscanf_s(buf.data(), "%d,%d", &tem_a, &tem_b);
        this->A.push_back(tem_a);
        this->B.push_back(tem_b);
       /* std::cout << tem_a << " " << tem_b <<std::endl;*/
       /* std::cout << buf.data() << std::endl;*/
        /*std::cout << buf.c_str();*/
    }
    file.close();
     /*std::cout << A.size() << std::endl;*/
    Calculate_COG(this->A,this->B);
}

void Center_of_Gravity::Calculate_COG(std::vector<int> A, std::vector<int> B) {
    this->ave1 = std::accumulate(A.begin(), A.end(), 0);
    this->ave2 = std::accumulate(B.begin(), B.end(), 0);
    std::cout << "The center of gravity is (" << this->ave1/A.size() << " , " << this->ave2/B.size() <<")" << std::endl;
}
int main()
{
    Center_of_Gravity COG;
    COG.readfile();
    
}
