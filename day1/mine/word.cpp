#include <iostream>
#include <fstream>
std::string findLargestWord (const std::string &filename) {
    std::ifstream file (filename);
    std::string word, largestWord;
    while (file >> word) {
        if (word.length() > largestWord.length()) {
            largestWord = word;
        }
    }
    return largestWord;
}
auto main () -> int
{
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    std::string largestWord = findLargestWord(filename);
    std::cout << "The largest word in the document is: " << largestWord << std::endl;
}