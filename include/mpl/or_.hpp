#pragma once


template<bool, typename... _args>
struct or_impl;

template<typename _arg1, typename... _args>
struct or_impl<false, _arg1, _args...>
    :or_impl<_arg1::value, _args...>
{
};

template<typename... _args>
struct or_impl<true, _args...>
{
    static bool const value = true;
};


template<>
struct or_impl<false>
{
    static bool const value = false;
};



template<typename _arg1, typename... _args>
struct or_
    :or_impl<_arg1::value, _args...>
{

};
