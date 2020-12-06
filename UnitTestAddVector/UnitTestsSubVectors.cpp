#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ExcMath/Vectors/SubVectors.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestSub {
	namespace UnitTestSubUnsignedLongLong {
		// B - A saved on B,
		TEST_CLASS(Unit_Test_Sub_Vectors_B_minus_A_to_B)
		{
		public:
			TEST_METHOD(Should_Sub_Correctly) {
				//given
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				std::vector<unsigned long long> VectorSubB;
				std::vector<unsigned long long>* VecSubB = &VectorSubB;
				std::vector<unsigned long long> VectorSubA;
				std::vector<unsigned long long>* VecSubA = &VectorSubA;
				(*VecSubB).push_back(100);
				(*VecSubB).push_back(100);
				(*VecSubA).push_back(50);
				(*VecSubA).push_back(50);
				(*VecToCheckResult).push_back(50);
				(*VecToCheckResult).push_back(50);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult)[0], (*VecSubB)[0]);
				Assert::AreEqual((*VecToCheckResult)[1], (*VecSubB)[1]);
			}
			TEST_METHOD(Should_Sub_Zeros){}
			TEST_METHOD(Should_Sub_Correctly_When_VectorB_Is_Equal_VectorA){}
			TEST_METHOD(Should_Sub_Correctly_When_VectorB_Is_Longer_Than_VectorA) {}
			TEST_METHOD(Should_Sub_Correctly_When_VectorB_And_VectorS_Is_Equal_Max_Value) {}
			TEST_METHOD(Should_Sub_One_Empty) {}
			TEST_METHOD(Should_Sub_Both_Empty) {}
		};
	}
}