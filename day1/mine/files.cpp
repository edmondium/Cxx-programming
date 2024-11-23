#include <fstream>
auto main () -> int
{
    std::ifstream fin;
    std::ofstream fout;
    double x, y, z;
    int i;
    std::string s;
    fin >> x >> y >> z >> i >> s;
    fout << x << y << z << i << s << std::endl;
}