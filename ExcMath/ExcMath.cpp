
#include <iostream>
#include <chrono>
#include "Vectors/AddVectors.hpp"

void workTree();

int main()
{
    auto start = std::chrono::steady_clock::now();
    workTree();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << std::endl << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void workTree() {
    char a1 = 192;// "└"
    char a2 = 195;// "├"
    char a3 = 196;// "─"
    char a4 = 179;// "|"
    char a5 = 194;// "|"

    std::cout << std::endl << " Hello Exsiccate Math!" << std::endl << std::endl << std::endl;
    std::cout << " what is included today:" << std::endl;
    std::cout << "   AddVectors:" << std::endl;
    std::cout << "     Standard approach:" << std::endl;
    std::cout << "       " << a2 << a3 << a5 << a3 << ": A + A saved on A," << std::endl;
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
    std::cout << "       " << std::endl;
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