#pragma once
#include <vector>
#include <math.h>

// A + A saved on A,
void AddVectors(std::vector<unsigned long long> *Adds);
// A + B saved on C,
// AddA + AddB saved on Result,
void AddVectors(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB, std::vector<unsigned long long>* Result);
// A + A saved on A,
// 10^RestExponent as Base, 
void AddVectors(std::vector<unsigned long long> *Adds, int *RestExponent);