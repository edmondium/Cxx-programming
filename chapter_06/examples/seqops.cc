#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// This function prints a given label and then the elements of a container.
// How it works is a topic for a later chapter
template <class Sequence>
void print(Sequence C, std::string label)
{
    std::cout << label << "\n";
    for (auto element : C)
        std::cout << element << ", ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print(v, "Vector v = (after initialization): ");
    if (std::is_sorted(v.begin(), v.end()))
        std::cout << "The sequence is sorted in the increasing order.\n";
    else
        std::cout << "The sequence is not sorted in the increasing order.\n";

    std::reverse(v.begin(), v.end());
    print(v, "After std::reverse: ");

    std::rotate(v.begin(), v.begin() + 3, v.end());
    print(v, "After std::rotate by 3");

    std::sort(v.begin(), v.end());
    print(v, "After std::sort");

    std::vector<int> w{ 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }, x, y, z;
    print(w, "Vector w = ");

    std::vector<int> m;
    std::merge(v.begin(), v.end(), w.begin(), w.end(), std::back_inserter(m));
    print(m, "std::merge of v and w gives ...");

    std::set_union(v.begin(), v.end(), w.begin(), w.end(),
        std::back_inserter(x));
    print(x, "Union of v and w");

    std::set_intersection(w.begin(), w.end(), v.begin(), v.end(),
        std::back_inserter(y));
    print(y, "Intersection of w and v");

    std::set_symmetric_difference(v.begin(), v.end(),
        w.begin(), w.end(),
        std::back_inserter(z));
    print(z, "Symmetric difference of v and w");

    if (std::is_permutation(z.begin(), z.end(),
            v.begin(), v.end())) {
        std::cout << "The above sequence is a permutation of the first sequence printed.\n";
    } else {
        std::cout << "The above sequence is not a permutation of the first sequence printed.\n";
    }
}
