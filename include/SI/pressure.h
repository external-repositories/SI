#pragma once

#include "area.h"
#include "detail/operator_helpers.h"
#include "detail/unit.h"
#include "force.h"

namespace SI {
template <typename _Type, class _Ratio = std::ratio<1>>
using pressure_t = detail::unit_t<'p', 1, _Type, _Ratio>;

/// specific units
template <typename _Type> using atto_pascal_t = pressure_t<_Type, std::atto>;
template <typename _Type> using femto_pascal_t = pressure_t<_Type, std::femto>;
template <typename _Type> using pico_pascal_t = pressure_t<_Type, std::pico>;
template <typename _Type> using nano_pascal_t = pressure_t<_Type, std::nano>;
template <typename _Type> using micro_pascal_t = pressure_t<_Type, std::micro>;
template <typename _Type> using milli_pascal_t = pressure_t<_Type, std::milli>;
template <typename _Type> using pascal_t = pressure_t<_Type, std::ratio<1>>;
template <typename _Type> using kilo_pascal_t = pressure_t<_Type, std::kilo>;
template <typename _Type> using mega_pascal_t = pressure_t<_Type, std::mega>;
template <typename _Type> using giga_pascal_t = pressure_t<_Type, std::giga>;
template <typename _Type> using tera_pascal_t = pressure_t<_Type, std::tera>;
template <typename _Type> using peta_pascal_t = pressure_t<_Type, std::peta>;
template <typename _Type> using exa_pascal_t = pressure_t<_Type, std::exa>;

namespace detail {

BUILD_UNIT_FROM_DIVISON(pressure_t, force_t, area_t)
}

inline namespace literals {
template <char... _Digits> constexpr auto operator""_apa() {
  return atto_pascal_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_fpa() {
  return femto_pascal_t<int64_t>{
      SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_ppa() {
  return pico_pascal_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_npa() {
  return nano_pascal_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_upa() {
  return micro_pascal_t<int64_t>{
      SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_mpa() {
  return milli_pascal_t<int64_t>{
      SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_pa() {
  return pascal_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_kpa() {
  return kilo_pascal_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_Mpa() {
  return mega_pascal_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_Gpa() {
  return giga_pascal_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_Tpa() {
  return tera_pascal_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_Ppa() {
  return peta_pascal_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_Epa() {
  return exa_pascal_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

constexpr auto operator""_apa(long double value) {
  return atto_pascal_t<long double>{value};
}

constexpr auto operator""_fpa(long double value) {
  return femto_pascal_t<long double>{value};
}

constexpr auto operator""_ppa(long double value) {
  return pico_pascal_t<long double>{value};
}

constexpr auto operator""_npa(long double value) {
  return nano_pascal_t<long double>{value};
}

constexpr auto operator""_upa(long double value) {
  return micro_pascal_t<long double>{value};
}

constexpr auto operator""_mpa(long double value) {
  return milli_pascal_t<long double>{value};
}

constexpr auto operator""_pa(long double value) {
  return pascal_t<long double>{value};
}

constexpr auto operator""_kpa(long double value) {
  return kilo_pascal_t<long double>{value};
}

constexpr auto operator""_Mpa(long double value) {
  return mega_pascal_t<long double>{value};
}

constexpr auto operator""_Gpa(long double value) {
  return giga_pascal_t<long double>{value};
}

constexpr auto operator""_Tpa(long double value) {
  return tera_pascal_t<long double>{value};
}

constexpr auto operator""_Ppa(long double value) {
  return peta_pascal_t<long double>{value};
}

constexpr auto operator""_Epa(long double value) {
  return exa_pascal_t<long double>{value};
}

} // namespace literals
} // namespace SI