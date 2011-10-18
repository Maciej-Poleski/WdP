#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <stdint.h>

using namespace std;

int main(int argc,char**argv)
{
    if(argc!=3)
    {
        cerr<<"Niewłaściwa liczba argumentów!\n";
        return 1;
    }
    ifstream in(argv[1]);
    ofstream out(argv[2]);

    uint_fast32_t z;
    in>>z;
    vector<uint_fast16_t> inputPermutation;
    while(z--)
    {
        uint_fast16_t n;
        in>>n;
        inputPermutation.clear();
        inputPermutation.reserve(n);
        for(decltype(n) i=0; i<n; ++i)
        {
            decltype(n) t;
            in>>t;
            inputPermutation.push_back(t);
        }
        if(next_permutation(inputPermutation.begin(),inputPermutation.end()))
        {
            for(auto e:inputPermutation)
                out<<e<<' ';
            out<<'\n';
        }
        else
        {
            out<<"BRAK\n";
        }
    }

    return 0;
}
