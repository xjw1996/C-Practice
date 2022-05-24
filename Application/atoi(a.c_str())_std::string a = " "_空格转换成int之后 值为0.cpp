//#pragma execution_character_set("utf-8")

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <errno.h>
#include <numeric>
#include <windows.h>
#include <algorithm>
#include <map>
#include <locale>
#include <stdio.h>
#include <string.h>

struct weici_2019_
{
    std::string College;
    std::string wc2019;
};

struct _college_order052420212019
{
    std::string province;
    std::string year;
    std::string Science;
    std::string pici;
    std::string College_name;
    std::string major;
    std::string plan;
    std::string average;
    std::string low_score;
    std::string weici;
};

struct toudangxian_2020_
{
    std::string College;
    std::string note;
    std::string pici;
    std::string toudangxian2020;
    std::string weici2020;

};

struct Science
{
    std::string Number;
    std::string CollegeCode;
    std::string College;
    std::string Note;
    std::string Pici;
    std::string Toudang2021;
    std::string Plan2021;
    std::string Weici2021;

    std::string Toudang2020;
    std::string Weici2020;
    std::string Weicicha;
    std::string Weici2019;
    std::string Isit985;
    std::string Isit211;
    std::string IsitDoubleTop;
    std::string City;
    std::string Province;
    std::string Characteristic;
};
struct SpecialtyList {
    std::string CollegeCode;
    std::string College;
    std::string Note;
    std::string Province;
    std::string Year;
    std::string MajorCode;
    std::string Major;
    std::string MajorNote;
    std::string ArtsOrScience;
    std::string Batch;
    std::string HighestScore;
    std::string LowestScore;
    std::string LowestPosition;
    std::string NumberOfAdmissions;
    std::string NumberOfPlans;
    std::string Isit985;
    std::string Isit211;
    std::string IsitDoubleTop;
    std::string Characteristic;
    std::string Level;
    std::string Type;
    std::string ProvincialCapital;
    std::string City;
    std::string ProvinceWhereTheSchoolIsLocated;
};

class Dataset_classification {
public:
    //void readfile();
    void readexcel();
    //void readexcel2019();
    void readexcel2020toudangxiam();
    void Sorting_college();



    //std::string path_2020college = "D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\位次差计算以及省份城市追加\\理科二本\\522\\2020年大学数据\\2020年大学数据.csv";
    

    std::string CollegeOrderPath = "D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\位次差计算以及省份城市追加\\理科二本\\522\\0522_2021-2019理科院校录取位次及位次差\\最终版本\\大学顺序.csv";
    std::string DataOriginal2020 = "D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\位次差计算以及省份城市追加\\理科二本\\522\\2020年大学数据\\2020年大学数据.csv";
    std::string outpath2020 = "D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\位次差计算以及省份城市追加\\理科二本\\522\\0522_2021-2019理科院校录取位次及位次差\\最终版本\\2020大学新顺序\\";
    //void classification();
    std::vector<std::string> split(std::string str, char del);
    std::vector<std::string> split_(std::string str, std::string del);
    std::vector<Science> BubbleSort(std::vector<Science> A, int n);
private:

    std::ofstream out;
    std::string path_2020 = "D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\位次差计算以及省份城市追加\\文科二本\\522\\2020投档线位次备注.csv";
    std::string path = "D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\位次差计算以及省份城市追加\\文科二本\\522\\文科二本复制.csv";
    //std::string path_ = "C:\\Users\\jinue\\Desktop\\数据\\20200428\\文科二本\\前半部分.csv";
    std::string outpath = "D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\位次差计算以及省份城市追加\\文科二本\\522\\0524_2021-2019文科二本院校录取位次及位次差\\";
    
    std::string variable_path;
    std::vector<SpecialtyList> Data_arr;
    std::vector<Science> output_arr;

    std::vector<std::string> College_arr;

    std::vector<std::string> College_order_arr;
    std::vector<_college_order052420212019> College_2020data;


    std::vector<weici_2019_> weici_2019_arr;
    std::vector<toudangxian_2020_> toudangxian_2020_arr;

    bool DoesItExist;
    //模糊搜寻
    bool Search_MajorNote;
    //std::map<std::string, std::vector<std::string>>maptest;
    std::vector<std::vector<SpecialtyList>> data_2Darr;
};

std::vector<std::string> Dataset_classification::split(std::string str, char del) {
    int first = 0;
    int last = str.find_first_of(del);
    //std::cout << last << std::endl;
    std::vector<std::string> result;
    while (first < str.size()) {
        std::string subStr(str, first, last - first);
        result.push_back(subStr);
        first = last + 1;
        last = str.find_first_of(del, first);
        if (last == std::string::npos) {
            last = str.size();
        }
    }

    return result;
}

std::vector<std::string> Dataset_classification::split_(std::string str, std::string del) {
    int first = 0;
    int last = str.find_first_of(del);
    //std::cout << str.size() << std::endl;
    //std::cout << last << std::endl;
    std::vector<std::string> result;
    std::string del_, space;
    int i = (str.size() - 1);
    while (first < str.size()) {
        std::string subStr(str, first, last - first);
        result.push_back(subStr);
        //std::cout << str[last] << std::endl;
        /*if (str[last] == str[last - 1]) {
            result.push_back(" ");
        }
        */
        if (last == i) {
            result.push_back(" ");
        }
        first = last + 1;
        last = str.find_first_of(del, first);
        if (last == std::string::npos) {
            last = str.size();
        }
    }

    return result;
}

std::vector<Science> Dataset_classification::BubbleSort(std::vector<Science> A, int n) {
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            //|| A[j + 1].Weici2020 == " "
            //std::string a = " ";
            //std::cout << atoi(a.c_str()) << std::endl;//空格转换成int之后 值为0
            if ( atoi(A[j].Weici2020.c_str()) > atoi(A[j+1].Weici2020.c_str()) ) {
                std::swap(A[j], A[j + 1]);
            }

    return A;
}

std::string UTF8ToGB(const char* str)
{
    std::string result;
    WCHAR* strSrc;
    LPSTR szRes;

    //获得临时变量的大小
    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i + 1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    //获得临时变量的大小
    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new CHAR[i + 1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    result = szRes;
    delete[]strSrc;
    delete[]szRes;

    return result;
}

std::string G2U(const char* gb2312)
{
    int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
    wchar_t* wstr = new wchar_t[len + 1];
    memset(wstr, 0, len + 1);
    MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
    len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* str = new char[len + 1];
    memset(str, 0, len + 1);
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
    if (wstr) delete[] wstr;
    return str;
}
//void Dataset_classification::readexcel2019() {
//    std::string del_ = ",";
//    std::ifstream file3;
//    file3.open(path_2019);
//    if (!file3.is_open())
//    {
//        std::cout << "Error opening excel file2";
//        exit(1);
//    }
//    weici_2019_ tem_2019;
//    std::string LineOfData_2019;
//    while (std::getline(file3, LineOfData_2019))
//    {
//        std::string str = UTF8ToGB(LineOfData_2019.c_str()).c_str();
//        /*std::cout << str << std::endl;*/
//        std::vector<std::string> tem_result2 = split_(str, del_);
//
//
//        std::cout << tem_result2.size() << std::endl;
//
//        tem_2019.College = tem_result2[0];
//        tem_2019.wc2019 = tem_result2[1];
//
//        weici_2019_arr.push_back(tem_2019);
//    }
//    file3.close();
//}

void Dataset_classification::Sorting_college(){
    std::string del_ = ",";
    std::ifstream file6;
    file6.open(DataOriginal2020);
    if (!file6.is_open())
    {
        std::cout << "Error opening excel file6";
        exit(1);
    }
    _college_order052420212019 temcollege2020data;
    std::string college2020line;
    while (std::getline(file6, college2020line)) {
        std::string str = UTF8ToGB(college2020line.c_str()).c_str();
        /*std::cout << str << std::endl;*/
        std::vector<std::string> tem_result2 = split_(str, del_);
        temcollege2020data.province = tem_result2[0];
        temcollege2020data.year = tem_result2[1];
        temcollege2020data.Science = tem_result2[2];
        temcollege2020data.pici = tem_result2[3];
        temcollege2020data.College_name = tem_result2[4];
        temcollege2020data.major = tem_result2[5];
        temcollege2020data.plan = tem_result2[6];
        temcollege2020data.average = tem_result2[7];
        temcollege2020data.low_score = tem_result2[8];
        temcollege2020data.weici = tem_result2[9];
        College_2020data.push_back(temcollege2020data);
    }
    file6.close();



    //std::string del_ = ",";
    std::ifstream file5;
    file5.open(CollegeOrderPath);
    if (!file5.is_open())
    {
        std::cout << "Error opening excel file7";
        exit(1);
    }
    
    std::string sort_college;
    while (std::getline(file5, sort_college)) {
        std::string str = UTF8ToGB(sort_college.c_str()).c_str();
        /*std::cout << str << std::endl;*/
        std::vector<std::string> tem_result2 = split_(str, del_);
        College_order_arr.push_back(tem_result2[0]);
    }
    file5.close();

    out.open(outpath2020 + "2020理科二本大学数据重新排序.csv", std::ios::out | std::ios::binary);
    if (out.fail()) {
        std::cerr << "fail" << std::endl;
        return;
    }
    for (std::string i : College_order_arr) {
        for (auto it = this->College_2020data.begin();it != this->College_2020data.end();++it) {
            if (i == it->College_name) {
                out << it->College_name << ","<< it->pici <<","<< it->year << "," << it->major << ","
                    <<it->plan << "," << it->average << "," << it->low_score << "," << it->weici << ","<<std::endl;
            }
        }
    }
    std::cout << "Open file successfully" << std::endl;
    out.close();


    exit(0);

}

void Dataset_classification::readexcel2020toudangxiam() {
    std::string del_ = ",";
    std::ifstream file4;
    file4.open(path_2020);
    if (!file4.is_open())
    {
        std::cout << "Error opening excel file3";
        exit(1);
    }
    toudangxian_2020_ tem_toudangxian2020;
    std::string LineOfData_toudangxian2020;

    while (std::getline(file4, LineOfData_toudangxian2020))
    {
        std::string str = UTF8ToGB(LineOfData_toudangxian2020.c_str()).c_str();
        /*std::cout << str << std::endl;*/
        std::vector<std::string> tem_result2 = split_(str, del_);
        tem_toudangxian2020.College = tem_result2[0];
        tem_toudangxian2020.note = tem_result2[1];
        tem_toudangxian2020.pici = tem_result2[2];
        tem_toudangxian2020.toudangxian2020 = tem_result2[3];
        tem_toudangxian2020.weici2020 = tem_result2[4];

        toudangxian_2020_arr.push_back(tem_toudangxian2020);
    }
    file4.close();
}

void Dataset_classification::readexcel() {
    std::string del_ = ",";
    std::ifstream file2;
    file2.open(path);
    if (!file2.is_open())
    {
        std::cout << "Error opening excel file2";
        exit(1);
    }
    Science tem_Science;
    std::string LineOfData_;
    while (std::getline(file2, LineOfData_))
    {
        std::string str = UTF8ToGB(LineOfData_.c_str()).c_str();
        /*std::cout << str << std::endl;*/
        std::vector<std::string> tem_result2 = split_(str, del_);
        std::cout << std::endl;
        tem_Science.Number = tem_result2[0];
        tem_Science.CollegeCode = tem_result2[1];
        tem_Science.College = tem_result2[2];
        tem_Science.Note = tem_result2[3];
        tem_Science.Pici = tem_result2[4];
        tem_Science.Toudang2021 = tem_result2[5];
        tem_Science.Plan2021 = tem_result2[6];
        tem_Science.Weici2021 = tem_result2[7];


        tem_Science.Toudang2020 = " ";
        /*if (tem_result2[9] == " ") {
            tem_Science.Weici2020 = "0";
        }
        else
        {
            tem_Science.Weici2020 = tem_result2[9];
        }*/
        tem_Science.Weici2020 = tem_result2[9];
        tem_Science.Weicicha = tem_result2[10];
        tem_Science.Weici2019 = tem_result2[11];

        /*tem_Science.Isit985 = tem_result2[12];
        tem_Science.Isit211 = tem_result2[13];
        tem_Science.IsitDoubleTop = tem_result2[14];*/
        tem_Science.City = tem_result2[12];
        tem_Science.Province = tem_result2[13];
        tem_Science.Characteristic = tem_result2[14];
        output_arr.push_back(tem_Science);
    }
    file2.close();
    //readexcel2019();
    readexcel2020toudangxiam();

    //for (int i = 0;i < this->output_arr.size();i++) {
    //    for (auto it = this->toudangxian_2020_arr.begin(); it != this->toudangxian_2020_arr.end(); ++it) {
    //        /*int Serach_ = it->MajorNote.find(two_Major_arr[i]);*/
    //        if (it->College == output_arr[i].College && it->note.find(output_arr[i].Note)!= std::string::npos&& it->weici2020==output_arr[i].Weici2020) {
    //            output_arr[i].Toudang2020 = it->toudangxian2020;
    //        }
    //    }
    //}
     
    //这篇文章讲解了C++ for(auto i:vector)的使用方法  有两种写法显示数组中的值  和修改数组中的值
    //https://blog.csdn.net/qq_28087491/article/details/108171017
    
    //符号 & 表明 i 是一个引用变量，能让接下来的代码能够修改数组的内容
    for (Science &i : output_arr) {
        //std::cout << i.College << std::endl;
        for (auto it = this->toudangxian_2020_arr.begin(); it != this->toudangxian_2020_arr.end(); ++it) {

            //int Serach_ = it->MajorNote.find(two_Major_arr[i]);
            
            if (it->College == i.College &&it->note.find(i.Note) != std::string::npos && it->weici2020 == i.Weici2020) {
                i.Toudang2020 = it->toudangxian2020;
                std::cout << i.Toudang2020 << std::endl;
                
            }
        }
    }



    //std::sort(output_arr..begin(), sorted_container.end());

    int arr_length = output_arr.size();
    output_arr = BubbleSort(output_arr, arr_length);
    
    for (Science i : output_arr) {
        std::cout << i.Weici2020 << std::endl;
    }

    out.open(outpath + "2021-2020文科二本院校录取位次及位次差.csv", std::ios::out | std::ios::binary);
    if (out.fail()) {
        std::cerr << "fail" << std::endl;
        return;
    }
    for (int j = 0;j < output_arr.size();j++) {
        out << output_arr[j].Number << "," << output_arr[j].CollegeCode << "," << output_arr[j].College << "," << output_arr[j].Note << ","
            << output_arr[j].Pici << "," << output_arr[j].Toudang2021 << "," << output_arr[j].Plan2021 << "," << output_arr[j].Weici2021 << ","
            << output_arr[j].Toudang2020 << "," << output_arr[j].Weici2020 << "," << output_arr[j].Weicicha << "," << output_arr[j].Weici2019 << "," 
            << output_arr[j].City << "," << output_arr[j].Province << "," << output_arr[j].Characteristic << std::endl;
    }
    std::cout << "Open file successfully" << std::endl;
    out.close();


    exit(0);


}



int main()
{
    Dataset_classification Data_cla;
    Data_cla.readexcel();
    //Data_cla.Sorting_college();
}
