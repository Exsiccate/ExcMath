#pragma once
#include <vector>
#include <math.h>


namespace AddVectors{
	// A + A saved on A,
	// unsigned long long,
	void AplusAonA(std::vector<unsigned long long>* Adds);
	// A + B saved on B,
	// unsigned long long,
	void AplusBonB(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB);
	// A + B saved on C,
	// AddA + AddB saved on Result,
	// unsigned long long,
	void AplusBonC(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB, std::vector<unsigned long long>* Result);

	// A + A saved on A,
	// 10^RestExponent as Base, 
	// unsigned long long,
	void AplusAonAwithRestExponent(std::vector<unsigned long long>* Adds, int* RestExponent);

	// A + B saved on B, 3 cores,
	// unsigned long long,
	void AplusBonBwithCores3(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB);
}