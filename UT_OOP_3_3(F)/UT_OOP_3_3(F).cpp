#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_3_3(F)/Angle.cpp"
#include "../OOP_3_3(F)/TriangleC.cpp"
#include "../OOP_3_3(F)/TriangleO.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTOOP33F
{
	TEST_CLASS(UTOOP33F)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double epsilon = 0.000001;

			TriangleO a(3, 4, 5);
			Assert::IsTrue(fabs(90. - a.GetC().ToDegrees()) < epsilon);
			Assert::AreEqual(12., a.Perimeter());
			Assert::AreEqual("right triangle", a.Type().c_str());

			TriangleC b(3, 3, 3);
			Assert::IsTrue(fabs(60. - b.GetC().ToDegrees()) < epsilon);
			Assert::AreEqual(9., b.Perimeter());
			Assert::AreEqual("equilateral", b.Type().c_str());
		}
	};
}
