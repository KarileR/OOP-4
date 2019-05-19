#include <iostream>
#include <vector>
#include <iomanip>
#include "../headers/vector.h"
#include "../headers/timer.h"

using std::cout;
using std::cin;
using std::endl;

int main (int argc, const char * argv[])
{
    unsigned int sz = 100000000;

    std::vector<int> v1;

    Timer clock1;

    for (int i = 1; i <= sz; i++)
    {
        v1.push_back(i);
    }

    auto h1 = clock1.elapsed();

    cout << "Uztruko " << std::fixed << std::setprecision(8) << h1 << " s " << endl;


    Vector<int> v2;

    Timer clock2;

    for (int i = 1; i <= sz; i++)
    {
        v2.push_back(i);
    }
    
    auto h2 = clock2.elapsed();
    cout << "Uztruko " << std::fixed << std::setprecision(8) << h2 << " s " << endl;
        
    return 0;
    
}
