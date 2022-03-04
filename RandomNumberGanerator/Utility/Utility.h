#pragma once

#include <type_traits>

namespace utility
{
template<bool BOOL, typename Second>
struct Case
{
    static constexpr bool TBOOL = BOOL;
    using TSecond = Second;
};

template<class Head, class... Tail>
struct Switch
{
    using type =
        typename std::conditional<
        Head::TBOOL,
        typename Head::TSecond,   // trueの時
        typename Switch<Tail...>::type //falseの時
        >::type;
};

//再起終端用特殊化
template<class Head>
struct Switch<Head>
{
    using type =
        typename std::conditional<
        Head::TBOOL,
        typename Head::TSecond, // trueの時
        void
        >::type;
};
} // namespace utility