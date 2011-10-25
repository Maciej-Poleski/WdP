#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <random>
#include <functional>
#include <limits.h>

using namespace std;

int main(int argc,char**argv)
{
    uint64_t cc=0;
    if(argc!=6)
    {
        cerr<<argv[0]<<' '<<"<rozwiązanie> <wzorcówka> <plik wejściowy> <plik wzorcowy> <plik wyjściowy>\n";
        return 1;
    }
    uniform_int_distribution<int> distribution(INT_MIN,INT_MAX);
    mt19937 engine;
    auto select=bind(distribution,engine);
    const uint_fast32_t n=1000;

    do
    {
        cout<<"Test "<<cc++<<'\n';
        ofstream out(argv[3]);
        out<<"1\n"<<n<<'\n';
        for(size_t i=0; i<n; ++i)
        {
            out<<select()<<' ';
        }
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
        command="time ./";
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

    } while(true);
    cout<<"Wszystko OK. Przepychaj\n";

    return 0;
}
