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
    if(argc!=5)
    {
        cerr<<argv[0]<<' '<<"<rozwiązanie> <plik wejściowy> <plik wyjściowy> <plik wzorcowy>\n";
        return 1;
    }
    uniform_int_distribution<char> upperDistribution('A','C');
    uniform_int_distribution<uint_fast8_t> lengthDistribution(1,10);
    mt19937 engine;
    auto upperCharacter=bind(upperDistribution,engine);
    auto length=bind(lengthDistribution,engine);
    const uint_fast32_t n=1000000;
    const uint_fast32_t z=3;

    do
    {
        cout<<"Test "<<cc++<<'\n';
        ofstream out(argv[2]);
        out<<z<<"\n";
        ofstream wzor(argv[4]);
        for(uint_fast32_t i=0;i<z;++i)
        {
            vector<string> input;
            out<<n<<'\n';
            for(size_t j=0; j<n; ++j)
            {
                string name="";
                for(uint_fast8_t k=0,je=length(); k<je; ++k)
                    name+=static_cast<char>(upperCharacter());
                input.push_back(name);
                out<<name<<' ';
                for(uint_fast8_t k=0,je=length(); k<je; ++k)
                    out<<static_cast<char>(upperCharacter());
                out<<'\n';
            }
            sort(input.begin(),input.end());
            for(uint_fast32_t j=0;j<n;++j)
            {
                static uint_fast32_t count=1;
                if(j<n-1 && input[j]==input[j+1])
                    ++count;
                else
                {
                    wzor<<input[j]<<' '<<count<<'\n';
                    count=1;
                }
            }
        }
        out.close();
        wzor.close();
        string command="./";

        command="time ./";
        command+=argv[1];
        command+=" < ";
        command+=argv[2];
        command+=" > ";
        command+=argv[3];
        if(system(command.c_str()))
        {
            cerr<<"Rozwiązanie się wysypało\n";
            return 3;
        }
        command="diff -i ";
        command+=argv[4];
        command+=" ";
        command+=argv[3];
        if(system(command.c_str()))
        {
            cerr<<"Rozwiązania różnią się. Debuguj.\n";
            return 4;
        }

    } while(true);
    cout<<"Wszystko OK. Przepychaj\n";

    return 0;
}
