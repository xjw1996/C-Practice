#include <iostream>
#include <string>

int main() {
    std::string str = "(招英语考生)(要求英语成绩不低于英语科目总分的70%)";

    int engineerPos = str.find("英语");

   /* std::cout << "China is in the" << engineerPos << "th position"<<std::endl;

    int programmerPos = str.find("sou");*/

    if (engineerPos == std::string::npos) {
        std::cout << "The word was not found" << std::endl;
    }
    else {
        std::cout << "The letter is in the" << engineerPos << "th position";
    }

    return 0;
}
