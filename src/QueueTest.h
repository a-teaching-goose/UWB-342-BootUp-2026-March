#pragma once
class QueueTest {
public:
    static void test_size_of_new_queue_is_zero();

    static void test_size_increases_after_enqueue();

    static void test_size_decreases_after_dequeue();

    static void test_size_after_wraparound();

    static void test_size_wraparound_front_less_than_end();

    // TODO: add more tests for enqueue, dequeue, and is_empty()

    static void run_all();
};
