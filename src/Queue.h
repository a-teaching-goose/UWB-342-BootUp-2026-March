#pragma once
#include <iostream>

template<typename T>
class Queue {
private:
    uint capacity;
    T *data;

    uint front, end;

public:
    Queue(const uint capacity) : front(0), end(0) {
        this->capacity = capacity;
        this->data = new T[capacity];
    }

    // end....front
    bool enqueue(const T value) {
        if (size() == capacity) {
            std::cout << "Queue is full" << std::endl;
            return false;
        }
        data[front] = value;
        front = (front + 1) % capacity;
        return true;
    }

    bool dequeue(T &value) {
        if (is_empty()) {
            std::cout << "Queue is empty" << std::endl;
            return false;
        }

        value = data[end];
        end = (end + 1) % capacity;
        return true;
    }

    [[nodiscard]] bool is_empty() const {
        return size() == 0;
    }

    ~Queue() {
        delete[] data;
    }

    std::string to_string() {
        std::string result;
        for (uint i = 0; i < size(); ++i) {
            result += "data[" + std::to_string(i) + "]: " + data[front + i] + "\n";
        }
        return result;
    }

    [[nodiscard]] uint size() const {
        if (front >= end) {
            return front - end;
        }

        return front + capacity - end;
    }
};

typedef Queue<std::string> MessageQueue;
