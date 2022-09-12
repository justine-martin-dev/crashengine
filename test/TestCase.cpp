#include <catch2/catch_test_macros.hpp>

#include "CrashEngine/utiliy.hpp"
#include "CrashEngine/math/vec3.hpp"

static int Factorial( int number ) {
   //return number <= 1 ? number : Factorial(number - 1) * number;  // fail
 return number <= 1 ? 1      : Factorial(number - 1) * number;  // pass
}

TEST_CASE( "Factorial of 0 is 1 (fail)", "[single-file]" ) {
    REQUIRE(Factorial(0) == 1);
}

TEST_CASE( "Factorials of 1 and higher are computed (pass)", "[single-file]" ) {
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE( "Types are detected and effectively associated with an enum", "[typing]" ) {
    REQUIRE( crashengine::getDataType('a')               == crashengine::DataType::BYTE );
    REQUIRE( crashengine::getDataType(0.0d)              == crashengine::DataType::DOUBLE );
    REQUIRE( crashengine::getDataType(0.0f)              == crashengine::DataType::FLOAT );
    REQUIRE( crashengine::getDataType(int(0))            == crashengine::DataType::INT );
    REQUIRE( crashengine::getDataType(short(0))          == crashengine::DataType::SHORT );
    REQUIRE( crashengine::getDataType((unsigned char)0)  == crashengine::DataType::UBYTE );
    REQUIRE( crashengine::getDataType((unsigned int)0)   == crashengine::DataType::UINT );
    REQUIRE( crashengine::getDataType((unsigned short)0) == crashengine::DataType::USHORT );
}
