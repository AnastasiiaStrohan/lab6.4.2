#include "pch.h"
#include "CppUnitTest.h"
#include "../lb6.4.2/lb6.4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest642
{
	TEST_CLASS(UnitTest642)
	{
	public:
		double* testCreateArray(int n, const std::vector<double>& values) {
			double* arr = new double[n];
			for (int i = 0; i < n; i++) {
				arr[i] = values[i];
			}
			return arr;
		}

		TEST_METHOD(TestMethod1)
		{
			int n = 3;
			std::vector<double> inputValues = { 1.1, -2.2, 3.3 };
			double expectedArr[] = { 1.1, -2.2, 3.3 };

			
			double* arr = testCreateArray(n, inputValues);

			
			for (int i = 0; i < n; i++) {
				Assert::AreEqual(expectedArr[i], arr[i], 0.0001, (L"Element mismatch at index " + std::to_wstring(i)).c_str());
			}

			
			delete[] arr;
		}
	};
}
