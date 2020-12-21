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
			TEST_METHOD(Should_Sub_Zero_Minus_Zero) {
				//given
				std::vector<unsigned long long> VecResult, VectorSubB, VectorSubA;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				std::vector<unsigned long long>* VecSubB = &VectorSubB;
				std::vector<unsigned long long>* VecSubA = &VectorSubA;
				(*VecSubB).push_back(0);
				(*VecSubB).push_back(0);
				(*VecSubA).push_back(0);
				(*VecSubA).push_back(0);
				(*VecToCheckResult).push_back(0);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult)[0], (*VecSubB)[0]);
				Assert::AreEqual((*VecToCheckResult).size(), (*VecSubB).size());			
			}
			TEST_METHOD(Should_Sub_Zero){
				//given
				std::vector<unsigned long long> VecResult, VectorSubB, VectorSubA;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				std::vector<unsigned long long>* VecSubB = &VectorSubB;
				std::vector<unsigned long long>* VecSubA = &VectorSubA;
				(*VecSubB).push_back(100);
				(*VecSubB).push_back(100);
				(*VecSubA).push_back(0);
				(*VecToCheckResult).push_back(100);
				(*VecToCheckResult).push_back(100);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult)[0], (*VecSubB)[0]);
				Assert::AreEqual((*VecToCheckResult)[1], (*VecSubB)[1]);
				
				//given
				(*VecSubA).push_back(0);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult)[0], (*VecSubB)[0]);
				Assert::AreEqual((*VecToCheckResult)[1], (*VecSubB)[1]);
			}
			TEST_METHOD(Should_Sub_Be_Equal_One){
				//given
				std::vector<unsigned long long> VecResult, VectorSubB, VectorSubA;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				std::vector<unsigned long long>* VecSubB = &VectorSubB;
				std::vector<unsigned long long>* VecSubA = &VectorSubA;

				for (int i = 0;i < 15;i++) {
					(*VecSubB).push_back(0);
					(*VecSubA).push_back(999999999999999999);
				}
				(*VecSubB).push_back(1);
				(*VecToCheckResult).push_back(1);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult ).size(), (*VecSubB).size());
				for (int i = 0;i < (*VecSubB).size();i++) {
					Assert::AreEqual((*VecToCheckResult)[i], (*VecSubB)[i]);
				}


				//given
				(*VecSubB).resize(0);
				(*VecSubA).resize(0);
				(*VecToCheckResult).resize(0);
				for (int i = 0;i < 5;i++) {
					(*VecSubB).push_back(0);
					(*VecSubA).push_back(999999999999999999);
				}
				(*VecSubB).push_back(1000000000000000000);
				(*VecSubA).push_back(999999999999999999);
				(*VecToCheckResult).push_back(1);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult).size(), (*VecSubB).size());
				for (int i = 0;i < (*VecSubB).size();i++) {
					Assert::AreEqual((*VecToCheckResult)[i], (*VecSubB)[i]);
				}
			}
			TEST_METHOD(Should_Sub_Be_Equal_Max_Value) {
				//given
				std::vector<unsigned long long> VecResult, VectorSubB, VectorSubA;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				std::vector<unsigned long long>* VecSubB = &VectorSubB;
				std::vector<unsigned long long>* VecSubA = &VectorSubA;

				for (int i = 0;i < 5;i++) {
					(*VecSubB).push_back(0);
					(*VecToCheckResult).push_back(999999999999999999);
				}
				(*VecSubA).push_back(1);
				(*VecSubB).push_back(1);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult).size(), (*VecSubB).size());
				for (int i = 0;i < (*VecSubB).size();i++) {
					Assert::AreEqual((*VecToCheckResult)[i], (*VecSubB)[i]);
				}
			}
			TEST_METHOD(Should_Sub_Be_Equal_Zero) {
				//given
				std::vector<unsigned long long> VecResult, VectorSubB, VectorSubA;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				std::vector<unsigned long long>* VecSubB = &VectorSubB;
				std::vector<unsigned long long>* VecSubA = &VectorSubA;

				for (int i = 0;i < 5;i++) {
					(*VecSubB).push_back(0);
					(*VecSubA).push_back(0);
				}
				(*VecSubB).push_back(999);
				(*VecSubA).push_back(999);
				(*VecToCheckResult).push_back(0);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult).size(), (*VecSubB).size());
				for (int i = 0;i < (*VecSubB).size();i++) {
					Assert::AreEqual((*VecToCheckResult)[i], (*VecSubB)[i]);
				}

				(*VecSubB).resize(0);
				(*VecSubA).resize(0);
				for (int i = 0;i < 5;i++) {
					(*VecSubB).push_back(0);
				}
				(*VecSubA).push_back(0);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult).size(), (*VecSubB).size());
				for (int i = 0;i < (*VecSubB).size();i++) {
					Assert::AreEqual((*VecToCheckResult)[i], (*VecSubB)[i]);
				}
			}
			TEST_METHOD(Should_Sub_One_Empty) {
				//given
				std::vector<unsigned long long> VecResult, VectorSubB, VectorSubA;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				std::vector<unsigned long long>* VecSubB = &VectorSubB;
				std::vector<unsigned long long>* VecSubA = &VectorSubA;

				(*VecSubB).push_back(1);
				(*VecSubB).push_back(1);
				(*VecSubA).resize(0);
				(*VecToCheckResult).push_back(1);
				(*VecToCheckResult).push_back(1);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult).size(), (*VecSubB).size());
				for (int i = 0;i < (*VecSubB).size();i++) {
					Assert::AreEqual((*VecToCheckResult)[i], (*VecSubB)[i]);
				}
			}
			TEST_METHOD(Should_Sub_Both_Empty) {
				//given
				std::vector<unsigned long long> VecResult, VectorSubB, VectorSubA;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				std::vector<unsigned long long>* VecSubB = &VectorSubB;
				std::vector<unsigned long long>* VecSubA = &VectorSubA;

				(*VecSubB).resize(0);
				(*VecSubA).resize(0);
				(*VecToCheckResult).resize(0);
				//when
				SubVectors::BsubAonB(VecSubB, VecSubA);
				//then
				Assert::AreEqual((*VecToCheckResult).size(), (*VecSubB).size());
				for (int i = 0;i < (*VecSubB).size();i++) {
					Assert::AreEqual((*VecToCheckResult)[i], (*VecSubB)[i]);
				}
			}
		};
	}
}