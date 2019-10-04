#include <catch.hpp>

#include <SI/solid_angle.h>
#include <SI/stream.h>
#include <sstream>

using namespace SI::literals;
TEST_CASE("GIVEN a value WHEN constructed with literal _asr THEN result is a "
          "solid angle type AND ratio 1 to 10^15") {
  constexpr auto one = 1_asr;
  STATIC_REQUIRE(
      std::is_same<decltype(one),
                   const SI::solid_angle_t<int64_t, std::atto>>::value);

  constexpr auto one_f = 1.0_asr;
  STATIC_REQUIRE(
      std::is_same<decltype(one_f),
                   const SI::solid_angle_t<long double, std::atto>>::value);
}

TEST_CASE("GIVEN a value WHEN constructed with literal _fsr THEN result is a "
          "solid angle type AND ratio 1 to 10^15") {
  constexpr auto one = 1_fsr;
  STATIC_REQUIRE(
      std::is_same<decltype(one),
                   const SI::solid_angle_t<int64_t, std::femto>>::value);

  constexpr auto one_f = 1.0_fsr;
  STATIC_REQUIRE(
      std::is_same<decltype(one_f),
                   const SI::solid_angle_t<long double, std::femto>>::value);
}

TEST_CASE("GIVEN a value WHEN constructed with literal _psr THEN result is a "
          "solid angle type AND ratio 1 to 10^12") {
  constexpr auto one = 1_psr;
  STATIC_REQUIRE(
      std::is_same<decltype(one),
                   const SI::solid_angle_t<int64_t, std::pico>>::value);

  constexpr auto one_f = 1.0_psr;
  STATIC_REQUIRE(
      std::is_same<decltype(one_f),
                   const SI::solid_angle_t<long double, std::pico>>::value);
}

TEST_CASE("GIVEN a value WHEN constructed with literal _nsr THEN result is a "
          "solid angle type AND ratio 1 to 10^9") {
  constexpr auto one = 1_nsr;
  STATIC_REQUIRE(
      std::is_same<decltype(one),
                   const SI::solid_angle_t<int64_t, std::nano>>::value);

  constexpr auto one_f = 1.0_nsr;
  STATIC_REQUIRE(
      std::is_same<decltype(one_f),
                   const SI::solid_angle_t<long double, std::nano>>::value);
}

TEST_CASE("GIVEN a value WHEN constructed with literal _usr THEN result is a "
          "solid angle type AND ratio 1 to 10^6") {
  constexpr auto one = 1_usr;
  STATIC_REQUIRE(
      std::is_same<decltype(one),
                   const SI::solid_angle_t<int64_t, std::micro>>::value);

  constexpr auto one_f = 1.0_usr;
  STATIC_REQUIRE(
      std::is_same<decltype(one_f),
                   const SI::solid_angle_t<long double, std::micro>>::value);
}

TEST_CASE("GIVEN a value WHEN constructed with literal _msr THEN result is a "
          "solid angle type AND ratio 1 to 1000") {
  constexpr auto one = 1_msr;
  STATIC_REQUIRE(
      std::is_same<decltype(one),
                   const SI::solid_angle_t<int64_t, std::milli>>::value);

  constexpr auto one_f = 1.0_msr;
  STATIC_REQUIRE(
      std::is_same<decltype(one_f),
                   const SI::solid_angle_t<long double, std::milli>>::value);
}

TEST_CASE("GIVEN a value WHEN constructed with literal _sr THEN result is a "
          "solid angle type AND ratio 1 to 1") {
  constexpr auto one = 1_sr;
  STATIC_REQUIRE(
      std::is_same<decltype(one),
                   const SI::solid_angle_t<int64_t, std::ratio<1>>>::value);

  constexpr auto one_f = 1.0_sr;
  STATIC_REQUIRE(
      std::is_same<decltype(one_f),
                   const SI::solid_angle_t<long double, std::ratio<1>>>::value);
}

TEST_CASE("GIVEN a 1 atto sterradiant WHEN passed to a streaming operator WHEN "
          "result is '1asr'") {
  constexpr auto value = 1_asr;
  std::stringstream ss;
  ss << value;
  REQUIRE(ss.str() == "1asr");
}

TEST_CASE(
    "GIVEN a 1 femto sterradiant WHEN passed to a streaming operator WHEN "
    "result is '1fsr'") {
  constexpr auto value = 1_fsr;
  std::stringstream ss;
  ss << value;
  REQUIRE(ss.str() == "1fsr");
}

TEST_CASE("GIVEN a 1 pico sterradiant WHEN passed to a streaming operator WHEN "
          "result is '1psr'") {
  constexpr auto value = 1_psr;
  std::stringstream ss;
  ss << value;
  REQUIRE(ss.str() == "1psr");
}

TEST_CASE("GIVEN a 1 nano sterradiant WHEN passed to a streaming operator WHEN "
          "result is '1psr'") {
  constexpr auto value = 1_nsr;
  std::stringstream ss;
  ss << value;
  REQUIRE(ss.str() == "1nsr");
}

TEST_CASE(
    "GIVEN a 1 micro sterradiant WHEN passed to a streaming operator WHEN "
    "result is '1usr'") {
  constexpr auto value = 1_usr;
  std::stringstream ss;
  ss << value;
  REQUIRE(ss.str() == "1usr");
}

TEST_CASE(
    "GIVEN a 1 milli sterradiant WHEN passed to a streaming operator WHEN "
    "result is '1msr'") {
  constexpr auto value = 1_msr;
  std::stringstream ss;
  ss << value;
  REQUIRE(ss.str() == "1msr");
}

TEST_CASE(
    "GIVEN a 1 sterradiant WHEN passed to a streaming operator WHEN result is "
    "'1sr'") {
  constexpr auto value = 1_sr;
  std::stringstream ss;
  ss << value;
  REQUIRE(ss.str() == "1sr");
}
