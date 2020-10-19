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