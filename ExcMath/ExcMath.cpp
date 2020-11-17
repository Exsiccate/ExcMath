
#include <iostream>
#include <chrono>
#include "Vectors/AddVectors.hpp"
#include "Sequences/Sequences.hpp"

void timeTest();
void workTree();

int main()
{
    auto start = std::chrono::steady_clock::now();

    std::cout << std::endl << " Hello Exsiccate Math!" << std::endl << std::endl << std::endl;

    workTree();
    timeTest();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << std::endl << " total time: " << elapsed_seconds.count() << "s\n";

    char i;
    std::cout << std::endl << " end? [yes/no] ";
    std::cin >> i;
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


    //            12345678901234567890123456789012345
    std::cout << "   AddVectors (A+BonB)            : " << std::endl;
    (*AddA).resize(0);
    (*AddB).resize(0);
    for (int i = 0;i < 15;i++) PowerOfTwoOn1M(AddA);
    std::cout << "      AddA size                   : " << (*AddA).size() - 1 << std::endl;
    for (int i = 0;i < 15;i++) PowerOfTwoOn1M(AddB);
    std::cout << "      AddB size                   : " << (*AddB).size() - 1 << std::endl;
    auto timeTestStart1 = std::chrono::steady_clock::now();
    AddVectors::AplusBonB(AddA, AddB);
    auto timeTestEnd1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeTestElapsed1 = timeTestEnd1 - timeTestStart1;
    std::cout << "      AddVectors(AddA, AddB)      : " << timeTestElapsed1.count() << "s" << std::endl;
    std::cout << std::endl;



    std::cout << "   AddVectorsCores3 (A+BonB)      : " << std::endl;
    (*AddA).resize(0);
    (*AddB).resize(0);
    for (int i = 0;i < 15;i++) PowerOfTwoOn1M(AddA);
    std::cout << "      AddA size                   : " << (*AddA).size() - 1 << std::endl;
    for (int i = 0;i < 15;i++) PowerOfTwoOn1M(AddB);
    std::cout << "      AddB size                   : " << (*AddB).size() - 1 << std::endl;
    auto timeTestStart2 = std::chrono::steady_clock::now();
    AddVectors::AplusBonBwithCores3(AddA, AddB);
    auto timeTestEnd2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeTestElapsed2 = timeTestEnd2 - timeTestStart2;
    std::cout << "      AddVectorsCore3(AddA, AddB) : " << timeTestElapsed2.count() << "s" << std::endl;
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
    std::cout << "     Standard approach:" << std::endl;
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
    std::cout << "     Cores 3:" << std::endl;
    std::cout << "       " << a1 << a3 << a5 << a3 << ": A + B saved on B," << std::endl;
    std::cout << "       " << " " << " " << a2 << a3 << ": unsigned long long," << std::endl;
    std::cout << "       " << " " << " " << a1 << a3 << ": __int64 (soon)," << std::endl;
    std::cout << std::endl;
    std::cout << "   SubVectors:" << std::endl;
    std::cout << "     Standard approach:" << std::endl;
    std::cout << "       " << a2 << a3 << a3 << a3 << ": B - A saved on B (soon)," << std::endl;
    std::cout << "       " << a1 << a3 << a3 << a3 << ": B - A saved on C (soon)," << std::endl;
    std::cout << std::endl;
    std::cout << "   MulVectors:" << std::endl;
    std::cout << "     Standard approach:" << std::endl;
    std::cout << "       " << a2 << a3 << a3 << a3 << ": B * A saved on B (not soon)," << std::endl;
    std::cout << "       " << a1 << a3 << a3 << a3 << ": B * A saved on C (not soon)," << std::endl;
    std::cout << std::endl;
    std::cout << "   MulVectors:" << std::endl;
    std::cout << "     Standard approach:" << std::endl;
    std::cout << "       " << a2 << a3 << a3 << a3 << ": B / A saved on B (probably never)," << std::endl;
    std::cout << "       " << a1 << a3 << a3 << a3 << ": B / A saved on C (probably never)," << std::endl;


}