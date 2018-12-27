

#include <catch.hpp>

#include <SI/conversions.h>

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