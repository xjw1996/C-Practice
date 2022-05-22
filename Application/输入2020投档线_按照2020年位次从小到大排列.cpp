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

struct judge_list {
    std::string College_2020;
    bool IfCollegeIn2021;
};

struct datalist2020
{
    std::string Province_2020;
    std::string year_2020;
    std::string subject_2020;
    std::string Pici_2020;
    std::string College_2020;
    std::string major_2020;
    std::string AdmissionNumber_2020;
    std::string Toudangxian_2020;
    std::string Weici_2020;
};

class Dataset_classification {
public:
    void readfile();
    void read2020Excel();
   /* Dataset_classification(bool tf = false)
        :DoesIt2020Exist(tf)
    {}*/
    //void classification();
    std::vector<std::string> split(std::string str, char del);
    std::vector<SpecialtyList> BubbleSort(std::vector<SpecialtyList> A, int n);
private:
    std::ofstream out;
    std::string path = "D:\\xue_workspace\\DataOfUniversityScore\\理科二批.csv";
    std::string path_2020 = "C:\\Users\\jinue\\Desktop\\数据\\2020数据\\2020\\2020理科二本.csv";
    std::string outpath = "D:\\xue_workspace\\DataOfUniversityScore\\ExcelPythonTest\\20220204\\理科二本\\";
    std::string variable_path;
    std::vector<SpecialtyList> Data_arr;
    std::vector<datalist2020> Data_2020;
    std::vector<judge_list> judge_vector;
    std::vector<std::string> Major_arr;
    std::vector<std::string> collge2020_arr;
    bool DoesItExist;
    bool DoesIt2020Exist;
    //模糊搜寻
    bool Search_MajorNote;
    std::vector<std::vector<SpecialtyList>> data_2Darr;
    std::vector<std::vector<datalist2020>> data_2Darr_;
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

void Dataset_classification::read2020Excel() {
    char del = ',';
    std::ifstream file2;
    file2.open(path_2020);
    if (!file2.is_open())
    {
        std::cout << "Error opening file";
        exit(1);
    }

    datalist2020 Data;
    std::string LineOfData;
    while (std::getline(file2, LineOfData)) {
        std::string str = UTF8ToGB(LineOfData.c_str()).c_str();
        std::vector<std::string> tem_result = split(str, del);
        Data.Province_2020 = tem_result[0];
        Data.year_2020 = tem_result[1];
        Data.subject_2020 = tem_result[2];
        Data.Pici_2020 = tem_result[3];
        Data.College_2020 = tem_result[4];
        Data.major_2020 = tem_result[5];
        Data.AdmissionNumber_2020 = tem_result[6];
        Data.Toudangxian_2020 = tem_result[7];
        Data.Weici_2020 = tem_result[8];
        this->Data_2020.push_back(Data);
    }

    for (int x = 0;x < this->Data_2020.size();x++) {
        for (int y = x + 1;y < this->Data_2020.size();y++) {
            //std::string tem_value;
            auto tem_value = find(this->collge2020_arr.begin(), this->collge2020_arr.end(), this->Data_2020[x].College_2020);
            if (tem_value != collge2020_arr.end()) {
                this->DoesIt2020Exist = true;
            }
            else
            {
                this->DoesIt2020Exist = false;
            }
            //如果第一个专业不等于第二个专业，在major_arr里Data_arr[x].Major并没有被添加进去
            if (this->Data_2020[x].College_2020 != this->Data_2020[y].College_2020 && this->DoesIt2020Exist == false) {
                this->collge2020_arr.push_back(this->Data_2020[x].College_2020);
            }
        }
    }
  
    /*for (std::vector<std::string>::iterator p = this->collge2020_arr.begin();p != this->collge2020_arr.end();p++) {
        std::cout << &*p << std::endl;
        std::cout << "打印" << std::endl;
    }*/
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
        this->Data_arr.push_back(tem_specialty);
    }

    //unsigned int num = Data_arr.size();
    for (int x = 1;x < Data_arr.size();x++) {
        for (int y = x + 1;y < Data_arr.size();y++) {
            //std::string tem_value;
            auto tem_value = find(Major_arr.begin(), Major_arr.end(), Data_arr[x].College);
            if (tem_value != Major_arr.end()) {
                DoesItExist = true;
            }
            else
            {
                DoesItExist = false;
            }
            //如果第一个专业不等于第二个专业，在major_arr里Data_arr[x].Major并没有被添加进去
            if (Data_arr[x].College != Data_arr[y].College && DoesItExist == false) {
                Major_arr.push_back(Data_arr[x].College);
            }
        }
    }

    std::cout << "你好" << " " << Major_arr.size() << std::endl;
    for (int i = 0;i < Major_arr.size();i++) {
        std::cout << Major_arr[i] << std::endl;
    }
    std::cout << "---------------------------------------------------------------------" << std::endl;
    data_2Darr.resize(Major_arr.size());
    read2020Excel();
    for (int i = 0;i < Major_arr.size(); i++) {
        variable_path = Major_arr[i];
        out.open(outpath + variable_path + "理科二本2021以及2020年在吉专业分数及位次" + ".csv", std::ios::out | std::ios::binary);
        if (out.fail()) {
            std::cerr << "fail" << std::endl;
            return;
        }

        for (int j = 0;j < Data_arr.size();j++) {
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
            if (Major_arr[i] == Data_arr[j].College) {
                data_2Darr[i].push_back(tem_l);
            }
        }
        int arr_length;
        arr_length = data_2Darr[i].size();
        data_2Darr[i] = BubbleSort(data_2Darr[i], arr_length);

        for (int j = 0;j < arr_length;j++) {
            if (j == 0) {
                out << Data_arr[j].CollegeCode << "," << Data_arr[j].College << "," << Data_arr[j].Note << Data_arr[j].MajorCode << "," << Data_arr[j].Major << "," << Data_arr[j].MajorNote << "," << Data_arr[j].LowestScore << "," << Data_arr[j].LowestPosition << "," << Data_arr[j].NumberOfAdmissions << "," << Data_arr[j].Characteristic << "," << Data_arr[j].Level << "," << Data_arr[j].Type << std::endl;
            }
            out << data_2Darr[i][j].CollegeCode << "," << data_2Darr[i][j].College << "," << data_2Darr[i][j].Note << data_2Darr[i][j].MajorCode << "," << data_2Darr[i][j].Major << "," << data_2Darr[i][j].MajorNote << "," << data_2Darr[i][j].LowestScore << "," << data_2Darr[i][j].LowestPosition << "," << data_2Darr[i][j].NumberOfAdmissions << "," << data_2Darr[i][j].Characteristic << "," << data_2Darr[i][j].Level << "," << data_2Darr[i][j].Type << std::endl;
        }
        
        bool TF_whether = false;
        for (std::vector<std::string>::iterator p = this->collge2020_arr.begin();p != this->collge2020_arr.end();p++) {
            if (Major_arr[i] == *p) {
                /*std::cout << Major_arr[i]<<"找到了" << std::endl;*/
                TF_whether = true;
            }
            //std::cout << *p << std::endl;
        }
        if (TF_whether == true) {
            out << "2020" << "," << TF_whether << std::endl;
        }
        else
        {
            out << "2020" << "," << TF_whether << std::endl;
        }
        //this->DoesIt2020Exist = false;
        for (int j = 0;j < this->Data_2020.size();j++) {
            datalist2020 tem_data;
            if (this->Major_arr[i] == this->Data_2020[j].College_2020) {
                out << this->Data_2020[j].Province_2020 << "," << this->Data_2020[j].year_2020 << "," << this->Data_2020[j].subject_2020 << ","
                    << this->Data_2020[j].Pici_2020 << "," << this->Data_2020[j].College_2020 << "," << this->Data_2020[j].major_2020 << ","
                    << this->Data_2020[j].AdmissionNumber_2020 << "," << this->Data_2020[j].Toudangxian_2020 << "," << this->Data_2020[j].Weici_2020 << std::endl;
            }
        }
        std::cout << "Open file successfully" << std::endl;
        out.close();
    }

    exit(0);

}


int main()
{
    Dataset_classification Data_cla;
    Data_cla.readfile();
    //Data_cla.read2020Excel();
}
