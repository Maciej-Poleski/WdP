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
    vector<string> input;
    while(z--)
    {
        uint_fast32_t n;
        in>>n;
        input.clear();
        input.reserve(n);
        for(decltype(n) i=0; i<n; ++i)
        {
            string t;
            in>>t;
            input.push_back(t);
        }
        sort(input.begin(),input.end(),[] (const string& l,const string& r) {
            for(size_t i=0; i<min(l.length(),r.length()); ++i) {
                if(tolower(l[i])<tolower(r[i]))
                    return true;
                else if(tolower(l[i])>tolower(r[i]))
                    return false;
            }
            return l.length()<r.length();
        });
        for(auto e:input)
            out<<e<<' ';
        out<<'\n';
    }

    return 0;
}
