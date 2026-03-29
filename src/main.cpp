#include <iostream>

int main() {
    // option 1: $1M
    // option 2: 1 cent, 2 cents, 4 cents, doubling till 30 total days
    float ending_balance_in_dollar = 1; // 1 cent

    // magic number
    for (int i = 0; i < 29; i++) {
        printf("day %d: %f\n", i, ending_balance_in_dollar);
        ending_balance_in_dollar += ending_balance_in_dollar;
    }

    // be aware of round-off error
    printf("total ending balance after 30 days: %f\n", ending_balance_in_dollar);
}
