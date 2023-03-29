// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: BSD-3-Clause

#ifndef BUILTIN_TYPE_20220405_HPP
#define BUILTIN_TYPE_20220405_HPP

#include "clir/export.hpp"

#include <iosfwd>
#include <string>

namespace clir {

enum class builtin_type {
    bool_t,
    /* begin vector types */
    char_t,
    uchar_t,
    short_t,
    ushort_t,
    int_t,
    uint_t,
    long_t,
    ulong_t,
    float_t,
    double_t,
    /* end vector types */
    half_t,
    size_t,
    ptrdiff_t,
    intptr_t,
    uintptr_t,
    void_t,
    cl_mem_fence_flags_t
};

enum class cl_mem_fence_flags { CLK_GLOBAL_MEM_FENCE, CLK_LOCAL_MEM_FENCE, CLK_IMAGE_MEM_FENCE };
enum class address_space { generic_t, global_t, local_t, constant_t, private_t };
enum class endianess { device, host };
enum class function_qualifier : int { none = 0x0, extern_t = 0x1, inline_t = 0x2, kernel_t = 0x4 };

CLIR_EXPORT char const *to_string(builtin_type basic_data_type);
CLIR_EXPORT char const *to_string(cl_mem_fence_flags fence_flag);
CLIR_EXPORT char const *to_string(address_space as);
CLIR_EXPORT char const *to_string(endianess e);
CLIR_EXPORT std::string to_string(function_qualifier q, char sep = ' ');
CLIR_EXPORT std::ostream &operator<<(std::ostream &os, builtin_type sdt);
CLIR_EXPORT std::ostream &operator<<(std::ostream &os, cl_mem_fence_flags fence_flag);
CLIR_EXPORT std::ostream &operator<<(std::ostream &os, address_space as);
CLIR_EXPORT std::ostream &operator<<(std::ostream &os, function_qualifier q);

CLIR_EXPORT function_qualifier operator|(function_qualifier x, function_qualifier y);
CLIR_EXPORT function_qualifier operator&(function_qualifier x, function_qualifier y);
CLIR_EXPORT bool test(function_qualifier x);

template <typename T> struct to_builtin_type;
template <> struct to_builtin_type<char> {
    static constexpr builtin_type value = builtin_type::char_t;
};
template <> struct to_builtin_type<unsigned char> {
    static constexpr builtin_type value = builtin_type::uchar_t;
};
template <> struct to_builtin_type<short> {
    static constexpr builtin_type value = builtin_type::short_t;
};
template <> struct to_builtin_type<unsigned short> {
    static constexpr builtin_type value = builtin_type::ushort_t;
};
template <> struct to_builtin_type<int> {
    static constexpr builtin_type value = builtin_type::int_t;
};
template <> struct to_builtin_type<unsigned int> {
    static constexpr builtin_type value = builtin_type::uint_t;
};
template <> struct to_builtin_type<long> {
    static constexpr builtin_type value = builtin_type::long_t;
};
template <> struct to_builtin_type<unsigned long> {
    static constexpr builtin_type value = builtin_type::ulong_t;
};
template <> struct to_builtin_type<float> {
    static constexpr builtin_type value = builtin_type::float_t;
};
template <> struct to_builtin_type<double> {
    static constexpr builtin_type value = builtin_type::double_t;
};
template <typename T> inline constexpr builtin_type to_builtin_type_v = to_builtin_type<T>::value;

} // namespace clir

#endif // BUILTIN_TYPE_20220405_HPP
