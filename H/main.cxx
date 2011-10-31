#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <stdint.h>

using namespace std;

struct Employee
{
    string name;
    int s;
    double f;

    bool operator<(const Employee &o) const
    {
        string upperName1="",upperName2="";
        for(char c:name)
            upperName1+=toupper(c);
        for(char c:o.name)
            upperName2+=toupper(c);
        return f<o.f || (f==o.f && s>o.s) || (f==o.f && s==o.s && upperName1>upperName2);
    }
};

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
    vector<Employee> input;
    while(z--)
    {
        uint_fast32_t n;
        in>>n;
        input.clear();
        input.reserve(n);
        for(decltype(n) i=0; i<n; ++i)
        {
            string t;
            int s;
            double f;
            in>>t>>s>>f;
            input.push_back({t,s,f});
        }
        sort(input.begin(),input.end());
        reverse(input.begin(),input.end());
        for(Employee e:input)
        {
            out<<e.name<<' '<<e.s<<' ';
            out.precision(3);
            out<<fixed<<e.f<<'\n';
        }
    }

    return 0;
}
