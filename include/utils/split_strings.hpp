#pragma once
#include <string>
#include <sstream>
#include <iterator>
#include <vector>


template<char delimiter>
class delimited_by_char: public std::string{};

std::vector<std::string> split_by_char(std::string &str){
    const char delimiter = ';';
    std::istringstream iss(str);
    std::vector<std::string> splitted ((std::istream_iterator<delimited_by_char<delimiter>>(iss)), 
                                        std::istream_iterator<delimited_by_char<delimiter>>());
    
    return splitted;
}