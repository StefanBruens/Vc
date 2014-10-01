/*  This file is part of the Vc library. {{{

    Copyright (C) 2013 Matthias Kretz <kretz@kde.org>

    Vc is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version.

    Vc is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with Vc.  If not, see <http://www.gnu.org/licenses/>.

}}}*/

#include "unittest.h"
#include <Vc/type_traits>
#include <memory>

using Vc::float_v;
using Vc::double_v;
using Vc::int_v;
using Vc::uint_v;
using Vc::short_v;
using Vc::ushort_v;

TEST_TYPES(V, isIntegral, (ALL_VECTORS))
{
    using T = typename V::EntryType;
    COMPARE(Vc::is_integral<V>::value, std::is_integral<T>::value);
}

TEST_TYPES(V, isFloatingPoint, (ALL_VECTORS))
{
    using T = typename V::EntryType;
    COMPARE(Vc::is_floating_point<V>::value, std::is_floating_point<T>::value);
}

TEST_TYPES(V, isSigned, (ALL_VECTORS))
{
    using T = typename V::EntryType;
    COMPARE(Vc::is_signed<V>::value, std::is_signed<T>::value);
    COMPARE(Vc::is_unsigned<V>::value, std::is_unsigned<T>::value);
}

TEST_TYPES(V, hasSubscript, (ALL_VECTORS))
{
    VERIFY(Vc::Traits::has_subscript_operator<V>::value);
}

TEST_TYPES(V, hasMultiply, (ALL_VECTORS))
{
    VERIFY(Vc::Traits::has_multiply_operator<V>::value);
}

TEST_TYPES(V, hasEquality, (ALL_VECTORS))
{
    VERIFY(Vc::Traits::has_equality_operator<V>::value);
}

TEST_TYPES(V, isSimdMask, (ALL_VECTORS))
{
    VERIFY(!Vc::is_simd_mask<V>::value);
    VERIFY( Vc::is_simd_mask<typename V::Mask>::value);
}

TEST_TYPES(V, isSimdVector, (ALL_VECTORS))
{
    VERIFY( Vc::is_simd_vector<V>::value);
    VERIFY(!Vc::is_simd_vector<typename V::Mask>::value);
}

template <typename T> void hasContiguousStorageImpl(T &&, const char *type)
{
    VERIFY(Vc::Traits::has_contiguous_storage<T>::value) << type;
}

TEST(hasContiguousStorage)
{
    std::unique_ptr<int[]> a(new int[3]);
    int b[3] = {1, 2, 3};
    const std::unique_ptr<int[]> c(new int[3]);
    const int d[3] = {1, 2, 3};
    auto &&e = {1, 2, 3};
    const auto &f = {1, 2, 3};
    std::vector<int> g;
    std::array<int, 3> h;
    hasContiguousStorageImpl(a.get(), "T[]");
    hasContiguousStorageImpl(a, "std::unique_ptr<T[]>");
    hasContiguousStorageImpl(&a[0], "T *");
    hasContiguousStorageImpl(b, "T[3]");
    hasContiguousStorageImpl(c.get(), "const T[]");
    hasContiguousStorageImpl(c, "std::unique_ptr<const T[]>");
    hasContiguousStorageImpl(&c[0], "const T *");
    hasContiguousStorageImpl(d, "const T[3]");
    hasContiguousStorageImpl(e, "std::initializer_list 1");
    hasContiguousStorageImpl(f, "std::initializer_list 2");
    hasContiguousStorageImpl(g, "std::vector<int>");
    // no way to specialize for vector::iterator...
    // hasContiguousStorageImpl(g.begin(), "std::vector<int>::iterator");
    hasContiguousStorageImpl(h, "std::array<int, 3>");
    hasContiguousStorageImpl(h.begin(), "std::array<int, 3>::iterator");
}

struct F0
{
    template <typename T> void operator()(T &) const {}
};
struct F1
{
    template <typename T> void operator()(const T &) const {}
};

TEST(test_is_functor_argument_immutable)
{
    VERIFY(!(Vc::Traits::is_functor_argument_immutable<F0, int>::value));
    VERIFY((Vc::Traits::is_functor_argument_immutable<F1, int>::value));
}
