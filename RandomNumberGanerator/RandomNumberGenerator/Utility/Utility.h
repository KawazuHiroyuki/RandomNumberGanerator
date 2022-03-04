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
        typename Head::TSecond,   // true�̎�
        typename Switch<Tail...>::type //false�̎�
        >::type;
};

//�ċN�I�[�p���ꉻ
template<class Head>
struct Switch<Head>
{
    using type =
        typename std::conditional<
        Head::TBOOL,
        typename Head::TSecond, // true�̎�
        void
        >::type;
};
} // namespace utility