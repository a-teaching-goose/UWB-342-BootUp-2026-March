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
    Food foods[5] = {
        Food("cake", 2),
        Food("apple", 30),
        Food("banana", 15),
        Food("coffee", 90),
        Food("fish", 3),
    };

    Food food;
    food = foods[0];
    int lowest_expire_in_days = foods[0].days_to_expire;
    for (int i = 0; i < 5; ++i) {
        if (foods[i].days_to_expire < lowest_expire_in_days) {
            lowest_expire_in_days = foods[i].days_to_expire;
        }
    }

    std::cout << "I should eat " << food.name << " first!" << std::endl;
}
