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
    typedef int_fast32_t element;
    vector<element> input;
    while(z--)
    {
        uint_fast32_t n;
        in>>n;
        input.clear();
        input.reserve(n);
        for(decltype(n) i=0; i<n; ++i)
        {
            element t;
            in>>t;
            input.push_back(t);
        }
        decltype(n) q;
        in>>q;
        for(decltype(q) i=0;i<q;++i)
        {
            element s;
            in>>s;
            if(binary_search(input.begin(),input.end(),s)==false)
            {
                out<<"0\n";
            }
            else
            {
                out<<upper_bound(input.begin(),input.end(),s)-lower_bound(input.begin(),input.end(),s)<<'\n';
            }
        }
    }

    return 0;
}
