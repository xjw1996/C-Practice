
#include <iostream>


struct addr_entity {
    int x;
};

class Entity {
    int y;
public:
    Entity(int tem = 7)
        :y(tem){  std::cout << "Destructor is called"<<std::endl;}
    void alloca_struct();
    void alloca_array();
    void alloca_class();
    int get_value() { return y; }
};

void Entity::alloca_array() {
    std::cout << "print out alloca_array";
    int* array_inty = new int[4];
    for (int i = 0;i < 4;i++) {
        array_inty[i] = 7;
        std::cout << array_inty[i];
    }
    std::cout << std::endl;
}

void Entity::alloca_struct() {
    std::cout << "print out alloca_struct";
    addr_entity* arr_struct = new addr_entity[4];
    for (int i = 0;i < 4;i++) {
        arr_struct[i].x = 7;
        std::cout << arr_struct[i].x;
    }
    std::cout << std::endl;
}

void Entity::alloca_class() {
    std::cout << "print out alloca_class";
    Entity* arr_class = new Entity[4];
    for (int i = 0;i < 4;i++) {
        std::cout << arr_class[i].y;
    }
    std::cout <<std::endl;
}
int main()
{
    Entity E;
    E.alloca_array();
    E.alloca_struct();
    E.alloca_class();
}

