#include <iostream>
int main() {
    int my_data = 50;

    std::string messages[5];

    for (int i=0; i<my_data; i++) {
        messages[i] = "Hello " + std::to_string(i);
    }

    int i = 0;
    for (;;) {
        if (i==my_data) {
            break;
        }
        if (i%2==0) {
            std::cout << messages[i] << std::endl;
        }
        i++;
    }
}