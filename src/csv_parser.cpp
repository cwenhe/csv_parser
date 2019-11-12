#include "csv_parser.h"

#include <fstream>


namespace csv
{

    csv_parser::iterator_::iterator_()
        :node_(new node)
    {
    }

    csv_parser::node* csv_parser::iterator_::operator->()const
    {
        return this->node_.get();
    }

    csv_parser::node& csv_parser::iterator_::operator*() const
    {
        return *this->node_.get();
    }

    bool csv_parser::iterator_::operator== ( iterator_ const& rhs) const
    {
        return rhs.node_->row_iterator == this->node_->row_iterator;
    }

    csv_parser::csv_parser( std::string const& file_name)
    {
    }


    csv_parser::iterator csv_parser::begin() const
    {
        iterator begin;
        return begin;
    }

    csv_parser::iterator csv_parser::end() const
    {
        iterator iter;
        return iter;
    }


    bool csv_parser::read_from_file( std::string const& file_name )
    {
        std::ifstream ifs(file_name);
        std::vector<std::string> tokens;
        std::string line;
        char const delimiter = ',';
        while(std::getline(ifs, line))
        {
            std::string token;
            std::stringstream ssm(line);
            while(std::getline(ssm, token, delimiter))
            {
                tokens.emplace_back(token);
            }

        }

        return true;
    }
    
} /* csv */ 
