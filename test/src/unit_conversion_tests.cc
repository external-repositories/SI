

#include <catch.hpp>

#include <SI/conversions.h>

// stream operator needed to expand in test output
using namespace SI::literals;

TEST_CASE("GIVEN values electric current (I) and a time (T) WHEN multiplied "
          "THEN result is electric charge (Q)") {
  constexpr auto current = 1_A;
  constexpr auto time = 1_s;
  constexpr auto result = current * time;
  constexpr auto result_commutative = time * current;

  static_assert(
      std::is_same<decltype(result),
                   const SI::electric_charge_t<1, std::ratio<1>>>::value,
      "Result is electric charge");
  static_assert(
      std::is_same<decltype(result_commutative),
                   const SI::electric_charge_t<1, std::ratio<1>>>::value,
      "Result is electric charge");
  static_assert(result == result_commutative,
                "Commutative operations are equal");
}

TEST_CASE("GIVEN values for I and T AND ratio is the same WHEN multiplied THEN "
          "resulting value is I.raw_value() * T.raw_value()") {
  constexpr auto current = 1_A;
  constexpr auto time = 2_s;
  constexpr auto result = current * time;
  constexpr auto result_commutative = time * current;

  static_assert(result.raw_value() == 2, "result is calculated correctly");
  static_assert(result_commutative.raw_value() == 2,
                "result is calculated correctly");
}

TEST_CASE("GIVEN values for I and T AND ratio is not the same WHEN multiplied "
          "THEN resulting ratio is same as lhs") {
  constexpr auto current = 1000_mA;
  constexpr auto t = 2_s;
  constexpr auto result = current * t;
  constexpr auto result_commutative = t * current;

  static_assert(std::ratio_equal<decltype(result)::ratio,
                                 decltype(current)::ratio>::value,
                "Ratio is the same");

  static_assert(result.raw_value() == 2000, "value is calculated in "
                                            "millis");

  static_assert(std::ratio_equal<decltype(result_commutative)::ratio,
                                 decltype(t)::ratio>::value,
                "Ratio is the same");

  static_assert(result_commutative.raw_value() == 2,
                "value is calculated in ratio 1");

  static_assert(result_commutative == result,
                "Commutative operations are equal");
}

TEST_CASE("GIVEN electric charge Q with ratio<1> WHEN divided by electric "
          "current I with ratio<1> THEN "
          "result is time t with ratio <1>") {
  constexpr auto charge = 8_C;
  constexpr auto current = 4_A;
  constexpr auto result = charge / current;

  static_assert(
      std::is_same<decltype(result), const SI::time_t<1, std::ratio<1>>>::value,
      "Result is of type t");

  static_assert(result.raw_value() == 2, "Is 2");
}

TEST_CASE("GIVEN electric charge Q with ratio<1000,1> WHEN divided by electric "
          "current I with ratio<1> THEN "
          "result is time t with ratio <1,1> (s)") {
  constexpr auto charge = 8_MC;
  constexpr auto current = 4000_A;
  constexpr auto result = charge / current;

  static_assert(
      std::is_same<decltype(result), const SI::time_t<1, std::ratio<1>>>::value,
      "Result is of type t");
  static_assert(result.raw_value() == 2000, "Is 2000");
}