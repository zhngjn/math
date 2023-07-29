#ifndef UTIL_UTILITY_HPP 
#define UTIL_UTILITY_HPP

#include <type_traits>

#include <boost/assert.hpp>

namespace math
{
namespace util
{

/**
 * @brief normalize floating value to [lower, upper)
 * 
 */
template <typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
T normalize(T value, T lower, T upper)
{
    BOOST_ASSERT(lower < upper);

    T period = upper - lower;
    while (value < lower) value += period;
    while (value >= upper) value -= period;
    return value;
}

template <typename T>
double horner(double, T a) { return a; }

template <typename T, typename... U> 
double horner(double x, T a, U... as)
{
    return horner(x, as...) * x + a;
}

} // namespace util
} // namespace math

#endif // UTIL_UTILITY_HPP