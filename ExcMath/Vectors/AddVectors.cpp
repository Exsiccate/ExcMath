#include "AddVectors.h"


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

void AddVectors(
	std::vector<unsigned long long>* AddA, 
	std::vector<unsigned long long>* AddB, 
	std::vector<unsigned long long>* Result)
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

void AddVectors(std::vector<unsigned long long> *Adds,int *RestExponent)
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