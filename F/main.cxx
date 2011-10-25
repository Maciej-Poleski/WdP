#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <stdint.h>
#include <initializer_list>

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
    vector<int> input;
    while(z--)
    {
        uint_fast32_t n;
        in>>n;
        input.clear();
        input.reserve(n);
        for(decltype(n) i=0; i<n; ++i)
        {
            int t;
            in>>t;
            input.push_back(t);
        }
        sort(input.begin(),input.end());
        for(auto e:input)
            out<<e<<' ';
        out<<'\n';
        try {
            for(decltype(n) i=0; i<n; ++i)
            {
                decltype(n) j=0,k=n-1;
                while(j<=k)
                {
                    if(input[i]+input[j]+input[k]==0)
                        throw initializer_list<decltype(n)> {i,j,k};
                    else if(input[i]+input[j]+input[k]<0)
                        ++j;
                    else
                        --k;
                }
            }
            out<<"NIE\n";
        }
        catch(initializer_list<decltype(n)> r)
        {
            out<<"TAK";
            for(auto e:r)
                out<<' '<<e;
            out<<'\n';
        }
    }

    return 0;
}
