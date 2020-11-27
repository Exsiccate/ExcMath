#include "AddVectors.hpp"
#include <thread>
//#include <bitset>

//cores...
namespace {
	inline void AplusAonBCore1(
		std::vector<unsigned long long>* Core1AddA,
		std::vector<unsigned long long>* Core1AddB,
		unsigned long long Core1Start,
		unsigned long long Core1Stop,
		int Core1Rest)
	{
		for (unsigned long long i  = Core1Start; i <= Core1Stop; i++) {
			(*Core1AddB)[i] = (*Core1AddA)[i] + (*Core1AddA)[i] + Core1Rest;
			Core1Rest = 0;
			if ((*Core1AddB)[i] >= 1000000000000000000) {
				(*Core1AddB)[i] = (*Core1AddB)[i] - 1000000000000000000;
				Core1Rest = 1;
			}
		}
	}
	inline void AplusAonBCore2(
		std::vector<unsigned long long>* Core2AddA,
		std::vector<unsigned long long>* Core2AddB,
		unsigned long long Core2Start,
		unsigned long long Core2Stop,
		int Core2Rest)
	{
		for (unsigned long long i  = Core2Start + 1; i <= Core2Stop; i++) {
			(*Core2AddB)[i] = (*Core2AddA)[i] + (*Core2AddA)[i] + Core2Rest;
			Core2Rest = 0;
			if ((*Core2AddB)[i] >= 1000000000000000000) {
				(*Core2AddB)[i] = (*Core2AddB)[i] - 1000000000000000000;
				Core2Rest = 1;
			}
		}
	}
	inline void AplusAonBCore3(
		std::vector<unsigned long long>* Core3AddA,
		std::vector<unsigned long long>* Core3AddB,
		unsigned long long Core3Start,
		unsigned long long Core3Stop,
		int* Core3Rest)
	{
		for (unsigned long long i  = Core3Start + 1; i <= Core3Stop; i++) {
			(*Core3AddB)[i] = (*Core3AddA)[i] + (*Core3AddA)[i] + *Core3Rest;
			*Core3Rest = 0;
			if ((*Core3AddB)[i] >= 1000000000000000000) {
				(*Core3AddB)[i] = (*Core3AddB)[i] - 1000000000000000000;
				*Core3Rest = 1;
			}
		}
	}

	inline void AplusBonBCore1(
		std::vector<unsigned long long>* Core1AddA,
		std::vector<unsigned long long>* Core1AddB,
		long long Core1Start,
		long long Core1Stop,
		int Core1Rest)
	{
		for (long i = Core1Start; i <= Core1Stop; i++) {
			(*Core1AddB)[i] = (*Core1AddB)[i] + (*Core1AddA)[i] + Core1Rest;
			Core1Rest = 0;
			if ((*Core1AddB)[i] >= 1000000000000000000) {
				(*Core1AddB)[i] = (*Core1AddB)[i] - 1000000000000000000;
				Core1Rest = 1;
			}
		}
	}
	inline void AplusBonBCore2(
		std::vector<unsigned long long>* Core2AddA,
		std::vector<unsigned long long>* Core2AddB,
		long long Core2Start,
		long long Core2Stop,
		int Core2Rest) {

		for (long i = Core2Start + 1; i <= Core2Stop; i++) {
			(*Core2AddB)[i] = (*Core2AddB)[i] + (*Core2AddA)[i] + Core2Rest;
			Core2Rest = 0;
			if ((*Core2AddB)[i] >= 1000000000000000000) {
				(*Core2AddB)[i] = (*Core2AddB)[i] - 1000000000000000000;
				Core2Rest = 1;
			}
		}
	}
	inline void AplusBonBCore3(
		std::vector<unsigned long long>* Core3AddA,
		std::vector<unsigned long long>* Core3AddB,
		long long Core3Start,
		long long Core3Stop,
		int *Core3Rest) {

		for (long i = Core3Start + 1; i <= Core3Stop; i++) {
			(*Core3AddB)[i] = (*Core3AddB)[i] + (*Core3AddA)[i] + *Core3Rest;
			*Core3Rest = 0;
			if ((*Core3AddB)[i] >= 1000000000000000000) {
				(*Core3AddB)[i] = (*Core3AddB)[i] - 1000000000000000000;
				*Core3Rest = 1;
			}
		}
	}
}

//fuld adder
namespace {

// CPP program to modify a bit at position p in n to b. 
// n - input number,
// p - position,
// b - to which bit,
	inline void modifyBit64(unsigned long long* n, int p, int b)
	{
		__int64 mask = static_cast <__int64>(1) << p;
		*n = (static_cast <__int64>(*n) & ~mask) | ((b << p) & mask);
	}
	void modifyBit(__int32* n, __int32 p, __int32 b)
	{
		__int32 mask = 1 << p;
		*n = (*n & ~mask) | ((b << p) & mask);
	}
	//n-number,
	//k-position,
	void isKthBitSet64(__int64 n, __int64 k)
	{
		/*
		if (static_cast<__int64>(n) & (static_cast <__int64>(1) << (static_cast<__int64>(k) - 1)))
			cout << "n: " << n << ", k: " << k << ", SET" << endl;
		else
			cout << "n: " << n << ", k: " << k << ", NOT SET" << endl;
		*/
	}
	void isKthBitSet(__int32 n, __int32 k)
	{
		/*
		if (n & (1 << (k - 1)))
			//cout << "n: " << n << ", k: " << k << ", SET" << endl;
		else
			std::cout << "n: " << n << ", k: " << k << ", NOT SET" << endl;
		*/
	}
}

namespace AddVectors {
	void AplusAonA(std::vector<unsigned long long>* Adds)
	{
		int Rest = 0;
		for (unsigned long long i  = 0; i < (*Adds).size(); i++) {
			(*Adds)[i] = (*Adds)[i] + (*Adds)[i] + Rest;
			Rest = 0;
			if ((*Adds)[i] >= 1000000000000000000) {
				(*Adds)[i] = (*Adds)[i] - 1000000000000000000;
				Rest = 1;
			}
		}
		if (Rest == 1) (*Adds).push_back(1);
	}
	void AplusAonB(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB)
	{
		int Rest = 0;
		(*AddB).resize(0);
		for (unsigned long long i  = 0; i < (*AddA).size(); i++) {
			(*AddB).push_back((*AddA)[i] + (*AddA)[i] + Rest);
			Rest = 0;
			if ((*AddB)[i] >= 1000000000000000000) {
				(*AddB)[i] = (*AddB)[i] - 1000000000000000000;
				Rest = 1;
			}
		}
		if (Rest == 1) (*AddB).push_back(1);
	}
	void AplusBonB(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB)
	{
		int Rest = 0;
		if ((*AddA).size() == (*AddB).size()) {
			for (unsigned long long i   = 0; i < (*AddA).size(); i++) {
				(*AddB)[i] = (*AddA)[i] + (*AddB)[i] + Rest;
				Rest = 0;
				if ((*AddB)[i] >= 1000000000000000000) {
					(*AddB)[i] = (*AddB)[i] - 1000000000000000000;
					Rest = 1;
				}
			}
			if (Rest == 1) (*AddB).push_back(1);
		}
		else if ((*AddA).size() < (*AddB).size()) {
			for (unsigned long long i  = 0; i < (*AddA).size(); i++) {
				(*AddB)[i] = (*AddA)[i] + (*AddB)[i] + Rest;
				Rest = 0;
				if ((*AddB)[i] >= 1000000000000000000) {
					(*AddB)[i] = (*AddB)[i] - 1000000000000000000;
					Rest = 1;
				}
			}
			for (unsigned long long i  = (*AddA).size(); i < (*AddB).size(); i++) {
				(*AddB)[i] = (*AddB)[i] + Rest;
				Rest = 0;
				if ((*AddB)[i] >= 1000000000000000000) {
					(*AddB)[i] = (*AddB)[i] - 1000000000000000000;
					Rest = 1;
				}
			}
			if (Rest == 1) (*AddB).push_back(1);
		}
		else {
			for (unsigned long long i  = 0; i < (*AddB).size(); i++) {
				(*AddB)[i] = (*AddA)[i] + (*AddB)[i] + Rest;
				Rest = 0;
				if ((*AddB)[i] >= 1000000000000000000) {
					(*AddB)[i] = (*AddB)[i] - 1000000000000000000;
					Rest = 1;
				}
			}
			for (unsigned long long i  = (*AddB).size(); i < (*AddA).size(); i++) {
				(*AddB).push_back((*AddA)[i] + Rest);
				Rest = 0;
				if ((*AddB)[i] >= 1000000000000000000) {
					(*AddB)[i] = (*AddB)[i] - 1000000000000000000;
					Rest = 1;
				}
			}
			if (Rest == 1) (*AddB).push_back(1);
		}
	}
	void AplusBonC(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB, std::vector<unsigned long long>* Result)
	{
		int Rest = 0;
		(*Result).resize(0);

		if ((*AddA).size() == (*AddB).size()) {
			for (unsigned long long i  = 0; i < (*AddA).size(); i++) {
				(*Result).push_back((*AddA)[i] + (*AddB)[i] + Rest);
				Rest = 0;
				if ((*Result)[i] >= 1000000000000000000) {
					(*Result)[i] = (*Result)[i] - 1000000000000000000;
					Rest = 1;
				}
			}
			if (Rest == 1) (*Result).push_back(1);
		}
		else if ((*AddA).size() < (*AddB).size()) {
			for (unsigned long long i  = 0; i < (*AddA).size(); i++) {
				(*Result).push_back((*AddA)[i] + (*AddB)[i] + Rest);
				Rest = 0;
				if ((*Result)[i] >= 1000000000000000000) {
					(*Result)[i] = (*Result)[i] - 1000000000000000000;
					Rest = 1;
				}
			}
			for (unsigned long long i  = (*AddA).size(); i < (*AddB).size(); i++) {
				(*Result).push_back((*AddB)[i] + Rest);
				Rest = 0;
				if ((*Result)[i] >= 1000000000000000000) {
					(*Result)[i] = (*Result)[i] - 1000000000000000000;
					Rest = 1;
				}
			}
			if (Rest == 1) (*Result).push_back(1);
		}
		else {
			for (unsigned long long i  = 0; i < (*AddB).size(); i++) {
				(*Result).push_back((*AddA)[i] + (*AddB)[i] + Rest);
				Rest = 0;
				if ((*Result)[i] >= 1000000000000000000) {
					(*Result)[i] = (*Result)[i] - 1000000000000000000;
					Rest = 1;
				}
			}
			for (unsigned long long i  = (*AddB).size(); i < (*AddA).size(); i++) {
				(*Result).push_back((*AddA)[i] + Rest);
				Rest = 0;
				if ((*Result)[i] >= 1000000000000000000) {
					(*Result)[i] = (*Result)[i] - 1000000000000000000;
					Rest = 1;
				}
			}
			if (Rest == 1) (*Result).push_back(1);
		}

	}

	void AplusAonAwithRestExponent(std::vector<unsigned long long>* Adds, int* RestExponent)
	{
		int Rest = 0;
		unsigned long long UnsLL = pow(10, (*RestExponent));
		for (unsigned long long i  = 0; i < (*Adds).size(); i++) {
			(*Adds)[i] = (*Adds)[i] + (*Adds)[i] + Rest;
			Rest = 0;
			if ((*Adds)[i] >= UnsLL) {
				(*Adds)[i] = (*Adds)[i] - UnsLL;
				Rest = 1;
			}
		}
		if (Rest == 1) (*Adds).push_back(1);
	}

	void AplusAonA_FullAdder(std::vector<unsigned long long>* Adds)
	{
		unsigned long long Rest = 0;
		int RestRewindingTheCounter = 0;
		unsigned long long AddsTemp = 0;
		for (unsigned long long i = 0; i < (*Adds).size(); i++) {
			Rest = (*Adds)[i] & (*Adds)[i];
			(*Adds)[i] = (*Adds)[i] ^ (*Adds)[i];
			AddsTemp = static_cast<__int64>(Rest) << 1;
			while (AddsTemp != 0)
			{
				Rest = AddsTemp & (*Adds)[i];
				(*Adds)[i] = AddsTemp ^ (*Adds)[i];
				AddsTemp = static_cast<__int64>(Rest) << 1;
			}
			(*Adds)[i] = (*Adds)[i] ^ RestRewindingTheCounter;

			//condition below as decimal number: >9223372036854775807,
			if (static_cast<__int64>((*Adds)[i]) & (static_cast <__int64>(1) << (static_cast<__int64>(64) - 1)))
			{
				RestRewindingTheCounter = 1;
			}
			else{
				RestRewindingTheCounter = 0;
			}
		}
		if (RestRewindingTheCounter == 1) (*Adds).push_back(1);
	}

	void AplusAonBwithCores3(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB)
	{
		int Core1RestStartValue = 0;
		int Core2RestStartValue = 0;
		int Core3RestStartValue = 0;
		int* Core3Rest = &Core3RestStartValue;
		unsigned long long RangeStartValue0 = 0;
		unsigned long long RangeStartValue1 = 0;
		unsigned long long RangeStartValue2 = 0;
		unsigned long long RangeStartValue3 = 0;

		(*AddB).resize((*AddA).size());
		if ((*AddA).size() < 3) {
			AplusAonB(AddA, AddB);
			return;
		}
		RangeStartValue0 = 0;
		RangeStartValue1 = floor((*AddA).size() / 3) - 1;
		RangeStartValue2 = 2 * (RangeStartValue1) + 1;
		RangeStartValue3 = (*AddA).size() - 1;

		Core1RestStartValue = 0;
		Core2RestStartValue = 0;
		Core3RestStartValue = 0;

		if ((*AddA)[RangeStartValue1] + (*AddA)[RangeStartValue1] >= 1000000000000000000) Core2RestStartValue = 1;
		if ((*AddA)[RangeStartValue2] + (*AddA)[RangeStartValue2] >= 1000000000000000000) Core3RestStartValue = 1;

		std::thread Core1(AplusAonBCore1, AddA, AddB, RangeStartValue0, RangeStartValue1, Core1RestStartValue);
		std::thread Core2(AplusAonBCore2, AddA, AddB, RangeStartValue1, RangeStartValue2, Core2RestStartValue);
		std::thread Core3(AplusAonBCore3, AddA, AddB, RangeStartValue2, RangeStartValue3, Core3Rest);

		Core1.join();
		Core2.join();
		Core3.join();

		if (*Core3Rest == 1) {
			if ((*AddA).size() == (*AddB).size()) {
				(*AddB).push_back(1);
			}
		}
	}
	void AplusBonBwithCores3(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB)
	{
		int Core1RestStartValue = 0;
		int Core2RestStartValue = 0;
		int Core3RestStartValue = 0;
		int *Core3Rest = &Core3RestStartValue;
		
		long long RangeStartValue0 = 0;
		long long RangeStartValue1 = 0;
		long long RangeStartValue2 = 0;
		long long RangeStartValue3 = 0;

		if ((*AddA).size() <= (*AddB).size()) {
			if ((*AddA).size() < 3) {
				AplusBonB(AddA, AddB);
				return;
			}
			RangeStartValue0 = 0;
			RangeStartValue1 = floor((*AddA).size() / 3) - 1;
			RangeStartValue2 = 2 * (RangeStartValue1) + 1;
			RangeStartValue3 = (*AddA).size() - 1;
		}
		else {
			if ((*AddB).size() < 3) {
				AplusBonB(AddA, AddB);
				return;
			}
			RangeStartValue0 = 0;
			RangeStartValue1 = floor((*AddB).size() / 3) - 1;
			RangeStartValue2 = 2 * (RangeStartValue1) + 1;
			RangeStartValue3 = (*AddB).size() - 1;
		}

		Core1RestStartValue = 0;
		Core2RestStartValue = 0;
		*Core3Rest = 0;

		if ((*AddA)[RangeStartValue1] + (*AddB)[RangeStartValue1] >= 1000000000000000000) Core2RestStartValue = 1;
		if ((*AddA)[RangeStartValue2] + (*AddB)[RangeStartValue2] >= 1000000000000000000) *Core3Rest = 1;

		std::thread Core1(AplusBonBCore1, AddA, AddB, RangeStartValue0, RangeStartValue1, Core1RestStartValue);
		std::thread Core2(AplusBonBCore2, AddA, AddB, RangeStartValue1, RangeStartValue2, Core2RestStartValue);
		std::thread Core3(AplusBonBCore3, AddA, AddB, RangeStartValue2, RangeStartValue3, Core3Rest);

		Core1.join();
		Core2.join();
		Core3.join();

		if (*Core3Rest == 1) {
			if ((*AddA).size() == (*AddB).size()) {
				(*AddB).push_back(1);
			}
			else if ((*AddA).size() > (*AddB).size()) {
				for (long i = RangeStartValue3 + 1; i < (*AddA).size(); i++) {
					(*AddB).push_back((*AddA)[i] + (*Core3Rest));
					if ((*AddB)[i] >= 1000000000000000000) {
						(*AddB)[i] = (*AddB)[i] - 1000000000000000000;
						*Core3Rest = 1;
					}
					else {
						*Core3Rest = 0;
						break;
					}
				}
				if (*Core3Rest == 1) (*AddB).push_back(1);
			}
			else {
				for (unsigned long long i  = RangeStartValue3 + 1; i < (*AddB).size(); i++) {
					(*AddB)[i] = (*AddB)[i] + (*Core3Rest);
					if ((*AddB)[i] >= 1000000000000000000) {
						(*AddB)[i] = (*AddB)[i] - 1000000000000000000;
					}
					else {
						*Core3Rest = 0;
						break;
					}
				}
				if (*Core3Rest == 1) (*AddB).push_back(1);
			}
		}
	}
}
