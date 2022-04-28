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
struct rear
{
    std::string College;
    std::string Isit985;
    std::string Isit211;
    std::string IsitDoubleTop;
    std::string City;
    std::string Province;
    std::string Characteristic;
};
struct Science
{
    std::string Number;
    std::string CollegeCode;
    std::string College;
    std::string Note;
    std::string Pici;
    std::string Plan2021;
    std::string PlanToudang;
    std::string Weici2021;
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
    void readfile();
    void readexcel();
    //void classification();
    std::vector<std::string> split(std::string str, char del);
    std::vector<std::string> split_(std::string str, std::string del);
    std::vector<SpecialtyList> BubbleSort(std::vector<SpecialtyList> A, int n);
private:

    std::ofstream out;
    std::string path = "D:\\xue_workspace\\DataOfUniversityScore\\文科二批.csv";
    std::string path_ = "C:\\Users\\jinue\\Desktop\\数据\\20200428\\文科二本\\前半部分.csv";
    std::string outpath = "C:\\Users\\jinue\\Desktop\\数据\\20200428\\文科二本\\";
    std::string variable_path;
    std::vector<SpecialtyList> Data_arr;
    std::vector<Science> output_arr;
    std::vector<rear> rear_arr;
    std::vector<std::string> College_arr;
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
    int i = (str.size()-1);
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

std::vector<SpecialtyList> Dataset_classification::BubbleSort(std::vector<SpecialtyList> A, int n) {
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (A[j].LowestScore < A[j + 1].LowestScore) {
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

void Dataset_classification::readexcel() {
    std::string del_ = ",";
    std::ifstream file2;
    file2.open(path_);
    if (!file2.is_open())
    {
        std::cout << "Error opening excel file2";
        exit(1);
    }
    Science tem_Science;
    std::string LineOfData_;
    int inum = 0;
    while (std::getline(file2, LineOfData_))
    {
        std::string str = UTF8ToGB(LineOfData_.c_str()).c_str();
        /*std::cout << str << std::endl;*/
        std::vector<std::string> tem_result2 = split_(str, del_);
        
        
        std::cout << inum << std::endl;
        std::cout << tem_result2.size() << std::endl;
        inum++;
        std::cout << std::endl;
        tem_Science.Number = tem_result2[0];
        tem_Science.CollegeCode = tem_result2[1];
        tem_Science.College = tem_result2[2];
        tem_Science.Note = tem_result2[3];
        tem_Science.Pici = tem_result2[4];
        tem_Science.Plan2021 = tem_result2[5];
        tem_Science.PlanToudang = tem_result2[6];
        tem_Science.Weici2021 = tem_result2[7];
        tem_Science.Weici2020 = tem_result2[8];
        tem_Science.Weicicha = tem_result2[9];
        tem_Science.Weici2019 = tem_result2[10];
        tem_Science.Isit985 = " ";
        tem_Science.Isit211 = " ";
        tem_Science.IsitDoubleTop = " ";
        tem_Science.City = " ";
        tem_Science.Province = " ";
        tem_Science.Characteristic = " ";
        output_arr.push_back(tem_Science);
    }
    file2.close();
}

void Dataset_classification::readfile() {
    char del = ',';
    std::ifstream file;
    file.open(path);
    if (!file.is_open())
    {
        std::cout << "Error opening file";
        exit(1);
    }

    SpecialtyList tem_specialty;
    std::string LineOfData;

    while (std::getline(file, LineOfData))
    {
        std::string str = UTF8ToGB(LineOfData.c_str()).c_str();
        std::vector<std::string> tem_result = split(str, del);
        /*std::cout << tem_result[0] <<" " << typeid(tem_result[0]).name()<< std::endl;
        std::cout << "tem_result.size()" << tem_result.size() << std::endl;*/
        tem_specialty.CollegeCode = tem_result[0];
        tem_specialty.College = tem_result[1];
        tem_specialty.Note = tem_result[2];
        tem_specialty.Province = tem_result[3];
        tem_specialty.Year = tem_result[4];
        tem_specialty.MajorCode = tem_result[5];
        tem_specialty.Major = tem_result[6];
        tem_specialty.MajorNote = tem_result[7];
        tem_specialty.ArtsOrScience = tem_result[8];
        tem_specialty.Batch = tem_result[9];
        tem_specialty.HighestScore = tem_result[10];
        tem_specialty.LowestScore = tem_result[11];
        tem_specialty.LowestPosition = tem_result[12];
        tem_specialty.NumberOfAdmissions = tem_result[13];
        tem_specialty.NumberOfPlans = tem_result[14];
        tem_specialty.Isit985 = tem_result[15];
        tem_specialty.Isit211 = tem_result[16];
        tem_specialty.IsitDoubleTop = tem_result[17];
        tem_specialty.Characteristic = tem_result[18];
        tem_specialty.Level = tem_result[19];
        tem_specialty.Type = tem_result[20];
        tem_specialty.ProvincialCapital = tem_result[21];
        tem_specialty.City = tem_result[22];
        tem_specialty.ProvinceWhereTheSchoolIsLocated = tem_result[23];
        Data_arr.push_back(tem_specialty);
    }

    //unsigned int num = Data_arr.size();
    rear R;
    for (int x = 0;x < Data_arr.size();x++) {
        for (int y = x + 1;y < Data_arr.size();y++) {
            //std::string tem_value;
            auto tem_value = find(College_arr.begin(), College_arr.end(), Data_arr[x].College);
            
            if (tem_value != College_arr.end()) {
                DoesItExist = true;
            }
            else
            {
                DoesItExist = false;
            }
            //如果第一个专业不等于第二个专业，在major_arr里Data_arr[x].Major并没有被添加进去
            if (Data_arr[x].College != Data_arr[y].College && DoesItExist == false) {
                College_arr.push_back(Data_arr[x].College);
                R.College = Data_arr[x].College;
                R.Isit985 = Data_arr[x].Isit985;
                R.Isit211 = Data_arr[x].Isit211;
                R.IsitDoubleTop = Data_arr[x].IsitDoubleTop;
                R.City = Data_arr[x].City;
                R.Province = Data_arr[x].ProvinceWhereTheSchoolIsLocated;
                R.Characteristic = Data_arr[x].Characteristic;
                rear_arr.push_back(R);
            }

        }
    }
    file.close();
    for (int i = 0;i < rear_arr.size();i++) {
        std::cout << rear_arr[i].College << std::endl;
        std::cout << rear_arr[i].Isit211 << std::endl;
        std::cout << rear_arr[i].IsitDoubleTop<< std::endl;
    }
    readexcel();
    //std::cout << "你好" << " " << College_arr.size() << std::endl;
    for (int i = 0;i < output_arr.size();i++) {
        for (int j = 0;j < rear_arr.size();j++) {
            if (output_arr[i].College == rear_arr[j].College) {
                output_arr[i].Isit985 = rear_arr[j].Isit985;
                output_arr[i].Isit211 = rear_arr[j].Isit211;
                output_arr[i].IsitDoubleTop = rear_arr[j].IsitDoubleTop;
                output_arr[i].City = rear_arr[j].City;
                output_arr[i].Province = rear_arr[j].Province;
                output_arr[i].Characteristic = rear_arr[j].Characteristic;
            }
        }
    }

    out.open(outpath + "2021-2019理科一本院校录取位次及位次差" + ".csv", std::ios::out | std::ios::binary);
    if (out.fail()) {
        std::cerr << "fail" << std::endl;
        return;
    }
    for (int j = 0;j < output_arr.size();j++) {
        out << output_arr[j].Number << "," << output_arr[j].CollegeCode << "," << output_arr[j].College << "," << output_arr[j].Note << ","
            << output_arr[j].Pici << "," << output_arr[j].Plan2021 << "," << output_arr[j].PlanToudang << "," << output_arr[j].Weici2021 << ","
            << output_arr[j].Weici2020 << "," << output_arr[j].Weicicha << "," << output_arr[j].Weici2019 << "," << output_arr[j].Isit985 << "," 
            << output_arr[j].Isit211 << ","<< output_arr[j].IsitDoubleTop << "," << output_arr[j].City << "," << output_arr[j].Province << "," 
            << output_arr[j].Characteristic<<std::endl;
    }
    std::cout << "Open file successfully" << std::endl;
    out.close();

    
    exit(0);

}


int main()
{
    Dataset_classification Data_cla;
    Data_cla.readfile();
    //Data_cla.readexcel();
}
