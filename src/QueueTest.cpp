#include "QueueTest.h"
#include "Queue.h"

#include <cassert>
#include <iostream>

void QueueTest::test_size_of_new_queue_is_zero() {
    Queue<int> q(5);
    assert(q.size() == 0);
}

void QueueTest::test_size_increases_after_enqueue() {
    Queue<int> q(5);

    q.enqueue(10);
    assert(q.size() == 1);

    q.enqueue(20);
    assert(q.size() == 2);

    q.enqueue(30);
    assert(q.size() == 3);
}

void QueueTest::test_size_decreases_after_dequeue() {
    Queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    assert(q.size() == 3);

    int value;

    q.dequeue(value);
    assert(q.size() == 2);

    q.dequeue(value);
    assert(q.size() == 1);

    q.dequeue(value);
    assert(q.size() == 0);
}

void QueueTest::test_size_after_wraparound() {
    Queue<int> q(5);

    // Fill partially
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    assert(q.size() == 3);

    int value;

    // Remove some (move end forward)
    q.dequeue(value);
    q.dequeue(value);
    assert(q.size() == 1);

    // Add more (force wrap-around)
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    assert(q.size() == 4);
}

void QueueTest::run_all() {
    test_size_of_new_queue_is_zero();
    test_size_increases_after_enqueue();
    test_size_decreases_after_dequeue();
    test_size_after_wraparound();

    std::cout << "All Queue tests passed." << std::endl;
}

void QueueTest::test_size_wraparound_front_less_than_end() {
    Queue<int> q(5);

    // Step 1: fill partially
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    // front = 3, end = 0

    int value;

    // Step 2: remove two elements
    q.dequeue(value);
    q.dequeue(value);
    // front = 3, end = 2

    // Step 3: enqueue more to wrap around
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    // front wraps: front = (3+3)%5 = 1
    // now front = 1, end = 2  → front < end

    // Expected size = 4 elements: [3,4,5,6]
    assert(q.size() == 4);
}
