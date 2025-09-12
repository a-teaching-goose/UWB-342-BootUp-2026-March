## In-lecture demo and exercise

### Exercise A: "It's not going anywhere"

You are given two choices:

- Take $1,000,000 today, no conditions.
- Take $0.01 today (yes one cent that is), but it will grow every day for 30 days by a fixed percentage rate.

Every day, your money doubles. For example, one day 1, your have 1 cent. On day 2, you have 2 cent. On day 3, you have 4 cent.

Before writing any code, answer this:

Which option would you choose — the guaranteed $1,000,000, or the 30-day compounding penny?

Now write a program that simulates the second option.

```c++
#include <iostream>

int main() {
    /*
     * For 30 days.
     * Starting from 1 cent.
     * Double the money from the day before.
     * How much end up till end of 30 days?
     */

    const float start_in_dollar = 0.01; // 1 cent
    float start_rate_in_percentage = 100;
    int days = 30;
    const float one_million = 1000000.0;

    for (int rate = start_rate_in_percentage; rate <= 100; rate += 1) {
        float ending_balance = start_in_dollar;
        for (int day = 1; day < days; ++day) {
            ending_balance += (float) rate / 100.0f * ending_balance;
        }
        if (ending_balance > one_million) {
            std::cout << "rate " << rate << " beats lump sump with ending balance " << ending_balance / one_million <<
                    " million!" << std::endl;
        }
    }
}
```

### In-class Exercise B: "First come first serve"

A queue is a data structure that features First In First Out behavior. Seeing the long TSA lines at airports? Those are FIFO.

<img width="40%" height="2160" alt="image" src="https://github.com/user-attachments/assets/85efc648-4222-4f6d-b10c-b197ca57678e" />

A queue is usually used to synchronize different components in a system that run at different speed. 

  - Example 1: Clutch in a car

<img width="40%" height="559" alt="image" src="https://github.com/user-attachments/assets/b1c9ba94-1335-4be5-af9b-0b0aebe12cd1" />

  - Example 2: Queue in Apexiel for video processing

<img width="40%" height="559" alt="image" src="https://github.com/user-attachments/assets/a74c01c8-ab0d-496a-9ab7-d1cdbdf41a4d" />

TODO: 
1. Create a Queue to allow processing data FIFO.
2. When queue gets long, it could indicate problem (e.g., worker process has failed). How to use to trigger alarm in this situation?
3. When there's multiple workers fetching items from the queue in paralle, how to guarentee FIFO?
4. How to maximize the speed of queue without it being the bottleneck?
5. When FIFO is not strictly guarenteed, does the trigger method in 2 still work?

### After-class Exercise: "Prime Factor"

1. Given a number, determine whether it is a prime number.
2. Given the product of two prime numbers as int, find out the two prime numbers. For example, give 35, the result is 5 and 7.
3. Increate the number size using *long*, and then *long long*. See the running time increase.
4. Increase the number to very large (boost::multiprecision::cpp_int), and see the running time explode.
5. Explore how this can be used for public key encryption.

```c++
#include <iostream>
#include <chrono>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

// One pair type for both sizes
template<typename T>
struct PrimePairT {
    T p;
    T q;
};

// One factoring algorithm for both sizes
template<typename T>
void find_two_primes(const T &product) {
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
    T iterations = 0;

    for (T i = 2; i <= product / i; ++i) {
        ++iterations;

        if (product % i == 0) {
            auto end = high_resolution_clock::now();
            auto ms = duration_cast<milliseconds>(end - start).count();

            std::cout << "prime 1: " << i << "\n";
            std::cout << "prime 2: " << product / i << "\n";
            std::cout << "iterations: " << iterations << "\n";
            std::cout << "time: " << ms << " ms\n";
            return;
        }
    }

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start).count();

    std::cout << "no prime pair found\n";
    std::cout << "iterations: " << iterations << "\n";
    std::cout << "time: " << ms << " ms\n";
}

int main() {
    // Crackable numbers (long long)
    PrimePairT<long long> ll_cases[] = {
        {10007, 10009},
        {1000003, 1000033},
        {10000019, 10000079},
        {100000007, 100000037},
        {1000000007LL, 1000000009LL}
    };

    std::cout << "===== long long =====\n";
    for (auto &t: ll_cases) {
        long long n = t.p * t.q;
        std::cout << "\nFactoring n = " << n << "\n";
        find_two_primes(n);
    }

    // RSA-scale numbers (cpp_int)
    PrimePairT<cpp_int> big_cases[] = {
        {(cpp_int(1) << 17) - 1, (cpp_int(1) << 19) - 1},
        {(cpp_int(1) << 31) - 1, (cpp_int(1) << 61) - 1},
        {(cpp_int(1) << 61) - 1, (cpp_int(1) << 89) - 1},
        {(cpp_int(1) << 61) - 1, (cpp_int(1) << 127) - 1}
    };

    std::cout << "\n===== cpp_int =====\n";
    for (auto &t: big_cases) {
        cpp_int n = t.p * t.q;
        std::cout << "\nFactoring n (bits=" << msb(n) + 1 << ")\n";
        find_two_primes(n);
    }
}
```

#### How Prime Numbers Are Used for Encryption

Imagine we choose two small prime numbers, p = 13 and q = 7. We multiply them to get n = 13 × 7 = 91. We publish n for everyone to see, but we keep p and q secret. Now suppose someone wants to send us a secret number m, say m = 20. Using our public key (which includes n), they transform the message using a mathematical formula based on modular arithmetic, turning 20 into a scrambled number c. Anyone can do this because n is public. But to turn c back into 20, you need a special number d that depends on φ(n) = (13 − 1)(7 − 1) = 12 × 6 = 72, and you can only compute φ(n) if you know p and q. An attacker who only sees n = 91 would have to factor it into 13 and 7 to get φ(n), which is easy here but becomes impossible when p and q are hundreds of digits long. That’s how multiplying two primes creates a public lock that only the person who knows the primes can unlock.

