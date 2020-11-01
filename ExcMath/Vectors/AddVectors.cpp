#include "AddVectors.hpp"
#include <thread>

namespace {
	// initial values:
	unsigned long long CarryULL = 1000000000000000000;
}

namespace {
	void AddVectorsCore1(
		std::vector<unsigned long long> *Core1AddA,
		std::vector<unsigned long long> *Core1AddB,
		unsigned long long *Core1Start,
		unsigned long long *Core1Stop,
		unsigned long long *Core1Rest)
	{
		for (unsigned long long i = *Core1Start; i <= *Core1Stop; i++) {
			(*Core1AddB)[i] = (*Core1AddB)[i] + (*Core1AddA)[i] + *Core1Rest;
			*Core1Rest = 0;
			if ((*Core1AddB)[i] >= 1000000000000000000) {
				(*Core1AddB)[i] = (*Core1AddB)[i] - 1000000000000000000;
				*Core1Rest = 1;
			}
		}
	}
	void AddVectorsCore2(
		std::vector<unsigned long long> *Core2AddA,
		std::vector<unsigned long long> *Core2AddB,
		unsigned long long *Core2Start,
		unsigned long long *Core2Stop,
		unsigned long long *Core2Rest) {

		for (unsigned long long i = *Core2Start; i <= *Core2Stop; i++) {
			(*Core2AddB)[i] = (*Core2AddB)[i] + (*Core2AddA)[i] + *Core2Rest;
			*Core2Rest = 0;
			if ((*Core2AddB)[i] >= 1000000000000000000) {
				(*Core2AddB)[i] = (*Core2AddB)[i] - 1000000000000000000;
				*Core2Rest = 1;
			}
		}
	}
	void AddVectorsCore3(
		std::vector<unsigned long long> *Core3AddA,
		std::vector<unsigned long long> *Core3AddB,
		unsigned long long *Core3Start,
		unsigned long long *Core3Stop,
		unsigned long long *Core3Rest) {

		for (unsigned long long i = *Core3Start; i <= *Core3Stop; i++) {
			(*Core3AddB)[i] = (*Core3AddB)[i] + (*Core3AddA)[i] + *Core3Rest;
			*Core3Rest = 0;
			if ((*Core3AddB)[i] >= 1000000000000000000) {
				(*Core3AddB)[i] = (*Core3AddB)[i] - 1000000000000000000;
				*Core3Rest = 1;
			}
		}
	}
}

void AddVectors(std::vector<unsigned long long> *Adds)
{
	int Rest = 0;
	unsigned long long UnsLL = 1000000000000000000;
	for (unsigned long long i = 0; i < (*Adds).size(); i++) {
		(*Adds)[i] = (*Adds)[i] + (*Adds)[i] + Rest;
		Rest = 0;
		if ((*Adds)[i] >= UnsLL) {
			(*Adds)[i] = (*Adds)[i] - UnsLL;
			Rest = 1;
		}
	}
	if (Rest == 1) (*Adds).push_back(1);
}
void AddVectors(std::vector<unsigned long long> *Adds, int *RestExponent)
{
	int Rest = 0;
	unsigned long long UnsLL = pow(10, (*RestExponent));
	for (unsigned long long i = 0; i < (*Adds).size(); i++) {
		(*Adds)[i] = (*Adds)[i] + (*Adds)[i] + Rest;
		Rest = 0;
		if ((*Adds)[i] >= UnsLL) {
			(*Adds)[i] = (*Adds)[i] - UnsLL;
			Rest = 1;
		}
	}
	if (Rest == 1) (*Adds).push_back(1);
}
void AddVectors(std::vector<unsigned long long> *AddA, std::vector<unsigned long long> *AddB)
{
	int Rest = 0;
	unsigned long long UnsLL = 1000000000000000000;
	if ((*AddA).size() == (*AddB).size()) {
		for (unsigned long long i = 0; i < (*AddA).size(); i++) {
			(*AddB)[i] = (*AddA)[i] + (*AddB)[i] + Rest;
			Rest = 0;
			if ((*AddB)[i] >= UnsLL) {
				(*AddB)[i] = (*AddB)[i] - UnsLL;
				Rest = 1;
			}
		}
		if (Rest == 1) (*AddB).push_back(1);
	}
	else if ((*AddA).size() < (*AddB).size()){
		for (unsigned long long i = 0; i < (*AddA).size(); i++) {
			(*AddB)[i] = (*AddA)[i] + (*AddB)[i] + Rest;
			Rest = 0;
			if ((*AddB)[i] >= UnsLL) {
				(*AddB)[i] = (*AddB)[i] - UnsLL;
				Rest = 1;
			}
		}
		for (unsigned long long i = (*AddA).size(); i < (*AddB).size(); i++) {
			(*AddB)[i] = (*AddB)[i] + Rest;
			Rest = 0;
			if ((*AddB)[i] >= UnsLL) {
				(*AddB)[i] = (*AddB)[i] - UnsLL;
				Rest = 1;
			}
		}
		if (Rest == 1) (*AddB).push_back(1);
	}
	else {
		for (unsigned long long i = 0; i < (*AddB).size(); i++) {
			(*AddB)[i] = (*AddA)[i] + (*AddB)[i] + Rest;
			Rest = 0;
			if ((*AddB)[i] >= UnsLL) {
				(*AddB)[i] = (*AddB)[i] - UnsLL;
				Rest = 1;
			}
		}
		for (unsigned long long i = (*AddB).size(); i < (*AddA).size(); i++) {
			(*AddB).push_back((*AddA)[i] + Rest);
			Rest = 0;
			if ((*AddB)[i] >= UnsLL) {
				(*AddB)[i] = (*AddB)[i] - UnsLL;
				Rest = 1;
			}
		}
		if (Rest == 1) (*AddB).push_back(1);
	}
}
void AddVectors(std::vector<unsigned long long> *AddA, std::vector<unsigned long long> *AddB, std::vector<unsigned long long> *Result)
{
	int Rest = 0;
	unsigned long long UnsLL = 1000000000000000000;
	(*Result).resize(0);

	if ((*AddA).size() == (*AddB).size()) {
		for (unsigned long long i = 0; i < (*AddA).size(); i++) {
			(*Result).push_back((*AddA)[i]+(*AddB)[i]+Rest);
			Rest = 0;
			if ((*Result)[i] >= UnsLL) {
				(*Result)[i] = (*Result)[i] - UnsLL;
				Rest = 1;
			}
		}
		if (Rest == 1) (*Result).push_back(1);
	}
	else if ((*AddA).size() < (*AddB).size()) {
		for (unsigned long long i = 0; i < (*AddA).size(); i++) {
			(*Result).push_back((*AddA)[i] + (*AddB)[i] + Rest);
			Rest = 0;
			if ((*Result)[i] >= UnsLL) {
				(*Result)[i] = (*Result)[i] - UnsLL;
				Rest = 1;
			}
		}
		for (unsigned long long i = (*AddA).size(); i < (*AddB).size(); i++) {
			(*Result).push_back((*AddB)[i] + Rest);
			Rest = 0;
			if ((*Result)[i] >= UnsLL) {
				(*Result)[i] = (*Result)[i] - UnsLL;
				Rest = 1;
			}
		}
		if (Rest == 1) (*Result).push_back(1);
	}
	else{
		for (unsigned long long i = 0; i < (*AddB).size(); i++) {
			(*Result).push_back((*AddA)[i] + (*AddB)[i] + Rest);
			Rest = 0;
			if ((*Result)[i] >= UnsLL) {
				(*Result)[i] = (*Result)[i] - UnsLL;
				Rest = 1;
			}
		}
		for (unsigned long long i = (*AddB).size(); i < (*AddA).size(); i++) {
			(*Result).push_back((*AddA)[i] + Rest);
			Rest = 0;
			if ((*Result)[i] >= UnsLL) {
				(*Result)[i] = (*Result)[i] - UnsLL;
				Rest = 1;
			}
		}
		if (Rest == 1) (*Result).push_back(1);
	}

}

void AddVectorsCores3(std::vector<unsigned long long>* AddA, std::vector<unsigned long long>* AddB)
{
	unsigned long long RangeStartValue0 = 0;
	unsigned long long RangeStartValue1 = 0;
	unsigned long long RangeStartValue2 = 0;
	unsigned long long RangeStartValue3 = 0;
	unsigned long long Core1RestStartValue = 0;
	unsigned long long Core2RestStartValue = 0;
	unsigned long long Core3RestStartValue = 0;

	unsigned long long* Range0 = &RangeStartValue0;
	unsigned long long* Range1 = &RangeStartValue1;
	unsigned long long* Range2 = &RangeStartValue2;
	unsigned long long* Range3 = &RangeStartValue3;
	unsigned long long* Core1Rest = &Core1RestStartValue;
	unsigned long long* Core2Rest = &Core2RestStartValue;
	unsigned long long* Core3Rest = &Core3RestStartValue;

	if ((*AddA).size() <= (*AddB).size()) {
		if ((*AddA).size() < 3) {
			AddVectors(AddA, AddB);
			return;
		}
		*Range0 = 0;
		*Range1 = floor((*AddA).size() / 3) - 1;
		*Range2 = 2 * (*Range1) + 1;
		*Range3 = (*AddA).size() - 1;
	}
	else {
		if ((*AddB).size() < 3) {
			AddVectors(AddA, AddB);
			return;
		}
		*Range0 = 0;
		*Range1 = floor((*AddB).size() / 3) - 1;
		*Range2 = 2 * (*Range1) + 1;
		*Range3 = (*AddB).size() - 1;
	}

	if ((*AddA)[*Range1] + (*AddB)[*Range1] >= 1000000000000000000) *Core2Rest = 1;
	if ((*AddA)[*Range2] + (*AddB)[*Range2] >= 1000000000000000000) *Core3Rest = 1;

	std::thread Core1(AddVectorsCore1, AddA, AddB, Range0, Range1, Core1Rest);
	std::thread Core2(AddVectorsCore1, AddA, AddB, Range1 + 1, Range2, Core2Rest);
	std::thread Core3(AddVectorsCore1, AddA, AddB, Range2, Range3, Core3Rest);

	Core1.join();
	Core2.join();
	Core3.join();

	if (*Core3Rest == 1) {
			if ((*AddA).size() == (*AddB).size()) {
				(*AddB).push_back(1);
			}
			else if ((*AddA).size() > (*AddB).size()) {
				for (unsigned long long i = *Range3 + 1; i < (*AddA).size(); i++) {
					(*AddB).push_back((*AddA)[i] + (*Core3Rest));
					if ((*AddB)[i] >= 1000000000000000000) {
						(*AddB)[i] = (*AddB)[i] - 1000000000000000000;
						//*Core3Rest = 1;
					}
					else {
						*Core3Rest = 0;
						break;
					}
				}
				if (*Core3Rest == 1) (*AddB).push_back(1);
			}
			else {
				for (unsigned long long i = *Range3 + 1; i < (*AddB).size(); i++) {
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