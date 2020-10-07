#pragma once

#include <cstddef>
#include <type_traits>

#include "Vector.h"
#include "Array.h"
#include "Iterators.h"

namespace learncpp
{

template<typename Iter>
using iterator_category_t = typename std::iterator_traits<Iter>::iterator_category;

template<typename InputIt>
using is_input_iterator = std::enable_if_t<
    std::is_convertible<iterator_category_t<InputIt>, std::input_iterator_tag>::value>;

} // namespace learncpp