#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <random>
#include <functional>

using namespace std;

int main(int argc,char**argv)
{
    uint64_t cc=0;
    if(argc!=6)
    {
        cerr<<argv[0]<<' '<<"<rozwiązanie> <wzorcówka> <plik wejściowy> <plik wzorcowy> <plik wyjściowy>\n";
        return 1;
    }
    typedef int_fast32_t element;
    uniform_int_distribution<element> sourceDistribution(-2000000,2000000);
    uniform_int_distribution<uint_fast32_t> multiplyDistribution(0,100);
    mt19937 engine;
    auto newElement=bind(sourceDistribution,engine);
    auto newMultiply=bind(multiplyDistribution,engine);
    const uint_fast32_t size=1000000;
    vector<element> permutation;
    for(element i=0;i<size/100;++i)
        permutation.push_back(newElement());
    vector<element> seq;
    for(auto e:permutation)
    {
        for(uint_fast32_t i=0,ee=newMultiply();i<ee;++i)
        {
            seq.push_back(e);
        }
    }
    sort(seq.begin(),seq.end());

    do
    {
        cout<<"Test "<<cc++<<'\n';
        ofstream out(argv[3]);
        out<<"1\n"<<seq.size()<<'\n';
        for(auto e:seq)
            out<<e<<' ';
        out<<'\n';
        out<<permutation.size()<<'\n';
        for(auto e:permutation)
            out<<e<<'\n';
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

    } while(next_permutation(permutation.begin(),permutation.end()));
    cout<<"Wszystko OK. Przepychaj\n";

    return 0;
}
