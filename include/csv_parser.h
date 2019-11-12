#pragma once

#include <string>
#include <vector>
#include <list>
#include <memory>
#include <unordered_map>

#include "conversion.hpp"


namespace csv
{

    class csv_parser
    {
        public:
            using columns = std::vector<std::string>;
            using rows = std::list<columns>;

            struct node
            {
                std::unordered_map<std::string, size_t> header_idx;
                rows::iterator row_iterator;

                template<typename _dest_type>
                    _dest_type get( std::string const& index_name )
                    {
                        _dest_type dst;
                        this->get(index_name, dst);
                        return dst;
                    }

                template<typename _dest_type>
                    void get( std::string const& index_name, _dest_type& dst)
                    {
                        auto iter = header_idx.find(index_name);
                        if(iter == header_idx.end())
                        {
                            auto begin_node = row_iterator->begin();
                            conversion::convert(*std::next(begin_node, iter->second),
                                    dst);
                        }
                    }
            };

            class iterator_
            {
                public:
                    iterator_();

                    node* operator->()const;

                    node& operator*() const;

                    bool operator== ( iterator_ const& rhs) const;

                private:
                    std::unique_ptr<node> node_;
            };

            using iterator = iterator_;

            csv_parser( std::string const& file_name);

            iterator begin() const;

            iterator end() const;

            void from_raw( std::string const& raw_data, std::vector<std::string> const& header);

            std::string to_csv();

        private:
            bool read_from_file( std::string const& file_name );


        private:
            std::list< std::list<std::string> >  nodes_;
    };

} /* csv */ 

