#include "pch.h"
#include "Foo.h"
#include "ToStringSpecializations.h"
#include "vec4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Renderer;
using namespace std;
using namespace std::string_literals;


namespace UnitTestLibraryDesktop
{
	TEST_CLASS(Vec4Tests)
	{
	public:

		TEST_METHOD_INITIALIZE(Initialize)
		{
#if defined(_DEBUG)
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF);
			_CrtMemCheckpoint(&_startMemState);
#endif
		}

		TEST_METHOD_CLEANUP(Cleanup)
		{
#if defined(_DEBUG)
			_CrtMemState endMemState, diffMemState;
			_CrtMemCheckpoint(&endMemState);
			if (_CrtMemDifference(&diffMemState, &_startMemState, &endMemState))
			{
				_CrtMemDumpStatistics(&diffMemState);
				Assert::Fail(L"Memory Leaks!");
			}
#endif
		}

		TEST_METHOD(Constructor)
		{
			Vec4 test(1.0, 2.0, 3.0, 4.0);

			Assert::AreEqual(test.x(), (float)1.0);
			Assert::AreEqual(test.y(), (float)2.0);
			Assert::AreEqual(test.z(), (float)3.0);
			Assert::AreEqual(test.a(), (float)4.0);

		}

		TEST_METHOD(Negation)
		{
			Vec4 test(1.0, 2.0, 3.0, 4.0);
			Vec4 negTest = -test;

			float negFloat = -1.0;

			Assert::AreEqual(negTest.x(), negFloat);
			Assert::AreEqual(negTest.y(), (negFloat* 2));
			Assert::AreEqual(negTest.z(), (negFloat * 3));
			Assert::AreEqual(negTest.a(), (negFloat * 4));

		}

		TEST_METHOD(At)
		{
			Vec4 test(1.0, 2.0, 3.0, 4.0);
			

			Assert::AreEqual(test.x(), test[0]);
			Assert::AreEqual(test.y(), test[1]);
			Assert::AreEqual(test.z(), test[2]);
			Assert::AreEqual(test.a(), test[3]);

		}

		TEST_METHOD(PlusEquals)
		{
			Vec4 test(1.0, 2.0, 3.0, 4.0);
			Vec4 test2(1.0, 2.0, 3.0, 4.0);

			test += test2;

			Assert::AreEqual(test.x(), (float)2.0);
			Assert::AreEqual(test.y(), (float)4.0);
			Assert::AreEqual(test.z(), (float)6.0);
			Assert::AreEqual(test.a(), (float)8.0);

		}

		TEST_METHOD(SelfScalarMultiplication)
		{
			Vec4 test(1.0, 2.0, 3.0, 4.0);
			
			test *= 2;

			Assert::AreEqual(test.x(), (float)2.0);
			Assert::AreEqual(test.y(), (float)4.0);
			Assert::AreEqual(test.z(), (float)6.0);
			Assert::AreEqual(test.a(), (float)8.0);

		}

		

		TEST_METHOD(SelfScalarDivision)
		{
			Vec4 test(4.0, 8.0, 12.0, 16.0);

			test /= 2;

			Assert::AreEqual(test.x(), (float)2.0);
			Assert::AreEqual(test.y(), (float)4.0);
			Assert::AreEqual(test.z(), (float)6.0);
			Assert::AreEqual(test.a(), (float)8.0);

		}

		TEST_METHOD(LengthSquared)
		{
			Vec4 test(1.0, 2.0, 3.0, 4.0);
			Assert::AreEqual(test.length_squared(), (float)30.0);
		}


		TEST_METHOD(Length)
		{
			Vec4 test(1.0, 2.0, 3.0, 4.0);
			float sqRoot = sqrt(30.0);
			Assert::AreEqual(test.length(), sqRoot);
		}

		TEST_METHOD(Output)
		{
		/*	Vec4 test(1.0, 2.0, 3.0, 4.0);
			ostream& testcout();
			testcout << test;
			Assert::AreEqual(testcout, "1.0 2.0 3.0 4.0");*/
		}

		TEST_METHOD(Addition)
		{

			Vec4 test1(1.0, 2.0, 3.0, 4.0);
			Vec4 test2(3.0, 4.0, 5.0, 6.0);

			Vec4 test = test2 + test1;

			Assert::AreEqual(test.x(), (float)4.0);
			Assert::AreEqual(test.y(), (float)6.0);
			Assert::AreEqual(test.z(), (float)8.0);
			Assert::AreEqual(test.a(), (float)10.0);

		}

		TEST_METHOD(Subtraction)
		{

			Vec4 test1(1.0, 2.0, 3.0, 4.0);
			Vec4 test2(3.0, 4.0, 5.0, 6.0);

			Vec4 test = test2 - test1;

			Assert::AreEqual(test.x(), (float)2.0);
			Assert::AreEqual(test.y(), (float)2.0);
			Assert::AreEqual(test.z(), (float)2.0);
			Assert::AreEqual(test.a(), (float)2.0);

		}

		TEST_METHOD(Multiplication)
		{

			Vec4 test1(1.0, 2.0, 3.0, 4.0);
			Vec4 test2(3.0, 4.0, 5.0, 6.0);

			Vec4 test = test2 * test1;

			Assert::AreEqual(test.x(), (float)3.0);
			Assert::AreEqual(test.y(), (float)8.0);
			Assert::AreEqual(test.z(), (float)15.0);
			Assert::AreEqual(test.a(), (float)24.0);

		}

		TEST_METHOD(ScalarMultiplication)
		{

			Vec4 test1(1.0, 2.0, 3.0, 4.0);
			float scalar = 2;

			Vec4 output1 = scalar * test1;
			Vec4 output2 = test1* scalar;

			Assert::AreEqual(output1.x(), (float)2.0);
			Assert::AreEqual(output1.y(), (float)4.0);
			Assert::AreEqual(output1.z(), (float)6.0);
			Assert::AreEqual(output1.a(), (float)8.0);

			Assert::AreEqual(output2.x(), (float)2.0);
			Assert::AreEqual(output2.y(), (float)4.0);
			Assert::AreEqual(output2.z(), (float)6.0);
			Assert::AreEqual(output2.a(), (float)8.0);

		}

		TEST_METHOD(Division)
		{

			Vec4 test1(4.0, 6.0, 8.0, 10.0);
			float scalar = 2;

			Vec4 output1 = test1/scalar;

			Assert::AreEqual(output1.x(), (float)2.0);
			Assert::AreEqual(output1.y(), (float)3.0);
			Assert::AreEqual(output1.z(), (float)4.0);
			Assert::AreEqual(output1.a(), (float)5.0);

			
		}

		TEST_METHOD(Dot)
		{

			const Vec4 test1(4.0, 6.0, 8.0, 5.0);
			const Vec4 test2(1.0, 2.0, 3.0, 4.0);
		

			float output1 = dot(test1, test2);

			Assert::AreEqual(output1, (float)60);

		}
		

		TEST_METHOD(Cross)
		{
			const Vec4 test1(4.0, 6.0, 8.0, 5.0);
			const Vec4 test2(1.0, 2.0, 3.0, 4.0);


			Vec4 output1 = cross(test1, test2);

			Assert::AreEqual(output1.x(), (float)2.0);
			Assert::AreEqual(output1.y(), (float)-4.0);
			Assert::AreEqual(output1.z(), (float)2.0);
			Assert::AreEqual(output1.a(), (float)4.5);

		}


		TEST_METHOD(UnitVector)
		{
			const Vec4 test1(1.0, 2.0, 3.0, 4.0);
			
			Vec4 output1 = unit_vector(test1 );
			float x = 1.0 / sqrtf(30.0);
			float y = 2.0 / sqrtf(30.0);
			float z = 3.0 / sqrtf(30.0);
			float a = 4.0 / sqrtf(30.0);

			Assert::AreEqual(output1.x(), x);
			Assert::AreEqual(output1.y(), y);
		//	Assert::AreEqual(output1.z(),(float) (3.0 / sqrtf(30.0)));
			Assert::AreEqual(output1.a(), a);

		}


	private:
		static _CrtMemState _startMemState;
	};

	_CrtMemState Vec4Tests::_startMemState;
}

