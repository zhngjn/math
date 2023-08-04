#ifndef UTIL_CONSTANTS_HPP 
#define UTIL_CONSTANTS_HPP

#include <limits>

#include <boost/math/constants/constants.hpp>

namespace math
{
namespace util 
{
namespace constants
{

template <typename T>
constexpr T epsilon();

template <>
constexpr double epsilon<double>() { return std::numeric_limits<double>::epsilon(); }
template <>
constexpr float epsilon<float>() { return std::numeric_limits<float>::epsilon(); }

template <typename T>
constexpr T PI = boost::math::constants::pi<T>();

template <typename T>
constexpr T DEG_TO_RAD = boost::math::constants::degree<T>();
template <typename T>
constexpr T RAD_TO_DEG = boost::math::constants::radian<T>();

} // namespace constants 
} // namespace util
} // namespace math

#endif // UTIL_CONSTANTS_HPP