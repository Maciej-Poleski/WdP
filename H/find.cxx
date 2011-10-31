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
    uniform_int_distribution<char> lowerDistribution('a','c');
    uniform_int_distribution<char> upperDistribution('A','C');
    uniform_int_distribution<char> boolDistribution(0,1);
    uniform_int_distribution<uint_fast8_t> lengthDistribution(1,15);
    uniform_int_distribution<uint_fast8_t> yearsDistribution(1,100);
    uniform_real_distribution<double> profitDistribution(0,10000);
    mt19937 engine;
    auto lowerCharacter=bind(lowerDistribution,engine);
    auto upperCharacter=bind(upperDistribution,engine);
    auto select=bind(boolDistribution,engine);
    auto length=bind(lengthDistribution,engine);
    auto years=bind(yearsDistribution,engine);
    auto profit=bind(profitDistribution,engine);
    const uint_fast32_t n=10000;
    const uint_fast32_t z=10;

    do
    {
        cout<<"Test "<<cc++<<'\n';
        ofstream out(argv[3]);
        out<<z<<"\n";
        for(uint_fast32_t i=0;i<z;++i)
        {
            out<<n<<'\n';
            for(size_t i=0; i<n; ++i)
            {
                for(uint_fast8_t j=0,je=length(); j<je; ++j)
                    out<<static_cast<char>(select()?lowerCharacter():upperCharacter());
                out<<' '<<static_cast<unsigned int>(years())<<' '<<static_cast<double>(profit())<<'\n';
            }
        }
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
        command="diff -i ";
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
