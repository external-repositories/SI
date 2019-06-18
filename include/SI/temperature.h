#pragma once
#include "detail/unit.h"

namespace SI {

/// @todo find a way to encapuslate unit symbol Theta
/// @todo consider adding Celsius and fahrenheit
template <typename _Type, typename _Ratio>
using temperature_t = detail::unit_t<'t', 1, _Type, _Ratio>;
template <typename _Type> using atto_kelvin_t = temperature_t<_Type, std::atto>;
template <typename _Type>
using femto_kelvin_t = temperature_t<_Type, std::femto>;
template <typename _Type> using pico_kelvin_t = temperature_t<_Type, std::pico>;
template <typename _Type> using nano_kelvin_t = temperature_t<_Type, std::nano>;
template <typename _Type>
using micro_kelvin_t = temperature_t<_Type, std::micro>;
template <typename _Type>
using milli_kelvin_t = temperature_t<_Type, std::milli>;
template <typename _Type> using kelvin_t = temperature_t<_Type, std::ratio<1>>;
template <typename _Type> using kilo_kelvin_t = temperature_t<_Type, std::kilo>;
template <typename _Type> using mega_kelvin_t = temperature_t<_Type, std::mega>;
template <typename _Type> using giga_kelvin_t = temperature_t<_Type, std::giga>;
template <typename _Type> using tera_kelvin_t = temperature_t<_Type, std::tera>;
template <typename _Type> using peta_kelvin_t = temperature_t<_Type, std::peta>;
template <typename _Type> using exa_kelvin_t = temperature_t<_Type, std::exa>;

inline namespace literals {

template <char... _Digits> constexpr auto operator""_aK() {
  return atto_kelvin_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_fK() {
  return femto_kelvin_t<int64_t>{
      SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_pK() {
  return pico_kelvin_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_nK() {
  return nano_kelvin_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_uK() {
  return micro_kelvin_t<int64_t>{
      SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_mK() {
  return milli_kelvin_t<int64_t>{
      SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_K() {
  return kelvin_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_kK() {
  return kilo_kelvin_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_MK() {
  return mega_kelvin_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_GK() {
  return giga_kelvin_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_TK() {
  return tera_kelvin_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_PK() {
  return peta_kelvin_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

template <char... _Digits> constexpr auto operator""_EK() {
  return exa_kelvin_t<int64_t>{SI::detail::parsing::Number<_Digits...>::value};
}

constexpr auto operator""_aK(long double value) {
  return atto_kelvin_t<long double>{value};
}

constexpr auto operator""_fK(long double value) {
  return femto_kelvin_t<long double>{value};
}

constexpr auto operator""_pK(long double value) {
  return pico_kelvin_t<long double>{value};
}

constexpr auto operator""_nK(long double value) {
  return nano_kelvin_t<long double>{value};
}

constexpr auto operator""_uK(long double value) {
  return micro_kelvin_t<long double>{value};
}

constexpr auto operator""_mK(long double value) {
  return milli_kelvin_t<long double>{value};
}

constexpr auto operator""_K(long double value) {
  return kelvin_t<long double>{value};
}

constexpr auto operator""_kK(long double value) {
  return kilo_kelvin_t<long double>{value};
}

constexpr auto operator""_MK(long double value) {
  return mega_kelvin_t<long double>{value};
}

constexpr auto operator""_GK(long double value) {
  return giga_kelvin_t<long double>{value};
}

constexpr auto operator""_TK(long double value) {
  return tera_kelvin_t<long double>{value};
}

constexpr auto operator""_PK(long double value) {
  return peta_kelvin_t<long double>{value};
}

constexpr auto operator""_EK(long double value) {
  return exa_kelvin_t<long double>{value};
}

} // namespace literals
} // namespace SI