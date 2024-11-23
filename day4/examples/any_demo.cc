#include <any>
#include <map>
#include <string>
#include <iostream>
#if __has_include(<boost/core/demangle.hpp>)
  #include <boost/core/demangle.hpp>
  #define has_boost_demangle 1
#endif
// Uncomment the above to see the type info in a more human readable form
using namespace std;
using namespace std::string_literals;

auto demangle(auto anyobj) -> std::string
{
    #ifdef has_boost_demangle
    auto dmgnm = boost::core::demangle(anyobj.type().name());
    #else
    auto dmgnm = anyobj.type().name();
    #endif
    return "any[[" + dmgnm + "]]";
}

auto main() -> int
{
    any var = 1;
    cout << "Reading int after storing int ...\n" 
         << demangle(var) << ", value = " << any_cast<int>(var) << "\n";
    try {
        cout << "Trying to get a float after storing an int ... \n";
        auto res = any_cast<float>(var);
        cout << "extracted value = " << res << "\n";
    } catch (const exception& err) {
        cout << "Float cast after storing int failed. Error : " 
             << err.what() << "\n";
    }
    var = "Europa"s;
    cout << "Reading string after storing string ... \n" 
         << demangle(var) << ", value = " << any_cast<string>(var) << "\n";
    try {
        cout << "Trying to get a int after storing an string  ...\n"; 
        auto res = any_cast<int>(var);
        cout << "extracted value = " << res << "\n";
    } catch (const exception& err) {
        cout << "Int cast after storing string failed. Error : " 
             << err.what() << "\n";
    }

    map<string, any> config;

    config["max_frequency_ghz"] = 3.3; // any kind of values can be stored
    config["memory_MB"] = 16384;       // in a container expecting std::any.
    config["fingerprint_reader"] = true; // But, you can only read it back
                                         // if you know the type you stored!
}

