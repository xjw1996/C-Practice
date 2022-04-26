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

struct SpecialtyList {
    std::string number;
    std::string CollegeCode;
    std::string College;
    std::string Note;
    std::string Pici;
    std::string Toudang;
    std::string plan;
    std::string weici1;
    std::string weici2;
    std::string weicicha;
    std::string weici3;
};

struct List1 {
    std::string college;
    std::string weici;
};

struct List2 {
    std::string college;
    std::string weici;
};

class Dataset_classification {
public:
    void readfile();
    //void classification();
    std::vector<std::string> split(std::string str, char del);
    std::vector<SpecialtyList> BubbleSort(std::vector<SpecialtyList> A, int n);
private:

    std::ofstream out;
    std::string path2021 = "C:\\Users\\jinue\\Desktop\\数据\\文科\\一本\\2021.csv";
    std::string path2020 = "C:\\Users\\jinue\\Desktop\\数据\\文科\\一本\\2020.csv";
    std::string path2019 = "C:\\Users\\jinue\\Desktop\\数据\\文科\\一本\\2019.csv";
    //std::string path = "D:\\program\\data.csv";
    std::string outpath = "C:\\Users\\jinue\\Desktop\\数据\\文科\\一本\\";
    std::string variable_path;
    std::vector<SpecialtyList> Data_arr;
    std::vector<std::string> CollegeRepaet_arr;
    std::vector<int> tem_number_repeat;
    std::vector<List1> collge_arr1;
    std::vector<List2> collge_arr2;
    bool DoesItExist;
    //模糊搜寻
    bool Search_MajorNote;
    //std::map<std::string, std::vector<std::string>>maptest;
    std::vector<std::vector<SpecialtyList>> data_2Darr;
};

std::vector<std::string> Dataset_classification::split(std::string str, char del) {
    unsigned int first = 0;
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
            if (A[j].Toudang < A[j + 1].Toudang) {
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
    char del = ',';
    std::ifstream file;
    file.open(path2021);
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
        
        tem_specialty.number = tem_result[0];
        tem_specialty.CollegeCode = tem_result[1];
        tem_specialty.College = tem_result[2];
        tem_specialty.Note = tem_result[3];
        tem_specialty.Pici = tem_result[4];
        tem_specialty.Toudang = tem_result[5];
        tem_specialty.weici1 = tem_result[7];
        tem_specialty.plan = tem_result[6];
        tem_specialty.weici2 = " ";
        tem_specialty.weicicha = " ";
        tem_specialty.weici3 = " ";
        Data_arr.push_back(tem_specialty);
    }
    file.close();
    /*for (int i = 0;i < Data_arr.size();i++) {
        std::cout << Data_arr[i].Note << std::endl;
    }*/
    std::ifstream file2;
    file2.open(path2020);
    if (!file2.is_open())
    {
        std::cout << "Error opening file";
        exit(1);
    }

    List1 tem_2;
    std::string LineOfData2;

    while (std::getline(file2, LineOfData2))
    {
        std::string str = UTF8ToGB(LineOfData2.c_str()).c_str();
        std::vector<std::string> tem_result2 = split(str, del);
        
        tem_2.college = tem_result2[0];
        tem_2.weici = tem_result2[1];
        collge_arr1.push_back(tem_2);
    }
    file2.close();

    

    std::ifstream file3;
    file3.open(path2019);
    if (!file3.is_open())
    {
        std::cout << "Error opening file";
        exit(1);
    }

    List2 tem_3;
    std::string LineOfData3;

    while (std::getline(file3, LineOfData3))
    {
        std::string str = UTF8ToGB(LineOfData3.c_str()).c_str();
        std::vector<std::string> tem_result3 = split(str, del);
       /* std::cout << tem_result3[0] << std::endl;
        std::cout << tem_result3[1] << std::endl;*/
        tem_3.college = tem_result3[0];
        tem_3.weici = tem_result3[1];
        collge_arr2.push_back(tem_3);
    }
    file3.close();


    for (unsigned int i = 0;i < Data_arr.size();i++) {
        for (unsigned int j = 0;j < collge_arr2.size();j++) {
            if (Data_arr[i].College == collge_arr2[j].college) {
                Data_arr[i].weici3 = collge_arr2[j].weici;
            }
        }

    }
   
  
   // for (int i = 0;i < collge_arr1.size();i++) {
   //    std::cout << collge_arr1[i].college << std::endl;
   //}
    for (unsigned int i = 0;i < Data_arr.size();i++) {
        for (int unsigned j = 0;j < collge_arr1.size();j++) {
            if (Data_arr[i].College == collge_arr1[j].college) {
                Data_arr[i].weici2 = collge_arr1[j].weici;
                int tem_num1, tem_num2, tem_num3;
                tem_num1 = std::atoi(Data_arr[i].weici1.c_str());
                tem_num2 = std::atoi(Data_arr[i].weici2.c_str());
                tem_num3 = tem_num1 - tem_num2;
                std::string temstr = std::to_string(tem_num3);
                Data_arr[i].weicicha = temstr;
            }
        }

    }



   /* for (unsigned int i = 0;i < collge_arr1.size();i++) {
        std::cout << collge_arr1[i].college << std::endl;
        std::cout << collge_arr1[i].weici << std::endl;
    }*/

    for (int x = 0;x < Data_arr.size();x++) {
        for (int y = x + 1;y < Data_arr.size();y++) {
            //std::string tem_value;
            auto tem_value = find(CollegeRepaet_arr.begin(), CollegeRepaet_arr.end(), Data_arr[x].College);
            if (tem_value != CollegeRepaet_arr.end()) {
                DoesItExist = true;
            }
            else
            {
                DoesItExist = false;
            }
            //如果第一个专业不等于第二个专业，在major_arr里Data_arr[x].Major并没有被添加进去
            if (Data_arr[x].College == Data_arr[y].College && DoesItExist == false) {
                CollegeRepaet_arr.push_back(Data_arr[x].College);
            }
            //int Serach_ = str.find(Data_arr[x].Major);

        }
    }
    for (unsigned int i = 0;i < CollegeRepaet_arr.size();i++) {
        std::cout << CollegeRepaet_arr[i]<< std::endl;
    }
    

    for (int i = 0;i < CollegeRepaet_arr.size();i++) {
        for (int j = 0;j < Data_arr.size();j++) {
            if (CollegeRepaet_arr[i] == Data_arr[j].College) {
                Data_arr[j].weici2 = " ";
                Data_arr[j].weicicha = " ";
                Data_arr[j].weici3 = " ";
            }
        }          
    }



 

    /*for (int i = 0;i < CollegeRepaet_arr.size();i++) {
        for (int j = 0;j < Data_arr.size();j++) {
            if (CollegeRepaet_arr[i] == Data_arr[j].College) {
                tem_number_repeat.push_back(j);
            }
        }
    }
    
    

    

    for (int i = 0;i < tem_number_repeat.size();i++) {
        Data_arr.erase(Data_arr.begin() + (tem_number_repeat[i] + 1));
    }*/
   


    data_2Darr.resize(Data_arr.size());

    for(unsigned int i=0;i< Data_arr.size();i++){
        out.open(outpath + "文科一本.csv", std::ios::out | std::ios::binary);
        if (out.fail()) {
            std::cerr << "fail" << std::endl;
            return;
        }

        for (unsigned int j = 0;j < Data_arr.size();j++) {
            SpecialtyList tem_l;
            tem_l.number = Data_arr[j].number;
            tem_l.CollegeCode = Data_arr[j].CollegeCode;
            tem_l.College = Data_arr[j].College;
            tem_l.Note = Data_arr[j].Note;
            tem_l.Pici = Data_arr[j].Pici;
            tem_l.Toudang = Data_arr[j].Toudang;
            tem_l.plan = Data_arr[j].plan;
            tem_l.weici1 = Data_arr[j].weici1;
            tem_l.weici2 = Data_arr[j].weici2;
            tem_l.weicicha = Data_arr[j].weicicha;
            tem_l.weici3 = Data_arr[j].weici3;
            data_2Darr[i].push_back(tem_l);
        }

        
        
     

        /*for (const auto& x : v) {
            std::cout << x << std::endl;
        }*/

        int arr_length;
        arr_length = data_2Darr[i].size();
        data_2Darr[i] = BubbleSort(data_2Darr[i], arr_length);

        /*for (int arr = 0;arr < data_2Darr[i].size();arr++) {
            std::cout << data_2Darr[i][arr].LowestScore << std::endl;
            std::cout << data_2Darr[i][arr].Major<< std::endl;
        }*/

        //std::cout << "--------------------------------------------------------------------" << std::endl;
        for (int j = 0;j < arr_length;j++) {
            
            out << data_2Darr[i][j].number << "," << data_2Darr[i][j].CollegeCode << "," << data_2Darr[i][j].College <<"," << data_2Darr[i][j].Note << "," << data_2Darr[i][j].Pici << "," << data_2Darr[i][j].Toudang << "," << data_2Darr[i][j].plan << "," << data_2Darr[i][j].weici1 << "," << data_2Darr[i][j].weici2 << "," << data_2Darr[i][j].weicicha << "," << data_2Darr[i][j].weici3 <<  std::endl;


        }
        std::cout << "Open file successfully" << std::endl;
        out.close();
    

        exit(0);
    }
}


int main()
{
    Dataset_classification Data_cla;
    Data_cla.readfile();
}
