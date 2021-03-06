
#include <iostream>
#include <chrono>
#include <string>
#include "Vectors/AddVectors.hpp"
#include "Sequences/Sequences.hpp"

void timeTest();
void workTree();

int main()
{
    auto start = std::chrono::steady_clock::now();

    std::cout << std::endl << " Hello Exsiccate Math!" << std::endl << std::endl << std::endl;

    workTree();

    std::string i;
    do{
        timeTest();
        std::cout << std::endl << " end? [y/n] ";
        std::cin >> i;
    } while (i != "y");

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << std::endl << " total time: " << elapsed_seconds.count() << "s\n";

}

void timeTest() {
    std::vector<unsigned long long> Add1;
    std::vector<unsigned long long> Add2;
    std::vector<unsigned long long> *AddA = &Add1;
    std::vector<unsigned long long> *AddB = &Add2;
    
    (*AddA).reserve(250860);
    (*AddB).reserve(250860);


    std::cout << std::endl << std::endl;
    std::cout << " Time Tests:" << std::endl;

    // A + A on B
    //            12345678901234567890123456789012345
    std::cout << "   --------------------------------" << std::endl;
    std::cout << "   A + A on B," << std::endl;
    std::cout << "   AddVectors (A+AonB)            : " << std::endl;
    (*AddA).resize(0);
    (*AddB).resize(0);
    for (int i = 0; i < 15; i++) PowerOfTwoOn1M(AddA);
    std::cout << "      AddA size                   : " << (*AddA).size() - 1 << std::endl;
    auto timeTestStartCore1 = std::chrono::steady_clock::now();
    AddVectors::Arithmetic::AplusAonB(AddA, AddB);
    auto timeTestEndCore1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeTestElapsedCore1 = timeTestEndCore1 - timeTestStartCore1;
    std::cout << "      AplusAonB                   : " << timeTestElapsedCore1.count() << "s" << std::endl;
    std::cout << std::endl;

    (*AddA).resize(0);
    (*AddB).resize(0);
    for (int i = 0; i < 15; i++) PowerOfTwoOn1M(AddA);
    std::cout << "      AddA size                   : " << (*AddA).size() - 1 << std::endl;
    auto timeTestStartCore2 = std::chrono::steady_clock::now();
    AddVectors::Cores3::AplusAonBwithCores3(AddA, AddB);
    auto timeTestEndCore2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeTestElapsedCore2 = timeTestEndCore2 - timeTestStartCore2;
    std::cout << "      AplusAonBwithCores3         : " << timeTestElapsedCore2.count() << "s" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    (*AddA).resize(0);
    (*AddB).resize(0);
    for (int i = 0; i < 15; i++) PowerOfTwoOn1M(AddA);
    std::cout << "      AddA size                   : " << (*AddA).size() - 1 << std::endl;
    auto timeTestStartCore3 = std::chrono::steady_clock::now();
    AddVectors::FullAdder::AplusAonA_FullAdder(AddA);
    auto timeTestEndCore3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeTestElapsedCore3 = timeTestEndCore3 - timeTestStartCore3;
    std::cout << "      AplusAonB_FullAdder         : " << timeTestElapsedCore3.count() << "s" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    // A + B on B
    //            12345678901234567890123456789012345
    std::cout << "   --------------------------------" << std::endl;
    std::cout << "   A + B on B," << std::endl;
    std::cout << "   AddVectors (A+BonB)            : " << std::endl;
    (*AddA).resize(0);
    (*AddB).resize(0);
    for (int i = 0;i < 15;i++) PowerOfTwoOn1M(AddA);
    std::cout << "      AddA size                   : " << (*AddA).size() - 1 << std::endl;
    for (int i = 0;i < 15;i++) PowerOfTwoOn1M(AddB);
    std::cout << "      AddB size                   : " << (*AddB).size() - 1 << std::endl;
    auto timeTestStart1 = std::chrono::steady_clock::now();
    AddVectors::Arithmetic::AplusBonB(AddA, AddB);
    auto timeTestEnd1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeTestElapsed1 = timeTestEnd1 - timeTestStart1;
    std::cout << "      AplusBonB                   : " << timeTestElapsed1.count() << "s" << std::endl;
    std::cout << std::endl;


    std::cout << "   AddVectorsCores3 (A+BonB)      : " << std::endl;
    (*AddA).resize(0);
    (*AddB).resize(0);
    for (int i = 0;i < 15;i++) PowerOfTwoOn1M(AddA);
    std::cout << "      AddA size                   : " << (*AddA).size() - 1 << std::endl;
    for (int i = 0;i < 15;i++) PowerOfTwoOn1M(AddB);
    std::cout << "      AddB size                   : " << (*AddB).size() - 1 << std::endl;
    auto timeTestStart2 = std::chrono::steady_clock::now();
    AddVectors::Cores3::AplusBonBwithCores3(AddA, AddB);
    auto timeTestEnd2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeTestElapsed2 = timeTestEnd2 - timeTestStart2;
    std::cout << "      AplusBonBwithCores3         : " << timeTestElapsed2.count() << "s" << std::endl;
    std::cout << std::endl;


    std::cout << "   AplusBonB_noRestCheck (A+BonB) : " << std::endl;
    (*AddA).resize(0);
    (*AddB).resize(0);
    for (int i = 0;i < 30;i++) PowerOfTwoOn1M(AddA);
    std::cout << "      AddA size                   : " << (*AddA).size() - 1 << std::endl;
    for (int i = 0;i < 30;i++) PowerOfTwoOn1M(AddB);
    std::cout << "      AddB size                   : " << (*AddB).size() - 1 << std::endl;
    auto timeTestStart3 = std::chrono::steady_clock::now();
    AddVectors::Arithmetic::AplusBonB_noRestCheck(AddA, AddB);
    auto timeTestEnd3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeTestElapsed3 = timeTestEnd3 - timeTestStart3;
    std::cout << "      AplusBonB_noRestCheck       : " << timeTestElapsed3.count() << "s" << std::endl;
    std::cout << std::endl;
    
    
    std::cout << std::endl;
}

void workTree() {
    char a1 = 192;// "└"
    char a2 = 195;// "├"
    char a3 = 196;// "─"
    char a4 = 179;// "|"
    char a5 = 194;// "|"

    std::cout << " ExcMath today:" << std::endl;
    std::cout << "   AddVectors:" << std::endl;
    std::cout << "     Arithmetic approach:" << std::endl;
    std::cout << "       " << a2 << a3 << a5 << a3 << ": A + A saved on A," << std::endl;
    std::cout << "       " << a4 << " " << a2 << a3 << ": unsigned long long," << std::endl;
    std::cout << "       " << a4 << " " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << "       " << a4 << std::endl;
    std::cout << "       " << a2 << a3 << a5 << a3 << ": A + A saved on B," << std::endl;
    std::cout << "       " << a4 << " " << a2 << a3 << ": unsigned long long," << std::endl;
    std::cout << "       " << a4 << " " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << "       " << a4 << std::endl;
    std::cout << "       " << a2 << a3 << a5 << a3 << ": A + B saved on B," << std::endl;
    std::cout << "       " << a4 << " " << a2 << a3 << ": unsigned long long," << std::endl;
    std::cout << "       " << a4 << " " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << "       " << a4 << std::endl;
    std::cout << "       " << a1 << a3 << a5 << a3 << ": A + B saved on C," << std::endl;
    std::cout << "       " << "  " << a2 << a3 << ": unsigned long long," << std::endl;
    std::cout << "       " << "  " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << "     No Rest Check:" << std::endl;
    std::cout << "       " << a2 << a3 << a5 << a3 << ": A + A saved on B (soon)," << std::endl;
    std::cout << "       " << a4 << " " << a2 << a3 << ": unsigned long long (soon)," << std::endl;
    std::cout << "       " << a4 << " " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << "       " << a4 << std::endl;
    std::cout << "       " << a1 << a3 << a5 << a3 << ": A + B saved on B," << std::endl;
    std::cout << "       " << "  " << a2 << a3 << ": unsigned long long," << std::endl;
    std::cout << "       " << "  " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << "     Cores 3:" << std::endl;
    std::cout << "       " << a2 << a3 << a5 << a3 << ": A + A saved on B," << std::endl;
    std::cout << "       " << a4 << " " << a2 << a3 << ": unsigned long long," << std::endl;
    std::cout << "       " << a4 << " " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << "       " << a4 << std::endl;
    std::cout << "       " << a1 << a3 << a5 << a3 << ": A + B saved on B," << std::endl;
    std::cout << "       " << "  " << a2 << a3 << ": unsigned long long," << std::endl;
    std::cout << "       " << "  " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << "     Full Adder:" << std::endl;
    std::cout << "       " << a2 << a3 << a5 << a3 << ": A + A saved on A," << std::endl;
    std::cout << "       " << a4 << " " << a2 << a3 << ": unsigned long long," << std::endl;
    std::cout << "       " << a4 << " " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << "       " << a4 << std::endl;
    std::cout << "       " << a1 << a3 << a5 << a3 << ": A + A saved on B (soon)," << std::endl;
    std::cout << "       " << "  " << a2 << a3 << ": unsigned long long (soon)," << std::endl;
    std::cout << "       " << "  " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << std::endl;
    std::cout << "   SubVectors:" << std::endl;
    std::cout << "     Arithmetic approach:" << std::endl;
    std::cout << "       " << a2 << a3 << a3 << a3 << ": B - A saved on B," << std::endl;
    std::cout << "       " << a1 << a3 << a3 << a3 << ": B - A saved on C (soon)," << std::endl;
    std::cout << std::endl;
    std::cout << "   MulVectors:" << std::endl;
    std::cout << "     Arithmetic approach:" << std::endl;
    std::cout << "       " << a2 << a3 << a3 << a3 << ": B * A saved on B (not soon)," << std::endl;
    std::cout << "       " << a1 << a3 << a3 << a3 << ": B * A saved on C (not soon)," << std::endl;
    std::cout << std::endl;
    std::cout << "   DivVectors:" << std::endl;
    std::cout << "     Arithmetic approach:" << std::endl;
    std::cout << "       " << a2 << a3 << a3 << a3 << ": B / A saved on B (probably never)," << std::endl;
    std::cout << "       " << a1 << a3 << a3 << a3 << ": B / A saved on C (probably never)," << std::endl;


}