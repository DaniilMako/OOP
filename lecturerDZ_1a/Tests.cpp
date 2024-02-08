#include "tests.h"


void TestDefaultConstructor() {
    const BigInt defaultConstructed;
    const BigInt expected(0);
    ASSERT_EQUAL(defaultConstructed, expected);
}

void TestOperatorPlus() {
    {
        BigInt a("918739818302937492383485843093546546"), b("938475834792384023984892374"), c;
        c = a + b;
        const BigInt expected("918739819241413327175869867078438920");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("-918739818302937492383485843093546546"), b("-938475834792384023984892374"), c;
        c = a + b;
        const BigInt expected("-918739819241413327175869867078438920");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a(0), b(0), c;
        c = a + b;
        const BigInt expected(0);
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a(-1), b(1), c;
        c = a + b;
        const BigInt expected(0);
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("918739818302937492383485843093546546"), b("-938475834792384023984892374"), c;
        c = a + b;
        const BigInt expected("918739817364461657591101819108654172");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("-918739818302937492383485843093546546"), b("938475834792384023984892374"), c;
        c = a + b;
        const BigInt expected("-918739817364461657591101819108654172");
        ASSERT_EQUAL(c, expected);
    }

}
void TestOperatorMinus() {
    {
        BigInt a("918739818302937492383485843093546546"), b("938475834792384023984892374"), c;
        c = a - b;
        const BigInt expected("918739817364461657591101819108654172");
        ASSERT_EQUAL(c, expected, "Operator - does not work1");
    }
    {
        BigInt a("-918739818302937492383485843093546546"), b("-938475834792384023984892374"), c;
        c = a - b;
        const BigInt expected("-918739817364461657591101819108654172");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a(0), b(0), c;
        c = a - b;
        const BigInt expected(0);
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a(-1), b(-1), c;
        c = a - b;
        const BigInt expected(0);
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("918739818302937492383485843093546546"), b("-938475834792384023984892374"), c;
        c = a - b;
        const BigInt expected("918739819241413327175869867078438920");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("-918739818302937492383485843093546546"), b("938475834792384023984892374"), c;
        c = a - b;
        const BigInt expected("-918739819241413327175869867078438920");
        ASSERT_EQUAL(c, expected);
    }

}
void TestOperatorMultiply() {
    {
        BigInt a("99999999999999999999999999999999918739818302937492383485843093546546"), b("99999999999999999999999999999999938475834792384023984892374"), c;
        c = a * b;
        const BigInt expected("9999999999999999999999999999999985721565309532151636837821709354659599464843530965668112790999929817936358831857029119769440204");
        ASSERT_EQUAL(c, expected, "Operator * does not work0");
    }
    {
        BigInt a("918739818302937492383485843093546546"), b("938475834792384023984892374"), c;
        c = a * b;
        const BigInt expected("862215117938852482036491008093476363936358831857029119769440204");
        ASSERT_EQUAL(c, expected, "Operator * does not work1");
    }
    {
        BigInt a("-918739818302937492383485843093546546"), b("-938475834792384023984892374"), c;
        c = a * b;
        const BigInt expected("862215117938852482036491008093476363936358831857029119769440204");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a(0), b(1), c;
        c = a * b;
        const BigInt expected(0);
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a(-1), b(1), c;
        c = a * b;
        const BigInt expected(-1);
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("918739818302937492383485843093546546"), b("-938475834792384023984892374"), c;
        c = a * b;
        const BigInt expected("-862215117938852482036491008093476363936358831857029119769440204");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("-918739818302937492383485843093546546"), b("938475834792384023984892374"), c;
        c = a * b;
        const BigInt expected("-862215117938852482036491008093476363936358831857029119769440204");
        ASSERT_EQUAL(c, expected);
    }
}
void TestOperatorDivide() {
    {
        BigInt a("918739818302937492383485843093546546"), b("938475834792384023984892374"), c;
        c = a / b;
        const BigInt expected("978970138");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("-918739818302937492383485843093546546"), b("-938475834792384023984892374"), c;
        c = a / b;
        const BigInt expected("978970138");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a(0), b(1), c;
        c = a / b;
        const BigInt expected(0);
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a(-1), b(1), c;
        c = a / b;
        const BigInt expected(-1);
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("918739818302937492383485843093546546"), b("-938475834792384023984892374"), c;
        c = a / b;
        const BigInt expected("-978970138");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("-918739818302937492383485843093546546"), b("938475834792384023984892374"), c;
        c = a / b;
        const BigInt expected("-978970138");
        ASSERT_EQUAL(c, expected);
    }

}
void TestOperatorRemainder() {
    {
        BigInt a("918739818302937492383485843093546546"), b("938475834792384023984892374"), c;
        c = a % b;
        const BigInt expected("806572103074000445803618934");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("-918739818302937492383485843093546546"), b("-938475834792384023984892374"), c;
        c = a % b;
        const BigInt expected("-806572103074000445803618934");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a(0), b(1), c;
        c = a % b;
        const BigInt expected(0);
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a(-1), b(1), c;
        c = a % b;
        const BigInt expected(0);
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("918739818302937492383485843093546546"), b("-938475834792384023984892374"), c;
        c = a % b;
        const BigInt expected("806572103074000445803618934");
        ASSERT_EQUAL(c, expected);
    }
    {
        BigInt a("-918739818302937492383485843093546546"), b("938475834792384023984892374"), c;
        c = a % b;
        const BigInt expected("-806572103074000445803618934");
        ASSERT_EQUAL(c, expected);
    }

}


void TestAll() { // функция, вызывающая все тесты
    TestRunner tr;
    RUN_TEST(tr, TestOperatorPlus);
    RUN_TEST(tr, TestOperatorMinus);
    RUN_TEST(tr, TestOperatorMultiply);
    RUN_TEST(tr, TestOperatorDivide);
    RUN_TEST(tr, TestOperatorRemainder);
    RUN_TEST(tr, TestDefaultConstructor);
}