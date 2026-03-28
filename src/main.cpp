#include <iostream>

class Queue {
private:
    uint capacity;
    uint size;
    int *data;

    uint front, end;

public:
    Queue(const uint capacity) : size(0), front(0), end(0) {
        this->capacity = capacity;
        this->data = new int[capacity];
    }

    // end....front
    bool enqueue(const int value) {
        if (size == capacity) {
            std::cout << "Queue is full" << std::endl;
            return false;
        }
        data[front] = value;
        front = (front + 1) % capacity;
        size++;
        return true;
    }

    bool dequeue(int &value) {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return false;
        }

        value = data[end];
        end = (end + 1) % capacity;
        size--;
        return true;
    }

    bool isEmpty() const {
        return size == 0;
    }

    ~Queue() {
        delete[] data;
    }
};

int main() {
    Queue queue(5);
    for (int i = 0; i < 5; ++i) {
        queue.enqueue(i);
    }

    for (int i = 0; i < 10; ++i) {
        int val;
        bool success = queue.dequeue(val);
        if (!success) {
            std::cout << "Dequeue failed" << std::endl;
            break;
        }
        std::cout << val << std::endl;
    }
}
