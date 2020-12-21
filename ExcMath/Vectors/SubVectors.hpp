#pragma once
#include <vector>

namespace SubVectors {
	// B - A saved on B,
	// unsigned long long,
	// no condition B>=A check ... 
	// ... risk of rewind range in case A>B!
	void BsubAonB(std::vector<unsigned long long>* SubB, std::vector<unsigned long long>* SubA);
}