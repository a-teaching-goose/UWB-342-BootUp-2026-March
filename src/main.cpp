#include <iostream>

class Food {
public:
    std::string name;
    int days_to_expire;

    // constructor
    Food(std::string name, int days_to_expire) {
        this->name = name;
        this->days_to_expire = days_to_expire;
    }

    Food() {
        name = "";
        days_to_expire = 0;
    }

    // destructor
    ~Food() {
    }

    std::string to_string() {
        return "Name:" + name + "\nDays to expire:" + std::to_string(days_to_expire);
    }
};


int main() {
    // reference
    int num = 5;

    int &ref = num;
    ref = 10;

    std::cout << &num << std::endl;
    std::cout << &ref << std::endl;
}

