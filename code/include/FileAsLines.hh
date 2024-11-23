#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

class FileAsLines {
public:
    using iterator = std::vector<std::string>::iterator;
    void read(std::filesystem::path nm)
    {
        std::ifstream fin { nm };
        std::string line;
        while (getline(fin, line))
            mylines.push_back(line);
    }
    FileAsLines(std::filesystem::path nm) { read(nm); }
    FileAsLines() = default;
    FileAsLines(const FileAsLines&) = default;
    FileAsLines(FileAsLines&&) = default;
    FileAsLines& operator=(const FileAsLines&) = default;
    FileAsLines& operator=(FileAsLines&&) = default;
    ~FileAsLines() = default;
    inline auto size() const -> size_t { return mylines.size(); }
    inline auto empty() const -> bool { return mylines.empty(); }
    inline auto operator[](size_t i) const -> const std::string& { return mylines[i]; }
    inline auto operator[](size_t i) -> std::string& { return mylines[i]; }
    inline auto front() const -> const std::string& { return mylines.front(); }
    inline auto front() -> std::string& { return mylines.front(); }
    inline auto back() const -> const std::string& { return mylines.back(); }
    inline auto back() -> std::string& { return mylines.back(); }
    inline decltype(auto) begin() { return mylines.begin(); }
    inline decltype(auto) end() { return mylines.end(); }
    inline decltype(auto) begin() const { return mylines.cbegin(); }
    inline decltype(auto) end() const { return mylines.cend(); }

private:
    std::vector<std::string> mylines;
};
auto operator<<(std::ostream& os, const FileAsLines& lines) -> std::ostream& 
{
    for (auto&& line : lines) os << line;
    return os;
}


