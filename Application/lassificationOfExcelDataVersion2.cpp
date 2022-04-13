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
    //void classification();
    std::vector<std::string> split(std::string str, char del);
    std::vector<SpecialtyList> BubbleSort(std::vector<SpecialtyList> A, int n);
private:

    std::ofstream out;
    std::string path = "D:\\xue_workspace\\DataOfUniversityScore\\test - 副本 - 副本.csv";
    //std::string path = "D:\\program\\data.csv";
    std::string outpath = "D:\\xue_workspace\\DataOfUniversityScore\\2021年吉林文科本科一批院校专业分数线\\";
    std::string variable_path;
    std::vector<SpecialtyList> Data_arr;
    std::vector<std::string> Major_arr;
    bool DoesItExist;
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

void Dataset_classification::readfile() {
    std::string  College, Note, Provi, Maj, MajNote, AorS, Bat, if985, if211, ifToptwo, Property, Lev, Tye, Pcap, Ct, Ploca;
    int CCode, y, MCode, max, min, minposition, NumofAdmission, NumofPlan;
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
        //sscanf_s(str, "%d,%s,%s,%s,%d,%d,%s,%s,%s,%s,%d,%d,%d,%d,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s", &CCode, &College, &Note, &Provi, &y, &MCode, &Maj, &MajNote, &AorS, &Bat, &max, &min,&minposition,&NumofAdmission, &NumofPlan, if985, if211, ifToptwo, Property, Lev, Tye, Pcap, Ct, Ploca);
        //sscanf_s(str.data(), "%s,%s", &Note, &College);
        //std::string Note = UTF8ToGB(Note.c_str()).c_str();
        //std::cout << Note << std::endl;
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
        //capacity() 和 size()输出的结果是不一样的
        //std::cout << "tem_result.capacity()" << tem_result.capacity() << std::endl;
        //for (const auto& str_ : split(str, del)) {
        //    std::cout << str_ << std::endl;
        //    //查看变量类型typeid(str_).name()
        //}
        /*std::cout << Note << " " << College << std::endl;
        std::cout << str.data() << std::endl;*/
        /*sscanf_s(str.data(), "%s,%s", &Note, &College);*/
    }

    //unsigned int num = Data_arr.size();
    for (int x = 1;x < Data_arr.size();x++) {
        for (int y = x + 1;y < Data_arr.size();y++) {
            //std::string tem_value;
            auto tem_value = find(Major_arr.begin(), Major_arr.end(), Data_arr[x].Major);
            if (tem_value != Major_arr.end()) {
                DoesItExist = false;
            }
            else
            {
                DoesItExist = true;
            }

            if (Data_arr[x].Major != Data_arr[y].Major && DoesItExist == true) {
                Major_arr.push_back(Data_arr[x].Major);
            }
        }
    }
    std::cout << "你好" << " " << Major_arr.size() << std::endl;
    for (int i = 0;i < Major_arr.size();i++) {
        std::cout << Major_arr[i] << std::endl;
    }

    data_2Darr.resize(Major_arr.size());
    
    for (int i = 0;i < Major_arr.size(); i++) {
        /*variable_path = Major_arr[i];
        out.open(outpath + variable_path + ".csv", std::ios::out | std::ios::binary);
        if (out.fail()) {
            std::cerr << "fail" << std::endl;
            return;
        }*/

        for (int j = 0;j < Data_arr.size();j++) {
            if (Major_arr[i] == Data_arr[j].Major) {
                SpecialtyList tem_l;
                tem_l.CollegeCode = Data_arr[j].CollegeCode;
                tem_l.College = Data_arr[j].College;
                tem_l.Note = Data_arr[j].Note;
                tem_l.Province = Data_arr[j].Province;
                tem_l.Year = Data_arr[j].Year;
                tem_l.MajorCode = Data_arr[j].MajorCode;
                tem_l.Major = Data_arr[j].Major;
                tem_l.MajorNote = Data_arr[j].MajorNote;
                tem_l.ArtsOrScience = Data_arr[j].ArtsOrScience;
                tem_l.Batch = Data_arr[j].Batch;
                tem_l.HighestScore = Data_arr[j].HighestScore;
                tem_l.LowestScore = Data_arr[j].LowestScore;
                tem_l.LowestPosition = Data_arr[j].LowestPosition;
                tem_l.NumberOfAdmissions = Data_arr[j].NumberOfAdmissions;
                tem_l.NumberOfPlans = Data_arr[j].NumberOfPlans;
                tem_l.Isit985 = Data_arr[j].Isit985;
                tem_l.Isit211 = Data_arr[j].Isit211;
                tem_l.IsitDoubleTop = Data_arr[j].IsitDoubleTop;
                tem_l.Characteristic = Data_arr[j].Characteristic;
                tem_l.Level = Data_arr[j].Level;
                tem_l.Type = Data_arr[j].Type;
                tem_l.ProvincialCapital = Data_arr[j].ProvincialCapital;
                tem_l.City = Data_arr[j].City;
                tem_l.ProvinceWhereTheSchoolIsLocated = Data_arr[j].ProvinceWhereTheSchoolIsLocated;

                data_2Darr[i].push_back(tem_l);
            } 
        }
        int arr_length;
        arr_length = data_2Darr[i].size();
        data_2Darr[i] = BubbleSort(data_2Darr[i], arr_length);

        for (int arr = 0;arr < data_2Darr[i].size();arr++) {
            std::cout << data_2Darr[i][arr].LowestScore << std::endl;
        }
        std::cout << "--------------------------------------------------------------------" << std::endl;
        //for (int j = 0;j < Data_arr.size();j++) {
        //    if (j == 0) {
        //        //std::cout << Data_arr[0].CollegeCode << std::endl;
        //        out << Data_arr[j].CollegeCode << "," << Data_arr[j].College << "," << Data_arr[j].Note << "," << Data_arr[j].Province << "," << Data_arr[j].Year << "," << Data_arr[j].MajorCode << "," << Data_arr[j].Major << "," << Data_arr[j].MajorNote << "," << Data_arr[j].ArtsOrScience << "," << Data_arr[j].Batch << "," << Data_arr[j].HighestScore << "," << Data_arr[j].LowestScore << "," << Data_arr[j].LowestPosition << "," << Data_arr[j].NumberOfAdmissions << "," << Data_arr[j].NumberOfPlans << "," << Data_arr[j].Isit985 << "," << Data_arr[j].Isit211 << "," << Data_arr[j].IsitDoubleTop << "," << Data_arr[j].Characteristic << "," << Data_arr[j].Level << "," << Data_arr[j].Type << "," << Data_arr[j].ProvincialCapital << "," << Data_arr[j].City << "," << Data_arr[j].ProvinceWhereTheSchoolIsLocated << std::endl;
        //    }

        //    if (Major_arr[i] == Data_arr[j].Major) {
        //        out << Data_arr[j].CollegeCode << "," << Data_arr[j].College << "," << Data_arr[j].Note << "," << Data_arr[j].Province << "," << Data_arr[j].Year << "," << Data_arr[j].MajorCode << "," << Data_arr[j].Major << "," << Data_arr[j].MajorNote << "," << Data_arr[j].ArtsOrScience << "," << Data_arr[j].Batch << "," << Data_arr[j].HighestScore << "," << Data_arr[j].LowestScore << "," << Data_arr[j].LowestPosition << "," << Data_arr[j].NumberOfAdmissions << "," << Data_arr[j].NumberOfPlans << "," << Data_arr[j].Isit985 << "," << Data_arr[j].Isit211 << "," << Data_arr[j].IsitDoubleTop << "," << Data_arr[j].Characteristic << "," << Data_arr[j].Level << "," << Data_arr[j].Type << "," << Data_arr[j].ProvincialCapital << "," << Data_arr[j].City << "," << Data_arr[j].ProvinceWhereTheSchoolIsLocated << std::endl;
        //    }
        //}
        /*std::cout << "Open file successfully" << std::endl;
        out.close();*/
    }

    exit(0);

}


int main()
{
    Dataset_classification Data_cla;
    Data_cla.readfile();
}
