#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cmath>

struct CityRecord{
    std::string name;
    int Population;
}city_record[]={
    {"changchun",700},
    {"shenyang",1000},
    {"shuanghai",2000},
    {"chongqing",1500},
    {"guangzhong",1300},
    {"changsha",1200},
    {"qingdao",1550},
};

class test_map{
    public:
        void run();
        std::map<std::string,std::vector<CityRecord>> BubbleSort(std::map<std::string,std::vector<CityRecord>> x,std::vector<CityRecord> y,int n);
    private:
        std::map<std::string,std::vector<CityRecord>> Map_test;
        std::vector<CityRecord> CR;
};

std::map<std::string,std::vector<CityRecord>> test_map::BubbleSort(std::map<std::string,std::vector<CityRecord>> x,std::vector<CityRecord> y,int n){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(y[j].Population>y[j+1].Population){
                std::swap(x.at(y[j].name),x.at(y[j+1].name));
            }
        }
    }
    return x;
}

void test_map::run(){
    CityRecord tem_record;
    for(int i=0;i<7;i++){
        //emplace_back 在linux下编译不能通过
        CR.push_back(city_record[i]);
    }
    
    for(int j=0;j<7;j++){
        Map_test.insert(std::make_pair(CR[j].name,CR[j].Population));
    }
    // //std::cout<<"size is "<<Map_test.size()<<std::endl;
    // int num=Map_test.size();
    // Map_test=BubbleSort(Map_test,CR,num);

    // // auto begin = Map_test.begin(), end = Map_test.end();
    // // for (auto iter = begin; iter != end; iter++) {
    // //     // first: key, second: value
    // //     std::cout << "key = " << iter->first << " ";
    // //     std::cout << "value = " << iter->second << std::endl;
    // // }
    // std::vector<CityRecord> tem_;
    // tem_=Map_test.at(0);
    std::cout<<"value is "<<Map_test.at(0).name<<std::endl;

}

int main(int argc, char *argv[]){
    test_map tm;
    tm.run();
}
