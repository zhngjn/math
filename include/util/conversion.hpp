#ifndef UTIL_CONVERSION_HPP 
#define UTIL_CONVERSION_HPP

#include "util/constants.hpp"

namespace math
{
namespace util 
{
namespace conv
{
template <typename T>
T degToRad(T deg)
{
    return deg * constants::DEG_TO_RAD<T>;
}

template <typename T>
T radToDeg(T rad)
{
    return rad * constants::RAD_TO_DEG<T>;
}

} // namespace conv
} // namespace util
} // namespace math

#endif // UTIL_CONVERSION_HPP