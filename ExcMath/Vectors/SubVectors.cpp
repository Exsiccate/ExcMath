#include "SubVectors.hpp"

void SubVectors::BsubAonB(std::vector<unsigned long long>* SubB, std::vector<unsigned long long>* SubA)
{
	int Rest = 0;
	if ((*SubA).size() == (*SubB).size()) {
		for (unsigned long long i = 0; i < (*SubA).size(); i++) {
			if ((*SubB)[i] >= (*SubA)[i]) {
				(*SubB)[i] = (*SubB)[i] - (*SubA)[i] - Rest;
				Rest = 0;
			}
			else {
				(*SubB)[i] = (*SubB)[i] - (*SubA)[i] - Rest + 1000000000000000000;
				Rest = 1;
			}
		}
		//if((*SubB).size()>0)
		for (unsigned long long i = (*SubB).size() - 1; i >= 1; i--) {
			if ((*SubB)[i] == 0) (*SubB).pop_back();
			else break;
		}
	}
	else if ((*SubB).size() > (*SubA).size()) {
		for (unsigned long long i = 0; i < (*SubA).size(); i++) {
			if ((*SubB)[i] >= (*SubA)[i]) {
				(*SubB)[i] = (*SubB)[i] - (*SubA)[i] - Rest;
				Rest = 0;
			}
			else {
				(*SubB)[i] = (*SubB)[i] - (*SubA)[i] - Rest + 1000000000000000000;
				Rest = 1;
			}
		}
		if (Rest == 1) {
			for (unsigned long long i = (*SubA).size(); i <= (*SubB).size() - 1; i++) {
				if ((*SubB)[i] > 0) {
					(*SubB)[i] = (*SubB)[i] - Rest;
					break;
				}
				else {
					(*SubB)[i] = 999999999999999999;
					Rest = 1;
				}
			}
		}
		for (unsigned long long i = (*SubB).size() - 1; i >= 1; i--) {
			if ((*SubB)[i] == 0) (*SubB).pop_back();
			else break;
		}
	}
	else {
		//sub not possible?
	}
}
