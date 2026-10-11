#include "pch.h"
#include "CppUnitTest.h"
#include "../LR1.4OOP/MySet.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySetUnitTests
{
    TEST_CLASS(MySetTests)
    {
    public:
        TEST_METHOD(TestUnionWith)
        {
            MySet setA, setB;
            setA.Init(); setB.Init();
            setA.add(1); setA.add(2);
            setB.add(2); setB.add(3);

            MySet result = setA.unionWith(setB);

            Assert::AreEqual(1, result.getElement(1));
            Assert::AreEqual(1, result.getElement(2));
            Assert::AreEqual(1, result.getElement(3));
            Assert::AreEqual(0, result.getElement(4)); // 4 немає в жодній множині
        }

        TEST_METHOD(TestIntersectWith)
        {
            MySet setA, setB;
            setA.Init(); setB.Init();
            setA.add(5); setA.add(10);
            setB.add(10); setB.add(15);

            MySet result = setA.intersectWith(setB);
            Assert::AreEqual(0, result.getElement(5));
            Assert::AreEqual(1, result.getElement(10));
            Assert::AreEqual(0, result.getElement(15));
        }
    };
}