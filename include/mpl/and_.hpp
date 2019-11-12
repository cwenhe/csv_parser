#pragma once

#include <type_traits>

namespace mpl
{

    template<bool _arg1, typename... _args>
        struct and_impl;

    template<typename... _args>
        struct and_impl<false, _args...>
        {
            static bool const value = false;
        };


    template<typename _arg1, typename... _args>
        struct and_impl<true, _arg1, _args...>
        :and_impl<_arg1::value, _args...>
        {
        };


    template<>
        struct and_impl<true>
        {
            static bool const value = true;
        };


    template<typename _arg1, typename... _args>
        struct and_:
            and_impl<_arg1::value, _args...>
    {

    };

} /* mpl */ 

