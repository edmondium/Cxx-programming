#include <any>
#include <map>
#include <string>
#include <print>
#if __has_include(<boost/core/demangle.hpp>)
  #include <boost/core/demangle.hpp>
  #define has_boost_demangle 1
#endif
// Uncomment the above to see the type info in a more human readable form
using namespace std;
using namespace std::literals;

auto demangle(auto anyobj) -> std::string
{
    #ifdef has_boost_demangle
    auto dmgnm = boost::core::demangle(anyobj.type().name());
    #else
    auto dmgnm = anyobj.type().name();
    #endif
    return std::format("any[[{}]]", dmgnm) ;
}

auto main() -> int
{
    any var = 1;
    std::print("Reading int after storing int ...\n{}, value = {}\n", 
         demangle(var), any_cast<int>(var));
    try {
        std::print("Trying to get a float after storing an int ... \n");
        auto res = any_cast<float>(var);
	std::print("extracted value = {}\n", res);
    } catch (const exception& err) {
        std::print("Float cast after storing int failed. Error : {}\n", 
             err.what());
    }
    var = "Europa"s;
    std::print("Reading string after storing string ... \n{}, value = {}\n", 
         demangle(var), any_cast<string>(var));
    try {
        std::print("Trying to get a int after storing an string  ...\n"); 
        auto res = any_cast<int>(var);
	std::print("extracted value = {}\n", res);
    } catch (const exception& err) {
        std::print("Int cast after storing string failed. Error : {}\n", 
             err.what());
    }

    map<string, any> config;

    config["max_frequency_ghz"] = 3.3; // any kind of values can be stored
    config["memory_MB"] = 16384;       // in a container expecting std::any.
    config["fingerprint_reader"] = true; // But, you can only read it back
                                         // if you know the type you stored!
}

