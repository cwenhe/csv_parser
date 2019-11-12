#pragma once

#include "bool_.hpp"


namespace mpl
{
    namespace aux
    {
        template< bool _value>
            struct not_impl
            :mpl::bool_<!_value>
            {

            };

    } /* aux */ 

    template< typename _type>
        struct not_
        :aux::not_impl<_type::value>
        {
        };


} /* mpl */ 
