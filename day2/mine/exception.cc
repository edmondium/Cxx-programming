#include <iostream>
#include <stdexcept>

double f(double x) 
{
    double answer=1;
    if (x>=0 and x<10) {
        while (x>0) {
            answer*=x;
            x-=1;
        }
    } else {
        throw(std::invalid_argument("Bad parameter value " + std::to_string(x)));
    }
    return answer;
}


int main()
{
    double x=9.0;
    try {
        std::cout<<"Enter start point : ";
        std::cin >> x;
        auto res=f(x);
        std::cout <<"The result is "<<res<<'\n';
    } catch (std::exception &ex) {
        std::cerr<<"Cought exception "<<ex.what()<<'\n';
    }
}


