#pragma once
#include <vector>
#include <math.h>

// A + A saved on A,
// unsigned long long,
void AddVectors(std::vector<unsigned long long> *Adds);
// A + A saved on A,
// 10^RestExponent as Base, 
// unsigned long long,
void AddVectors(std::vector<unsigned long long> *Adds, int *RestExponent);
// A + B saved on B,
// unsigned long long,
void AddVectors(std::vector<unsigned long long> *AddA, std::vector<unsigned long long> *AddB);
// A + B saved on C,
// AddA + AddB saved on Result,
// unsigned long long,
void AddVectors(std::vector<unsigned long long> *AddA, std::vector<unsigned long long> *AddB, std::vector<unsigned long long> *Result);

// A + B saved on B, 3 cores,
// unsigned long long,
void AddVectorsCores3(std::vector<unsigned long long> *AddA, std::vector<unsigned long long> *AddB);