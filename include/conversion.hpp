#pragma once

#include <string>
#include <sstream>
#include <type_traits>
#include <stdexcept>
#include "mpl/and_.hpp"
#include "mpl/not_.hpp"

namespace conversion
{

    namespace detail
    {
        template<typename _src_type, typename _dst_type>
            void do_cast(_src_type const&, _dst_type&);
    }

    //TODO 无效字符串,校验是否转失败
    template<typename _src_type, typename _dst_type>
        void convert(_src_type const& src, _dst_type& dst)
        {
            detail::do_cast(src, dst);
        }

    namespace  detail
    {
        template<typename _dst_type, typename _src_type>
            typename std::enable_if<std::is_same<_dst_type, _src_type>::value>::type 
            do_cast(_src_type const& src, _dst_type& dst)
            {
                dst = src;
            }

        template<typename _dst_type>
            typename std::enable_if<
                                mpl::and_<
                                        std::is_arithmetic<_dst_type>,
                                        mpl::not_<std::is_same<bool, _dst_type> > 
                                            >::value 
                                    > ::type 
            do_cast(std::string const& src, _dst_type& dst)
            {
                std::stringstream ssm(src);
                ssm>>dst;
                if(ssm.fail() || ssm.eof())
                {
                    std::stringstream err_ssm;
                    err_ssm<<"value cast error for source string:"<<ssm.str();
                    throw std::invalid_argument(err_ssm.str());
                }
            }

        template<typename _dst_type>
            typename std::enable_if<
                                mpl::and_<
                                        std::is_arithmetic<_dst_type>,
                                        std::is_same<bool, _dst_type>
                                            >::value 
                                    > ::type 
            do_cast(std::string const& src, _dst_type& dst)
            {
                std::stringstream ssm(src);
                ssm>>std::boolalpha>>dst;
                if(ssm.fail() || ssm.eof())
                {
                    std::stringstream err_ssm;
                    err_ssm<<"value cast error for source string:"<<ssm.str();
                    throw std::invalid_argument(err_ssm.str());
                }
            }


        template<typename _src_type>
            typename std::enable_if<
                                mpl::and_<
                                        std::is_arithmetic<_src_type>,
                                        mpl::not_<std::is_same<bool, _src_type> > 
                                            >::value 
                                    > ::type 
            do_cast(_src_type const src, std::string& dst)
            {
                std::stringstream ssm;
                ssm<<src;
                dst = ssm.str();
            }


        template<typename _src_type>
            typename std::enable_if<
                                mpl::and_<
                                        std::is_arithmetic<_src_type>,
                                        std::is_same<bool, _src_type>
                                            >::value 
                                    > ::type 
            do_cast(_src_type const src, std::string& dst)
            {
                std::stringstream ssm;
                ssm<<std::boolalpha<<src;
                dst = ssm.str();
            }
    } /*  detail */ 



} /*  conversion */ 

