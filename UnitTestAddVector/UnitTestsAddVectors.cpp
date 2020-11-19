#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ExcMath/Vectors/AddVectors.hpp"
#include "../ExcMath/Sequences/Sequences.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestAdd{
	namespace UnitTestAddCores3UnsignedLongLong {
		// A + A saved on B,
		TEST_CLASS(UnitTestAddVectorsAplusAtoBCores3) {
		public:
			TEST_METHOD(Should_Add_Zeros) {
				//given
				std::vector<unsigned long long> VecAddA, VecAddB, VecInput;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				//when
				(*VecToCheckAddA).push_back(0);
				(*VecToCheckAddB).push_back(0);
				(*VecWIthGivenInput).push_back(0);
				AddVectors::AplusAonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				Assert::AreEqual((*VecWIthGivenInput)[0], (*VecToCheckAddB)[0]);
				//when
				for (int i = 0;i < 3;i++) {
					(*VecToCheckAddA).push_back(0);
					(*VecWIthGivenInput).push_back(0);
				}
				AddVectors::AplusAonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				Assert::AreEqual((*VecWIthGivenInput)[0], (*VecToCheckAddB)[0]);
				Assert::AreEqual((*VecWIthGivenInput)[1], (*VecToCheckAddB)[1]);
				Assert::AreEqual((*VecWIthGivenInput)[2], (*VecToCheckAddB)[2]);
				Assert::AreEqual((*VecWIthGivenInput)[3], (*VecToCheckAddB)[3]);
			}
			TEST_METHOD(Should_Add_Unity) {
				//given
				std::vector<unsigned long long> VecAddA, VecAddB, VecInput;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				//when
				int i = 20;
				for (int j = 0;j <= i;j++) {
					(*VecToCheckAddA).push_back(1);
					(*VecWIthGivenInput).push_back(2);
				}
				AddVectors::AplusAonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
			}
			TEST_METHOD(Should_Add_Max_Value) {
				//given
				std::vector<unsigned long long> VecResultA;
				std::vector<unsigned long long>* VecToCheckResultA = &VecResultA;
				std::vector<unsigned long long> VecResultB;
				std::vector<unsigned long long>* VecToCheckResultB = &VecResultB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				(*VecToCheckResultA).push_back(999999999999999999);
				(*VecWIthGivenInput).push_back(999999999999999998);
				int i = 1;
				for (i = 1; i <= 10; i++) {
					(*VecToCheckResultA).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(999999999999999999);
				}
				(*VecWIthGivenInput).push_back(1);
				//when
				AddVectors::AplusAonBwithCores3(VecToCheckResultA, VecToCheckResultB);
				//then
				for (int j = 0; j <= i; j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckResultB)[j]);
				}
			}
			TEST_METHOD(Should_Add_Empty) {
				//given
				std::vector<unsigned long long> VecAddA, VecAddB;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				//when
				(*VecToCheckAddA).resize(0);
				AddVectors::AplusAonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				Assert::AreEqual((unsigned long long)0, (*VecToCheckAddB).size());
			}
		};
		// A + B saved on B,
		TEST_CLASS(UnitTestAddVectorsAplusBtoBCores3){
		public:
			TEST_METHOD(Should_Add_Correctly_When_VectorA_Is_Equal_VectorB) {
				//given
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				(*VecToCheckAddA).push_back(999999999999999999);
				(*VecToCheckAddB).push_back(999999999999999999);
				(*VecWIthGivenInput).push_back(999999999999999998);
				int i = 1;
				for (i = 1;i <= 100;i++) {
					(*VecToCheckAddA).push_back(999999999999999999);
					(*VecToCheckAddB).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(999999999999999999);
				}
				(*VecWIthGivenInput).push_back(1);
				//when
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorA_Is_Longer_Than_VectorB) {
				//given
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				(*VecToCheckAddA).push_back(999999999999999999);
				(*VecToCheckAddB).push_back(999999999999999999);
				(*VecWIthGivenInput).push_back(999999999999999998);
				int i = 1;
				for (i = 1;i <= 2;i++) {
					(*VecToCheckAddA).push_back(999999999999999999);
					(*VecToCheckAddB).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(999999999999999999);
				}
				for (i = i;i <= 10;i++) {
					(*VecToCheckAddA).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(0);
				}
				(*VecWIthGivenInput).push_back(1);
				//when
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorB_Is_Longer_Than_VectorA) {
				//given
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				(*VecToCheckAddA).push_back(999999999999999999);
				(*VecToCheckAddB).push_back(999999999999999999);
				(*VecWIthGivenInput).push_back(999999999999999998);
				int i = 1;
				for (i = 1;i <= 2;i++) {
					(*VecToCheckAddA).push_back(999999999999999999);
					(*VecToCheckAddB).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(999999999999999999);
				}
				for (i = i;i <= 10;i++) {
					(*VecToCheckAddB).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(0);
				}
				(*VecWIthGivenInput).push_back(1);
				//when
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorA_And_VectorB_Is_Max_Value) {
				//given
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				(*VecToCheckAddA).push_back(999999999999999999);
				(*VecToCheckAddB).push_back(999999999999999999);
				(*VecWIthGivenInput).push_back(999999999999999998);
				int i = 1;
				for (i = 1;i <= 15;i++) {
					(*VecToCheckAddA).push_back(999999999999999999);
					(*VecToCheckAddB).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(999999999999999999);
				}
				(*VecWIthGivenInput).push_back(1);
				//when
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_One_Vector_Is_Max_And_Second_Vector_Is_One) {
				//given
				std::vector<unsigned long long> VecAddA, VecAddB, VecInput;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				//when
				int i = 0;
				for (i = 1;i <= 2;i++) {
					(*VecToCheckAddA).push_back(0);
					(*VecToCheckAddB).push_back(0);
					(*VecWIthGivenInput).push_back(0);
				}
				(*VecToCheckAddA).push_back(1);
				(*VecToCheckAddB).push_back(999999999999999999);
				(*VecWIthGivenInput).push_back(0);
				for (i = 3;i <= 100;i++) {
					(*VecToCheckAddB).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(0);
				}
				(*VecWIthGivenInput).push_back(1);
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
				//when
				(*VecToCheckAddA).resize(0);
				(*VecToCheckAddB).resize(0);
				for (i = 1;i <= 2;i++) {
					(*VecToCheckAddA).push_back(0);
					(*VecToCheckAddB).push_back(0);
				}
				(*VecToCheckAddA).push_back(999999999999999999);
				(*VecToCheckAddB).push_back(1);
				for (i = 3;i <= 100;i++) {
					(*VecToCheckAddA).push_back(999999999999999999);
				}
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
			}
			TEST_METHOD(Should_Add_Zeros) {
				//given
				std::vector<unsigned long long> VecAddA, VecAddB, VecInput;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				//when
				(*VecToCheckAddA).push_back(0);
				(*VecToCheckAddB).push_back(0);
				(*VecWIthGivenInput).push_back(0);
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				Assert::AreEqual((*VecWIthGivenInput)[0], (*VecToCheckAddB)[0]);
				//when
				(*VecToCheckAddA).push_back(0);
				(*VecToCheckAddA).push_back(0);
				(*VecToCheckAddB).push_back(0);
				(*VecToCheckAddB).push_back(0);
				(*VecWIthGivenInput).push_back(0);
				(*VecWIthGivenInput).push_back(0);
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				Assert::AreEqual((*VecWIthGivenInput)[0], (*VecToCheckAddB)[0]);
				Assert::AreEqual((*VecWIthGivenInput)[1], (*VecToCheckAddB)[1]);
				Assert::AreEqual((*VecWIthGivenInput)[2], (*VecToCheckAddB)[2]);
			}
			TEST_METHOD(Should_Add_Unity) {
				//given
				std::vector<unsigned long long> VecAddA, VecAddB, VecInput;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				//when
				int i = 20;
				for (int j = 0;j <= i;j++) {
					(*VecToCheckAddA).push_back(1);
					(*VecToCheckAddB).push_back(1);
					(*VecWIthGivenInput).push_back(2);
				}
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
			}
			TEST_METHOD(Should_Add_Vectors_Shorter_Than_3_Elements) {
				//given
				std::vector<unsigned long long> VecAddA, VecAddB, VecInput;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				//when
				(*VecToCheckAddA).push_back(1);
				(*VecToCheckAddB).push_back(0);
				(*VecToCheckAddB).push_back(1);
				(*VecWIthGivenInput).push_back(1);
				(*VecWIthGivenInput).push_back(1);
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				Assert::AreEqual((*VecWIthGivenInput)[0], (*VecToCheckAddB)[0]);
				Assert::AreEqual((*VecWIthGivenInput)[1], (*VecToCheckAddB)[1]);

				//when
				(*VecToCheckAddA).resize(0);
				(*VecToCheckAddB).resize(0);
				(*VecToCheckAddB).push_back(1);
				(*VecToCheckAddA).push_back(0);
				(*VecToCheckAddA).push_back(1);
				(*VecWIthGivenInput).push_back(1);
				(*VecWIthGivenInput).push_back(1);
				AddVectors::AplusBonBwithCores3(VecToCheckAddA, VecToCheckAddB);
				//then
				Assert::AreEqual((*VecWIthGivenInput)[0], (*VecToCheckAddB)[0]);
				Assert::AreEqual((*VecWIthGivenInput)[1], (*VecToCheckAddB)[1]);
			}
		};
	}
	namespace UnitTestAddUnsignedLongLong {
		// A + A saved on A,
		TEST_CLASS(UnitTestAddVectorsAplusAtoA)
		{
		public:
			TEST_METHOD(Should_Add_Correctly) {
				//given
				std::string::size_type sz;

				std::vector<std::string> VecPowerOfTwoInput;
				std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				unsigned long long StringCutLength, StringCutStart;
				unsigned long long PartOfVecPowerOfTwo;
				unsigned long long BeginingOfVecPowerOfTwo;

				//when
				PowerOfTwo(VecPowerOfTwo);
				(*VecToCheckResult).push_back(1);
				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusAonA(VecToCheckResult);
					for (unsigned long long j = 0; j < (*VecToCheckResult).size() - 1; j++) {
						StringCutStart = (*VecPowerOfTwo)[i].size() - (j + 1) * 18;
						StringCutLength = 18;
						PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckResult)[j]);
					}
					if ((*VecToCheckResult).size() > 1) {
						StringCutStart = 0;
						StringCutLength = (*VecPowerOfTwo)[i].size() - ((*VecToCheckResult).size() - 1) * (18);
						BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckResult)[(*VecToCheckResult).size() - 1]);
					}
				}
			}
			TEST_METHOD(Should_Add_Zero) {
				//given
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				(*VecToCheckResult).push_back(0);
				//when
				for (unsigned long long i = 0; i < 15; i++) {
					AddVectors::AplusAonA(VecToCheckResult);
				}
				//then
				Assert::AreEqual((unsigned long long)0, (*VecToCheckResult)[0]);
			}
			TEST_METHOD(Should_Not_Add_Correctly) {
				//given
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;

				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;

				(*VecToCheckResult).push_back(1);
				(*VecWIthGivenInput).push_back(0);

				//when
				AddVectors::AplusAonA(VecToCheckResult);
				//then
				Assert::AreNotEqual((*VecWIthGivenInput)[0], (*VecToCheckResult)[0]);
			}
		};
		// A + A saved on B,
		TEST_CLASS(UnitTestAddVectorsAplusAtoB)
		{
		public:
			TEST_METHOD(Should_Add_Correctly) {
				//given
				std::string::size_type sz;
				unsigned long long StringCutLength, StringCutStart;
				unsigned long long BeginingOfVecPowerOfTwo, PartOfVecPowerOfTwo;
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<std::string> VecPowerOfTwoInput;
				std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
				//when
				PowerOfTwo(VecPowerOfTwo);
				(*VecToCheckAddA).push_back(1);

				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusAonB(VecToCheckAddA, VecToCheckAddB);
					//then
					for (unsigned long long j = 0; j < (*VecToCheckAddB).size() - 1; j++) {
						StringCutStart = (*VecPowerOfTwo)[i].size() - (j + 1) * 18;
						StringCutLength = 18;
						PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckAddB)[j]);
					}
					if ((*VecToCheckAddB).size() > 1) {
						StringCutStart = 0;
						StringCutLength = (*VecPowerOfTwo)[i].size() - ((*VecToCheckAddB).size() - 1) * (18);
						BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckAddB)[(*VecToCheckAddB).size() - 1]);
					}
					AddVectors::AplusAonA(VecToCheckAddA);
				}
			}
			TEST_METHOD(Should_Add_Zero) {
				//given
				std::vector<unsigned long long> VecResultA;
				std::vector<unsigned long long>* VecToCheckResultA = &VecResultA;
				std::vector<unsigned long long> VecResultB;
				std::vector<unsigned long long>* VecToCheckResultB = &VecResultB;
				(*VecToCheckResultA).push_back(0);
				//when
				for (unsigned long long i = 0; i < 15; i++) {
					AddVectors::AplusAonB(VecToCheckResultA, VecToCheckResultB);
				}
				//then
				Assert::AreEqual((unsigned long long)0, (*VecToCheckResultB)[0]);
			}
			TEST_METHOD(Should_Add_Max_Value) {
				//given
				std::vector<unsigned long long> VecResultA;
				std::vector<unsigned long long>* VecToCheckResultA = &VecResultA;
				std::vector<unsigned long long> VecResultB;
				std::vector<unsigned long long>* VecToCheckResultB = &VecResultB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				(*VecToCheckResultA).push_back(999999999999999999);
				(*VecWIthGivenInput).push_back(999999999999999998);
				int i = 1;
				for (i = 1; i <= 10; i++) {
					(*VecToCheckResultA).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(999999999999999999);
				}
				(*VecWIthGivenInput).push_back(1);
				//when
				AddVectors::AplusAonB(VecToCheckResultA, VecToCheckResultB);
				//then
				for (int j = 0; j <= i; j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckResultB)[j]);
				}
			}
			TEST_METHOD(Should_Not_Add_Correctly) {
				//given
				std::vector<unsigned long long> VecResultA;
				std::vector<unsigned long long>* VecToCheckResultA = &VecResultA;
				std::vector<unsigned long long> VecResultB;
				std::vector<unsigned long long>* VecToCheckResultB = &VecResultB;

				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;

				(*VecToCheckResultA).push_back(1);
				(*VecWIthGivenInput).push_back(0);

				//when
				AddVectors::AplusAonB(VecToCheckResultA, VecToCheckResultB);
				//then
				Assert::AreNotEqual((*VecWIthGivenInput)[0], (*VecToCheckResultB)[0]);
			}
		};
		// A + B saved on B,
		TEST_CLASS(UnitTestAddVectorsAplusBtoB) {
		public:
			TEST_METHOD(Should_Add_Correctly_When_VectorA_Is_Equal_VectorB) {
				//given
				std::string::size_type sz;
				unsigned long long StringCutLength, StringCutStart;
				unsigned long long BeginingOfVecPowerOfTwo, PartOfVecPowerOfTwo;
				std::vector<std::string> VecPowerOfTwoInput;
				std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				//when
				PowerOfTwo(VecPowerOfTwo);
				(*VecToCheckAddA).push_back(1);
				(*VecToCheckAddB).push_back(1);
				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusBonB(VecToCheckAddA, VecToCheckAddB);
					for (unsigned long long j = 0; j < (*VecToCheckAddB).size() - 1; j++) {
						StringCutStart = (*VecPowerOfTwo)[i].size() - (j + 1) * 18;
						StringCutLength = 18;
						PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckAddB)[j]);
					}
					if ((*VecToCheckAddB).size() > 1) {
						StringCutStart = 0;
						StringCutLength = (*VecPowerOfTwo)[i].size() - ((*VecToCheckAddB).size() - 1) * (18);
						BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckAddB)[(*VecToCheckAddB).size() - 1]);
					}
					AddVectors::AplusAonA(VecToCheckAddA);
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorB_Is_Longer_Than_VectorA) {
				//given
				std::string::size_type sz;
				std::vector<std::string> VecPowerOfTwoInput;
				std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
				std::vector<unsigned long long> VecAddA, VecAddB, VecAddC;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long>* VecToCheckAddC = &VecAddC;
				unsigned long long StringCutLength, StringCutStart;
				unsigned long long PartOfVecPowerOfTwo, BeginingOfVecPowerOfTwo;
				//when
				PowerOfTwo(VecPowerOfTwo);
				(*VecToCheckAddA).push_back(2);
				(*VecToCheckAddB).push_back(2);
				(*VecToCheckAddC).push_back(2);

				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusAonA(VecToCheckAddB);
					(*VecToCheckAddC) = (*VecToCheckAddB);
					AddVectors::AplusBonB(VecToCheckAddA, VecToCheckAddC);
					for (unsigned long long j = 0; j < (*VecToCheckAddC).size() - 1; j++) {
						StringCutStart = (*VecPowerOfTwo)[i + 1].size() - (j + 1) * 18;
						StringCutLength = 18;
						PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i + 1].substr(StringCutStart, StringCutLength), &sz);
						if (j == 0)PartOfVecPowerOfTwo = PartOfVecPowerOfTwo + 2;
						//then
						Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckAddC)[j]);
					}
					if ((*VecToCheckAddB).size() > 1) {
						StringCutStart = 0;
						StringCutLength = (*VecPowerOfTwo)[i + 1].size() - ((*VecToCheckAddC).size() - 1) * (18);
						BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i + 1].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckAddC)[(*VecToCheckAddC).size() - 1]);
					}
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorA_Is_Longer_Than_VectorB) {
				//given
				std::string::size_type sz;
				std::vector<std::string> VecPowerOfTwoInput;
				std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
				std::vector<unsigned long long> VecAddA, VecAddB, VecAddC;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long>* VecToCheckAddC = &VecAddC;
				unsigned long long StringCutLength, StringCutStart;
				unsigned long long PartOfVecPowerOfTwo, BeginingOfVecPowerOfTwo;
				//when
				PowerOfTwo(VecPowerOfTwo);
				(*VecToCheckAddA).push_back(2);
				(*VecToCheckAddB).push_back(2);
				(*VecToCheckAddC).push_back(2);

				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusAonA(VecToCheckAddA);
					(*VecToCheckAddC) = (*VecToCheckAddB);
					AddVectors::AplusBonB(VecToCheckAddA, VecToCheckAddC);
					for (unsigned long long j = 0; j < (*VecToCheckAddC).size() - 1; j++) {
						StringCutStart = (*VecPowerOfTwo)[i + 1].size() - (j + 1) * 18;
						StringCutLength = 18;
						PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i + 1].substr(StringCutStart, StringCutLength), &sz);
						if (j == 0)PartOfVecPowerOfTwo = PartOfVecPowerOfTwo + 2;
						//then
						Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckAddC)[j]);
					}
					if ((*VecToCheckAddA).size() > 1) {
						StringCutStart = 0;
						StringCutLength = (*VecPowerOfTwo)[i + 1].size() - ((*VecToCheckAddC).size() - 1) * (18);
						BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i + 1].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckAddC)[(*VecToCheckAddC).size() - 1]);
					}
				}
			}
			TEST_METHOD(Should_Add_Zeros) {
				//given
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				//when
				(*VecToCheckAddA).push_back(0);
				(*VecToCheckAddB).push_back(0);
				(*VecWIthGivenInput).push_back(0);
				//then
				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusBonB(VecToCheckAddA, VecToCheckAddB);
					Assert::AreEqual((*VecWIthGivenInput)[0], (*VecToCheckAddB)[0]);
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_One_Vector_Is_Max_And_Second_Vector_Is_One) {
				//given
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				//when
				(*VecToCheckAddA).push_back(1);
				int i = 1;
				for (i = 0;i <= 100;i++) {
					(*VecToCheckAddB).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(0);
				}
				(*VecWIthGivenInput).push_back(1);
				AddVectors::AplusBonB(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
				//when
				(*VecToCheckAddA).resize(0);
				(*VecToCheckAddB).resize(0);
				(*VecToCheckAddB).push_back(1);
				for (i = 0;i <= 100;i++) {
					(*VecToCheckAddA).push_back(999999999999999999);
				}
				AddVectors::AplusBonB(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorA_And_VectorB_Is_Equal_Max_Value) {
				//given
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				(*VecToCheckAddA).push_back(999999999999999999);
				(*VecToCheckAddB).push_back(999999999999999999);
				(*VecWIthGivenInput).push_back(999999999999999998);
				int i = 1;
				for (i = 1;i <= 10;i++) {
					(*VecToCheckAddA).push_back(999999999999999999);
					(*VecToCheckAddB).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(999999999999999999);
				}
				(*VecWIthGivenInput).push_back(1);
				//when
				AddVectors::AplusBonB(VecToCheckAddA, VecToCheckAddB);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckAddB)[j]);
				}
			}
			TEST_METHOD(Should_Add_One_Empty) {
				//given
				std::vector<unsigned long long> VecAddA, VecAddB;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				//when
				(*VecToCheckAddA).resize(0);
				(*VecToCheckAddB).push_back(1);
				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusBonB(VecToCheckAddA, VecToCheckAddB);
					//then
					Assert::AreEqual((unsigned long long)1, (*VecToCheckAddB)[0]);
				}
				//when
				(*VecToCheckAddA).resize(0);
				(*VecToCheckAddA).push_back(1);
				(*VecToCheckAddB).resize(0);
				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusBonB(VecToCheckAddB, VecToCheckAddA);
					//then
					Assert::AreEqual((unsigned long long)1, (*VecToCheckAddA)[0]);
				}
			}
			TEST_METHOD(Should_Add_Both_Empty) {
				//given
				std::vector<unsigned long long> VecAddA, VecAddB;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				//when
				(*VecToCheckAddA).resize(0);
				(*VecToCheckAddB).resize(0);
				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusBonB(VecToCheckAddA, VecToCheckAddB);
					//then
					Assert::AreEqual((unsigned long long)0, (*VecToCheckAddB).size());
				}
			}
		};
		// A + A saved on A,
		// 10^RestExponent as Base, 
		TEST_CLASS(UnitTestAddVectorAplusAtoARestExponent)		{
		public:
			TEST_METHOD(Should_Rest_Exponent_Works) {
				for (int RestExponent = 1; RestExponent <= 17; RestExponent++) {
					//given 
					int* intRestExp = &RestExponent;
					std::string::size_type sz;
					std::vector<std::string> VecPowerOfTwoInput;
					std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
					std::vector<unsigned long long> VecResult;
					std::vector<unsigned long long>* VecToCheckResult = &VecResult;
					unsigned long long range, start;
					unsigned long long PartOfVecPowerOfTwo;
					unsigned long long BeginingOfVecPowerOfTwo;

					//when
					PowerOfTwo(VecPowerOfTwo);
					(*VecToCheckResult).push_back(1);
					for (unsigned long long i = 1; i < 1000; i++) {
						AddVectors::AplusAonAwithRestExponent(VecToCheckResult, intRestExp);
						for (unsigned long long j = 0; j < (*VecToCheckResult).size() - 1; j++) {
							start = (*VecPowerOfTwo)[i].size() - (j + 1) * (*intRestExp);
							range = (*intRestExp);
							PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(start, range), &sz);
							//then
							Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckResult)[j]);
						}
						if ((*VecToCheckResult).size() > 1) {
							start = 0;
							range = (*VecPowerOfTwo)[i].size() - ((*VecToCheckResult).size() - 1) * (*intRestExp);
							BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(start, range), &sz);
							//then
							Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckResult)[(*VecToCheckResult).size() - 1]);
						}
					}
				}
			}
			TEST_METHOD(Should_Not_Add_Correctly) {
				//given
				int RestExponent = 3;
				int* intRestExp = &RestExponent;

				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;

				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;

				(*VecToCheckResult).push_back(1);
				(*VecWIthGivenInput).push_back(0);

				//when
				AddVectors::AplusAonAwithRestExponent(VecToCheckResult, intRestExp);
				//then
				Assert::AreNotEqual((*VecWIthGivenInput)[0], (*VecToCheckResult)[0]);
			}
			TEST_METHOD(Should_Add_Correctly)
			{
				//given
				int RestExponent = 3;
				int* intRestExp = &RestExponent;

				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;

				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;

				(*VecToCheckResult).push_back(999);
				(*VecWIthGivenInput).push_back(232);
				(*VecWIthGivenInput).push_back(735);
				(*VecWIthGivenInput).push_back(32);

				//when
				for (unsigned long long i = 0; i < 15; i++) {
					AddVectors::AplusAonAwithRestExponent(VecToCheckResult, intRestExp);
				}
				//then
				for (unsigned long long i = 0; i < 3; i++) {
					Assert::AreEqual((*VecWIthGivenInput)[i], (*VecToCheckResult)[i]);
				}
			}
			TEST_METHOD(Should_Add_Zero)
			{
				//given
				int RestExponent = 3;
				int* intRestExp = &RestExponent;

				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;

				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;

				(*VecToCheckResult).push_back(0);
				(*VecWIthGivenInput).push_back(0);

				//when
				for (unsigned long long i = 0; i < 15; i++) {
					AddVectors::AplusAonAwithRestExponent(VecToCheckResult, intRestExp);
				}
				//then
				Assert::AreEqual((*VecWIthGivenInput)[0], (*VecToCheckResult)[0]);
			}
		};
		// A + B saved on C,
		TEST_CLASS(UnitTestAddVectorsAplusBtoC) {
		public:
			TEST_METHOD(Should_Add_Correctly_When_VectorA_Is_Equal_VectorB) {
				//given
				std::string::size_type sz;
				unsigned long long StringCutLength, StringCutStart;
				unsigned long long BeginingOfVecPowerOfTwo, PartOfVecPowerOfTwo;
				std::vector<std::string> VecPowerOfTwoInput;
				std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				//when
				PowerOfTwo(VecPowerOfTwo);
				(*VecToCheckAddA).push_back(1);
				(*VecToCheckAddB).push_back(1);
				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusBonC(VecToCheckAddA, VecToCheckAddB, VecToCheckResult);
					for (unsigned long long j = 0; j < (*VecToCheckResult).size() - 1; j++) {
						StringCutStart = (*VecPowerOfTwo)[i].size() - (j + 1) * 18;
						StringCutLength = 18;
						PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckResult)[j]);
					}
					if ((*VecToCheckResult).size() > 1) {
						StringCutStart = 0;
						StringCutLength = (*VecPowerOfTwo)[i].size() - ((*VecToCheckResult).size() - 1) * (18);
						BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckResult)[(*VecToCheckResult).size() - 1]);
					}
					AddVectors::AplusAonA(VecToCheckAddA);
					AddVectors::AplusAonA(VecToCheckAddB);
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorB_Is_Longer_Than_VectorA) {
				//given
				std::string::size_type sz;
				std::vector<std::string> VecPowerOfTwoInput;
				std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				unsigned long long StringCutLength, StringCutStart;
				unsigned long long PartOfVecPowerOfTwo, BeginingOfVecPowerOfTwo;
				//when
				PowerOfTwo(VecPowerOfTwo);
				(*VecToCheckAddA).push_back(2);
				(*VecToCheckAddB).push_back(2);

				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusAonA(VecToCheckAddB);
					AddVectors::AplusBonC(VecToCheckAddA, VecToCheckAddB, VecToCheckResult);
					for (unsigned long long j = 0; j < (*VecToCheckResult).size() - 1; j++) {
						StringCutStart = (*VecPowerOfTwo)[i + 1].size() - (j + 1) * 18;
						StringCutLength = 18;
						PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i + 1].substr(StringCutStart, StringCutLength), &sz);
						if (j == 0)PartOfVecPowerOfTwo = PartOfVecPowerOfTwo + 2;
						//then
						Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckResult)[j]);
					}
					if ((*VecToCheckResult).size() > 1) {
						StringCutStart = 0;
						StringCutLength = (*VecPowerOfTwo)[i + 1].size() - ((*VecToCheckResult).size() - 1) * (18);
						BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i + 1].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckResult)[(*VecToCheckResult).size() - 1]);
					}
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorA_Is_Longer_Than_VectorB) {
				//given
				std::string::size_type sz;
				std::vector<std::string> VecPowerOfTwoInput;
				std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				unsigned long long StringCutLength, StringCutStart;
				unsigned long long PartOfVecPowerOfTwo, BeginingOfVecPowerOfTwo;
				//when
				PowerOfTwo(VecPowerOfTwo);
				(*VecToCheckAddA).push_back(2);
				(*VecToCheckAddB).push_back(1);

				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusAonA(VecToCheckAddA);
					AddVectors::AplusBonC(VecToCheckAddA, VecToCheckAddB, VecToCheckResult);
					for (unsigned long long j = 0; j < (*VecToCheckResult).size() - 1; j++) {
						StringCutStart = (*VecPowerOfTwo)[i + 1].size() - (j + 1) * 18;
						StringCutLength = 18;
						PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i + 1].substr(StringCutStart, StringCutLength), &sz);
						if (j == 0)PartOfVecPowerOfTwo = PartOfVecPowerOfTwo + 1;
						//then
						Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckResult)[j]);
					}
					if ((*VecToCheckResult).size() > 1) {
						StringCutStart = 0;
						StringCutLength = (*VecPowerOfTwo)[i + 1].size() - ((*VecToCheckResult).size() - 1) * (18);
						BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i + 1].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckResult)[(*VecToCheckResult).size() - 1]);
					}
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorA_Is_Equal_Zero) {
				//given
				std::string::size_type sz;
				unsigned long long StringCutLength, StringCutStart;
				unsigned long long BeginingOfVecPowerOfTwo, PartOfVecPowerOfTwo;
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				std::vector<std::string> VecPowerOfTwoInput;
				std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
				//when
				PowerOfTwo(VecPowerOfTwo);
				(*VecToCheckAddA).push_back(0);
				(*VecToCheckAddB).push_back(1);
				(*VecToCheckResult).push_back(0);
				//then
				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusAonA(VecToCheckAddB);
					AddVectors::AplusBonC(VecToCheckAddA, VecToCheckAddB, VecToCheckResult);
					for (unsigned long long j = 0; j < (*VecToCheckResult).size() - 1; j++) {
						StringCutStart = (*VecPowerOfTwo)[i].size() - (j + 1) * 18;
						StringCutLength = 18;
						PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckResult)[j]);
					}
					if ((*VecToCheckResult).size() > 1) {
						StringCutStart = 0;
						StringCutLength = (*VecPowerOfTwo)[i].size() - ((*VecToCheckResult).size() - 1) * (18);
						BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckResult)[(*VecToCheckResult).size() - 1]);
					}
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorB_Is_Equal_Zero) {
				//given
				std::string::size_type sz;
				unsigned long long StringCutLength, StringCutStart;
				unsigned long long BeginingOfVecPowerOfTwo, PartOfVecPowerOfTwo;
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				std::vector<std::string> VecPowerOfTwoInput;
				std::vector<std::string>* VecPowerOfTwo = &VecPowerOfTwoInput;
				//when
				PowerOfTwo(VecPowerOfTwo);
				(*VecToCheckAddA).push_back(1);
				(*VecToCheckAddB).push_back(0);
				(*VecToCheckResult).push_back(0);
				//then
				for (unsigned long long i = 1; i < 1000; i++) {
					AddVectors::AplusAonA(VecToCheckAddB);
					AddVectors::AplusBonC(VecToCheckAddA, VecToCheckAddB, VecToCheckResult);
					for (unsigned long long j = 0; j < (*VecToCheckResult).size() - 1; j++) {
						StringCutStart = (*VecPowerOfTwo)[i].size() - (j + 1) * 18;
						StringCutLength = 18;
						PartOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(PartOfVecPowerOfTwo, (*VecToCheckResult)[j]);
					}
					if ((*VecToCheckResult).size() > 1) {
						StringCutStart = 0;
						StringCutLength = (*VecPowerOfTwo)[i].size() - ((*VecToCheckResult).size() - 1) * (18);
						BeginingOfVecPowerOfTwo = std::stoll((*VecPowerOfTwo)[i].substr(StringCutStart, StringCutLength), &sz);
						//then
						Assert::AreEqual(BeginingOfVecPowerOfTwo, (*VecToCheckResult)[(*VecToCheckResult).size() - 1]);
					}
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorA_And_VectorB_Is_Equal_Zero) {
				//given
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				//when
				(*VecToCheckAddA).push_back(0);
				(*VecToCheckAddB).push_back(0);
				(*VecWIthGivenInput).push_back(0);
				//then
				for (unsigned long long i = 1; i < 100; i++) {
					AddVectors::AplusBonC(VecToCheckAddA, VecToCheckAddB, VecToCheckResult);
					Assert::AreEqual((*VecWIthGivenInput)[0], (*VecToCheckResult)[0]);
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_VectorA_And_VectorB_Is_Equal_Max_Value) {
				//given
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				(*VecToCheckAddA).push_back(999999999999999999);
				(*VecToCheckAddB).push_back(999999999999999999);
				(*VecWIthGivenInput).push_back(999999999999999998);
				int i = 1;
				for (i = 1;i <= 10;i++) {
					(*VecToCheckAddA).push_back(999999999999999999);
					(*VecToCheckAddB).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(999999999999999999);
				}
				(*VecWIthGivenInput).push_back(1);
				//when
				AddVectors::AplusBonC(VecToCheckAddA, VecToCheckAddB, VecToCheckResult);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckResult)[j]);
				}
			}
			TEST_METHOD(Should_Add_Correctly_When_One_Vector_Is_Max_And_Second_Vector_Is_One) {
				//given
				std::vector<unsigned long long> VecAddA;
				std::vector<unsigned long long>* VecToCheckAddA = &VecAddA;
				std::vector<unsigned long long> VecAddB;
				std::vector<unsigned long long>* VecToCheckAddB = &VecAddB;
				std::vector<unsigned long long> VecInput;
				std::vector<unsigned long long>* VecWIthGivenInput = &VecInput;
				std::vector<unsigned long long> VecResult;
				std::vector<unsigned long long>* VecToCheckResult = &VecResult;
				//when
				(*VecToCheckAddA).push_back(1);
				int i = 1;
				for (i = 0;i <= 100;i++) {
					(*VecToCheckAddB).push_back(999999999999999999);
					(*VecWIthGivenInput).push_back(0);
				}
				(*VecWIthGivenInput).push_back(1);
				AddVectors::AplusBonC(VecToCheckAddA, VecToCheckAddB, VecToCheckResult);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckResult)[j]);
				}
				//when
				(*VecToCheckAddA).resize(0);
				(*VecToCheckAddB).resize(0);
				(*VecToCheckAddB).push_back(1);
				for (i = 0;i <= 100;i++) {
					(*VecToCheckAddA).push_back(999999999999999999);
				}
				AddVectors::AplusBonC(VecToCheckAddA, VecToCheckAddB, VecToCheckResult);
				//then
				for (int j = 0;j <= i;j++) {
					Assert::AreEqual((*VecWIthGivenInput)[j], (*VecToCheckResult)[j]);
				}
			}
		};
	}
}