#pragma once
#include <vector>
#include <math.h>


namespace AddVectors{
	namespace Arithmetic{
		// A + A saved on A,
		// unsigned long long,
		void AplusAonA(std::vector<unsigned long long>* Adds);
		// A + A saved on B,
		// unsigned long long,
		void AplusAonB(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB);
		// A + B saved on B,
		// unsigned long long,
		void AplusBonB(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB);
		// A + B saved on C,
		// unsigned long long,
		void AplusBonC(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB, std::vector<unsigned long long>* Result);
		// A + B saved on B,
		// unsigned long long,
		// no Rest check - risk of rewind range,
		void AplusBonB_noRestCheck(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB);
		// A + A saved on A,
		// 10^RestExponent as Base, 
		// unsigned long long,
		void AplusAonAwithRestExponent(std::vector<unsigned long long>* Adds, int* RestExponent);
	}
	namespace FullAdder{
		// A + A saved on A,
		// unsigned long long,
		// Add without arithmetic operators,
		// not tested!!
		void AplusAonA_FullAdder(std::vector<unsigned long long>* Adds);
	}
	namespace Cores3{
		// A + B saved on B, 3 cores,
		// unsigned long long,
		void AplusBonBwithCores3(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB);
		// A + A saved on B, 3 cores,
		// unsigned long long,
		void AplusAonBwithCores3(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB);
	}
}