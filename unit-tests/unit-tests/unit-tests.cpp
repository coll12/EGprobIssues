#include "pch.h"
#include "CppUnitTest.h"
#include "C:/Users/Игорь Образцов/source/repos/3_1_C++/3_1_C++/small_number.h" // Убедитесь, что путь верный

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SmallNumberTests
{
    TEST_CLASS(SmallNumberTest)
    {
    public:
        // Тест 1: Проверка инициализации и преобразования в int
        TEST_METHOD(InitAndToIntValid)
        {
            SmallNumber num;
            num.Init(1, 2, 3);
            Assert::AreEqual(123, num.toInt());
        }

        // Тест 2: Невалидные цифры должны заменяться на 0
        TEST_METHOD(InitInvalidDigits)
        {
            SmallNumber num;
            num.Init(10, -1, 5);
            Assert::AreEqual(5, num.toInt());
        }

        // Тест 3: Валидация корректного числа не должна вызывать исключение
        TEST_METHOD(ValidateNumberNoThrow)
        {
            SmallNumber num;
            num.Init(1, 2, 3);
            num.validateNumber(); // Если исключение будет, тест провалится
        }

        // Тест 4: Проверка выброса ZeroFirstDigitException для числа 057
        TEST_METHOD(ValidateNumberThrowsZeroFirstDigit)
        {
            SmallNumber num;
            num.Init(0, 5, 7);
            auto func = [&num] { num.validateNumber(); };
            Assert::ExpectException<ZeroFirstDigitException>(func);
        }

        // Тест 5: Проверка выброса ZeroFirstTwoDigitsException для числа 009
        TEST_METHOD(ValidateNumberThrowsZeroFirstTwoDigits)
        {
            SmallNumber num;
            num.Init(0, 0, 9);
            auto func = [&num] { num.validateNumber(); };
            Assert::ExpectException<ZeroFirstTwoDigitsException>(func);
        }

        // Тест 6: Сложение двух трёхзначных чисел
        TEST_METHOD(AddNormal)
        {
            SmallNumber a, b;
            a.Init(1, 2, 3);
            b.Init(4, 5, 6);
            SmallNumber result = add(a, b);
            Assert::AreEqual(579, result.toInt());
        }

        // Тест 7: Сложение с переполнением (500 + 500 = 0)
        TEST_METHOD(AddOverflowToZero)
        {
            SmallNumber a, b;
            a.Init(5, 0, 0);
            b.Init(5, 0, 0);
            SmallNumber result = add(a, b);
            Assert::AreEqual(0, result.toInt());
        }

        // Тест 8: Сложение с предупреждением (012 + 100 = 112)
        TEST_METHOD(AddWithZeroFirstDigitWarning)
        {
            SmallNumber a, b;
            a.Init(0, 1, 2);
            b.Init(1, 0, 0);
            SmallNumber result = add(a, b);
            Assert::AreEqual(112, result.toInt());
        }

        // Тест 9: Создание числа из целого
        TEST_METHOD(CreateFromIntValid)
        {
            SmallNumber num = createFromInt(345);
            Assert::AreEqual(345, num.toInt());
        }

        // Тест 10: Проверка проброса исключения из processNumber
        TEST_METHOD(ProcessNumberThrowsException)
        {
            SmallNumber num;
            num.Init(0, 1, 2);
            auto func = [&num] { processNumber(num); };
            Assert::ExpectException<ZeroFirstDigitException>(func);
        }
    };
}