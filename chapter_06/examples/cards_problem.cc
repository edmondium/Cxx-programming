// In one card game, a deck of cards is shuffled and the first player is given "hand_size" cards.
// Determine the probability distribution of the sum of the numerical values in the cards in the
// hand.

#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <random>

constexpr size_t hand_size = 7; // Number of cards in a hand. A compile time constant in this program.
static_assert(hand_size > 0 && hand_size <= 52, "Hand size must be a number between 1 and 52!");
// static_assert can be used as above to ensure we do not violate assumptions made in the code by using
// unsuitable parameters. From now on, we can code assuming that hand_size is a non-zero number no larger
// than 52.

// We are going to need to store the frequencies of the obtained sums in our computer experiment in
// an array, such that H[i] will count how often we ended up with a sum of i. How large does the
// array need to be ? It's a fairly simple calculation, but not a trivial one. We could write a function
// to do it for us. By making the function a "constexpr" function, we can even make it available at
// compile time, so that fixed sized arrays of the right length can be allocated by the compiler,
// based on the results of the evaluation of a non-trivial function.
constexpr auto max_sum(size_t N)
{
    // This function calculates the maximum sum of the numbers written on a hand of N cards.
    size_t S = 0;
    // A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K : 1,2,3,4,5,6,7,8,9,10,11,12,13
    size_t largest = 13;
    while (N > 4) {
        S += 4 * largest; // there are at most 4 of each kind.
        largest -= 1; // Equivalent to largest = largest-1
        N -= 4;
    }
    if (N > 0)
        S += largest * N;
    return S;
}

auto main() -> int
{
    std::random_device seed; // Device random number generator, used here only to seed the pseudo-random engine.
    std::mt19937 engine{ seed() }; // Mersenne Twister engine, seeded with a call to the device RNG
    std::array<int, 52> deck;
    std::iota(deck.begin(), deck.end(), 1); // Fills the deck with numbers 1..52
    constexpr size_t maxsum = max_sum(hand_size); // hand_size is known at compile time. So, all parameters
    // of the constexpr function max_sum are known to the compiler. Hence, it can be evaluated by the
    // compiler and the result of the function call can be assigned to a constexpr variable.
    // Max sum is the maximum sum obtainable for a hand of cards of size hand_size

    std::array<int, maxsum + 1> frequency_of_sum{};
    // We can now use a fixed length array to measure frequencies of different results obtained in
    // our Monte Carlo experiment.

    // We want to store the frequency of a measured sum of S at frequency_of_sum[S].
    // But arrays in C, C++ etc. start at index 0, i.e., if A is an array, its elements are
    // A[0], A[1], A[2] ... The element A[2] is the third element in an array, A[10] the
    // 11'th element. So, if we want frequency_of_sum[364] to be a valid element of the
    // array frequency_of_sum, it needs to have at least 365 elements.

    constexpr size_t Ntrials = 10'000'000; // Notice how we used the ' sign to group the digits for better
    // readability for humans. Use this feature! Stop wasting time staring at things like 1.6666666666,
    // and wondering how many 6s there are!

    // OK. Time for our Monte Carlo trials...
    for (size_t i = 0; i < Ntrials; ++i) {
        std::shuffle(deck.begin(), deck.end(), engine);
        // shuffle the numbers in the array deck, using "engine" as
        // the pseudo-random number source

        // Now let's add up the first hand_size numbers
        int sum = 0;
        if ((i + 1) % 1000000 == 0)
            std::cout << "Done with " << i + 1 << " shuffles.\n";
        for (size_t j = 0; j < hand_size; ++j) {
            auto card = deck[j];
            // Here we end up with a number between 1 and 52. 1..13 are hearts,
            // 14..26 are spades, 27..39 are clubs and 40..52 are diamonds. But
            // we want to only add up the numeric values of the cards, which are
            // between 1 and 13. The following line of code does it.
            card = (1 + ((card - 1) % 13));
            sum += card;
        }
        frequency_of_sum[sum]++;
    }
    // Write out the frequency table for the sum obtained in all the trials
    std::cout << std::left << std::setw(12) << "Sum"
              << std::left << std::setw(12) << "Frequency"
              << std::left << std::setw(12) << "Probability\n";
    for (size_t i = 0; i < frequency_of_sum.size(); ++i) {
        std::cout << std::left << std::setw(12) << i
                  << std::left << std::setw(12) << frequency_of_sum[i]
                  << std::left << std::setw(12) << (1.0 * frequency_of_sum[i]) / Ntrials
                  << "\n";
    }
}
