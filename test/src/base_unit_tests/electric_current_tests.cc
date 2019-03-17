#include <catch.hpp>

#include <SI/electric_current.h>

using namespace SI::literals;

/// @todo adjust test names
TEST_CASE("A returns ratio 1 to 1") {
  constexpr auto one = 1_A;
  STATIC_REQUIRE(std::ratio_equal<std::ratio<1>, decltype(one)::ratio>::value);

  constexpr auto one_f = 1.0_A;
  STATIC_REQUIRE(
      std::ratio_equal<std::ratio<1>, decltype(one_f)::ratio>::value);
}

TEST_CASE("mA returns ratio 1 to 1000") {
  constexpr auto one = 1_mA;
  STATIC_REQUIRE(std::ratio_equal<std::milli, decltype(one)::ratio>::value);

  constexpr auto one_f = 1.0_mA;
  STATIC_REQUIRE(std::ratio_equal<std::milli, decltype(one_f)::ratio>::value);
}

TEST_CASE("kA returns ratio 1000 to 1") {
  constexpr auto one = 1_kA;
  STATIC_REQUIRE(std::ratio_equal<std::kilo, decltype(one)::ratio>::value);

  constexpr auto one_f = 1.0_kA;
  STATIC_REQUIRE(std::ratio_equal<std::kilo, decltype(one_f)::ratio>::value);
}