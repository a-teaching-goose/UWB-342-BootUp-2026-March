#include <iostream>

template<typename T>
class Queue {
private:
    uint capacity;
    uint size;
    T *data;

    uint front, end;

public:
    Queue(const uint capacity) : size(0), front(0), end(0) {
        this->capacity = capacity;
        this->data = new T[capacity];
    }

    // end....front
    bool enqueue(const T value) {
        if (size == capacity) {
            std::cout << "Queue is full" << std::endl;
            return false;
        }
        data[front] = value;
        front = (front + 1) % capacity;
        size++;
        return true;
    }

    bool dequeue(T &value) {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return false;
        }

        value = data[end];
        end = (end + 1) % capacity;
        size--;
        return true;
    }

    [[nodiscard]] bool isEmpty() const {
        return size == 0;
    }

    ~Queue() {
        delete[] data;
    }

    std::string to_string() {
        std::string result;
        for (uint i = 0; i < size; ++i) {
            result += "data[" + std::to_string(i) + "]: " + data[front + i] + "\n";
        }
        return result;
    }
};

typedef Queue<std::string> MessageQueue;

int main() {
    Queue<int> queue(5);
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

    MessageQueue messageQueue(10);
    for (int i = 0; i < 10; ++i) {
        messageQueue.enqueue("Hello world: " + std::to_string(i));
    }

    std::cout << messageQueue.to_string() << std::endl;
}
