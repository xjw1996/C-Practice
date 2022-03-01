
#include <iostream>
#include <string>
#include <vector>

struct person
{
    std::string name;
    float height;
    float weight;
    std::string gender;
}PersonArr[] = {
    {"Abel", 185.5, 79.5, "male"},
    {"Gina", 172.4, 55.4, "female"},
    {"Fyodor", 157.5, 49.8, "male"},
    {"Goebbels", 165.0, 65.0, "male"},
    {"KUARO", 150.0, 80.0, "non"},
};

class Serarch_MaxHeight
{
    //std::vector<person*> arr;
    struct person* PtrMaxHeight = PersonArr;
public:
    void MaxHeight();
};

void Serarch_MaxHeight::MaxHeight() 
{
    for (int i = 0;i < 4;i++)
        if (PersonArr[i].height > PtrMaxHeight->height)
            PtrMaxHeight = PersonArr+i;

    std::cout << PtrMaxHeight->name << std::endl;
    std::cout << PtrMaxHeight->height << std::endl;
    std::cout << PtrMaxHeight->weight << std::endl;
    std::cout << PtrMaxHeight->gender << std::endl;
}


int main()
{
    Serarch_MaxHeight SH;
    SH.MaxHeight();
}

