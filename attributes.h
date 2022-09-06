#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#ifdef __cplusplus
#   define ATT_HAS_CPP 1

#   if __cplusplus >= 202002L
#       define ATT_HAS_CPP20
#   endif

#   if __cplusplus >= 201703L
#       define ATT_HAS_CPP17
#   endif

#   if __cplusplus >= 201402L
#       define ATT_HAS_CPP14
#   endif

#   if __cplusplus >= 201103L
#       define ATT_HAS_CPP11
#   endif
#else
#   define ATT_HAS_CPP 0
#endif

#ifdef ATT_HAS_CPP20
#   define att_likely_branch [[likely]]
#   define att_unlikely_branch [[unlikely]]
#   define _ATT_HAS_LIKELY_UNLIKELY_BRANCH
#endif

#ifdef ATT_HAS_CPP17
#   define att_nodiscard [[nodiscard]]
#   define _ATT_HAS_NODISCARD

#   define att_maybe_unused [[maybe_unused]]
#   define _ATT_HAS_MAYBE_UNUSED

#   define att_fallthrough [[fallthrough]]
#   define _ATT_HAS_FALLTHROUGH
#endif

#ifdef ATT_HAS_CPP14
#   define att_deprecated(message) [[deprecated(message)]]
#   define _ATT_HAS_DEPRECATED
#endif

#ifdef ATT_HAS_CPP11
#   define att_noreturn [[noreturn]]
#   define _ATT_HAS_NORETURN
#endif

#ifdef __GNUC__
#   define att_force_inline __attribute__((always_inline))

#   if __GNUC__ >= 3
#       define att_expect(expr, expected) __builtin_expect(!!(expr), expected)
#       define att_likely_expr(expr) att_expect(expr, 1)
#       define att_unlikely_expr(expr) att_expect(expr, 0)
#       define _ATT_HAS_EXPECT_LIKELY_UNLIKELY
#   endif

#   if __GNUC__ >= 4
#       ifndef _ATT_HAS_NODISCARD
#           define att_nodiscard __attribute__((warn_unused_result))
#           define _ATT_HAS_NODISCARD
#       endif
#   endif

#   if __GNUC__ >= 7
#       ifndef _ATT_HAS_FALLTHROUGH
#           define att_fallthrough __attribute__((fallthrough))
#           define _ATT_HAS_FALLTHROUGH
#       endif
#   endif

#   ifdef __has_attribute
#       if __has_attribute(returns_nonnull)
#           define att_returns_nonnull __attribute__((returns_nonnull))
#           define _ATT_HAS_RETURNS_NONNULL
#       endif
 
#       if __has_attribute(nonnull)
#           define att_nonnull __attribute__((nonnull))
#           define _ATT_HAS_NONNULL
#       endif
 
#       if __has_attribute(__cleanup__)
#           define att_cleanup(fun) __attribute__((__cleanup__(fun)))
//#         define _ATT_HAS_CLEANUP
#       endif

#       if !defined _ATT_HAS_MAYBE_UNUSED && __has_attribute(unused)
#           define att_maybe_unused __attribute__((unused))
#           define _ATT_HAS_MAYBE_UNUSED
#       endif

#       if !defined _ATT_HAS_NORETURN && __has_attribute(noreturn)
#           define att_noreturn __attribute__((noreturn))
#           define _ATT_HAS_NORETURN
#       endif

#       if !defined _ATT_HAS_DEPRECATED && __has_attribute(deprecated)
#           define att_deprecated(message) __attribute__((deprecated(message)))
#           define _ATT_HAS_DEPRECATED
#       endif

#       if __has_attribute(cold)
#           define att_cold __attribute__((cold))
#           define _ATT_HAS_COLD
#       endif

#       if __has_attribute(const)
#           define att_const __attribute__((const))
#           define _ATT_HAS_CONST
#       endif

#       if __has_attribute(hot)
#           define att_hot __attribute__((hot))
#           define _ATT_HAS_HOT
#       endif

#       if __has_attribute(aligned)
#           define att_align(alignment) __attribute__((aligned(alignment)))
//#         define _ATT_HAS_ALIGN
#       endif

#       if __has_attribute(noinline)
#           define att_noinline __attribute__((noinline))
#           define _ATT_HAS_NOINLINE
#       endif

#       if __has_attribute(naked)
#           define att_naked __attribute__((naked))
//#         define _ATT_HAS_NAKED
#       endif

#       if __has_attribute(pure)
#           define att_pure __attribute__((pure))
#           define _ATT_HAS_PURE
#       endif

#       if __has_attribute(used)
#           define att_used __attribute__((used))
//#         define _ATT_HAS_USED
#       endif

#       if __has_attribute(weak)
#           define att_weak
#           define _ATT_HAS_WEAK
#       endif

#       if __has_attribute(packed)
#           define att_packed
//#         define _ATT_HAS_PACKED
#       endif

#       if __has_attribute(constructor)
#           define att_constructor
//#         define _ATT_HAS_CONSTRUCTOR
#       endif

#       if __has_attribute(destructor)
#           define att_destructor
//#         define _ATT_HAS_DESTRUCTOR
#       endif

#   endif /* ifdef __has_attribute */

#   ifdef __PRETTY_FUNCTION__
#       define att_pretty_fun __PRETTY_FUNCTION__
#       define _ATT_HAS_PRETTY_FUN
#   endif

#elif defined _MSC_VER
#   ifndef _ATT_HAS_NORETURN
#       define att_noreturn __declspec(noreturn)
#       define _ATT_HAS_NORETURN
#   endif

#   ifndef _ATT_HAS_DEPRECATED
#       define att_deprecated(message) __declspec(deprecated(message))
#       define _ATT_HAS_DEPRECATED
#   endif

#   define att_force_inline __forceinline
#   define att_align(alignment) __declspec(align(alignment))
#   define att_noinline __declspec(noinline)
#   define att_naked __declspec(naked)

#   define _ATT_HAS_NOINLINE

#else
#   define att_force_inline
#   define att_noinline
#   define _ATT_HAS_NOINLINE

//  not defined as *nothing* because it might be dangerous
//# define att_naked
//# define att_align
#endif

#ifndef _ATT_HAS_EXPECT_LIKELY_UNLIKELY
#   define att_expect(expr, prob) (expr)
#   define att_likely_expr(expr) (expr)
#   define att_unlikely_expr(expr) (expr)
#endif

#ifndef _ATT_HAS_NODISCARD
#   define att_nodiscard
#endif

#ifndef _ATT_HAS_RETURNS_NONNULL
#   define att_returns_nonnull
#endif

#ifndef _ATT_HAS_NONNULL
#   define att_nonnull
#endif

#ifndef _ATT_HAS_MAYBE_UNUSED
#   define att_maybe_unused
#endif

#ifndef _ATT_HAS_NORETURN
#   define att_noreturn
#endif

#ifndef _ATT_HAS_DEPRECATED
#   define att_deprecated(message)
#endif

#ifndef _ATT_HAS_COLD
#   define att_cold
#endif

#ifndef _ATT_HAS_CONST
#   define att_const
#endif

#ifndef _ATT_HAS_HOT
#   define att_hot
#endif

#ifndef _ATT_HAS_PURE
#   define att_pure
#endif

#ifndef _ATT_HAS_WEAK
#   define att_weak
#endif

#ifndef _ATT_HAS_FALLTHROUGH
#   define att_fallthrough do {} while (0)
#endif

#ifndef _ATT_HAS_LIKELY_UNLIKELY_BRANCH
#   define att_likely_branch
#   define att_unlikely_branch
#endif

#ifndef _ATT_HAS_NOINLINE
#   define att_noinline
#endif

/* attributes not defined as *nothing* because it might be dangerous

#ifndef _ATT_HAS_ALIGN
#   define att_align(alignment)
#endif

#ifndef _ATT_HAS_USED
#   define att_used
#endif

#ifndef _ATT_HAS_PACKED
#   define att_packed
#endif

#ifndef _ATT_HAS_CONSTRUCTOR
#   define att_constructor
#endif

#ifndef _ATT_HAS_DESTRUCTOR
#   define att_destructor
#endif

#ifndef _ATT_HAS_CLEANUP
#   define att_cleanup(fun)
#endif

*/

#if !defined _ATT_HAS_PRETTY_FUN && defined __FUNCTION__
#   define att_pretty_fun __FUNCTION__
#else
#   define att_pretty_fun "<unknown function>"
#endif

#ifdef __FUNCTION__
#   define att_fun __FUNCTION__
#else
#   define att_fun "<unknown function>"
#endif

#ifdef ATT_HAS_CPP14
#   define att_constexpr14 constexpr
#else
#   define att_constexpr14 inline
#endif

#ifdef ATT_HAS_CPP17
#   define att_constexpr17 constexpr
#else
#   define att_constexpr17 inline
#endif

#ifdef ATT_HAS_CPP20
#   define att_constexpr20 constexpr
#else
#   define att_constexpr20 inline
#endif

#endif
