#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdint.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char**argv)
{
    if(argc!=6)
    {
        cerr<<argv[0]<<' '<<"<rozwiązanie> <wzorcówka> <plik wejściowy> <plik wzorcowy> <plik wyjściowy>\n";
        return 1;
    }
    typedef uint_fast16_t element;
    const element size=6;
    vector<element> permutation;
    permutation.reserve(size);
    for(element i=1;i<=size;++i)
        permutation.push_back(i);

    do
    {
        ofstream out(argv[3]);
        out<<"1\n"<<size<<'\n';
        for(auto e:permutation)
            out<<e<<' ';
        out<<'\n';
        out.close();
        string command="./";
        command+=argv[2];
        command+=" ";
        command+=argv[3];
        command+=" ";
        command+=argv[4];
        if(system(command.c_str()))
        {
            cerr<<"Wzorcówka się wysypała\n";
            return 2;
        }
        command="./";
        command+=argv[1];
        command+=" < ";
        command+=argv[3];
        command+=" > ";
        command+=argv[5];
        if(system(command.c_str()))
        {
            cerr<<"Rozwiązanie się wysypało\n";
            return 3;
        }
        command="diff ";
        command+=argv[4];
        command+=" ";
        command+=argv[5];
        if(system(command.c_str()))
        {
            cerr<<"Rozwiązania różnią się. Debuguj.\n";
            return 4;
        }

    } while(next_permutation(permutation.begin(),permutation.end()));
    cout<<"Wszystko OK. Przepychaj\n";

    return 0;
}