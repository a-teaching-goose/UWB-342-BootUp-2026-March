#include "Queue.h"
#include "QueueTest.h"


typedef Queue<std::string> MessageQueue;

int main() {
    /*
     * First, test the queue
     */
    QueueTest::run_all();

    /*
     * Use the queue once tests have passed
     */
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
