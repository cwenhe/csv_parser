#pragma once

namespace mpl
{
    template<bool _value>
    struct bool_
    {
        static bool const value = _value;
        using type = bool;
    };

}
