// 9.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

const std::vector<std::string> identifiers = { "return", "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool",
                                               "break", "case", "catch", "char", "char16_t", "char32_t", "class", "compl", "const",
                                               "constexpr", "const_cast", "continue", "decltype", "default", "delete", "do", "double",
                                               "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for",
                                               "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept",
                                               "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public",
                                               "register", "reinterpret_cast", "return", "short", "signed", "sizeof", "static", "static_assert",
                                               "static_cast", "struct", "switch", "template", "this", "thread_local", "throw", "true", "try",
                                               "typedef", "typeid", "typename", "union", "unsigned", "using", "void", "volatile",
                                               "wchar_t", "while", "xor", "xor_eq", "uint_64", "uint_32", "uint_16", "uint_8", "wchar_t",
                                               "char16_t", "char32_t", "std::endl", "std::cout", "std::cin", ">>", "<<", "std::",
                                               "#include", "class", "struct", "size_t", "getline", ".at(", "size_t",
                                               "virtual", "using", "system", "pause", "while"};

const std::string name_can_t_have = {"!#*(){}[]+='123456789~|?/:<>"};
const std::string symbols_to_filter = {",;}"};

std::vector<std::string> divideIntoWords(const std::string& str)
{
    std::vector<std::string> words;
    std::string word;
    for (auto x : str) {
        if (x == ' ') {
            words.push_back(word);
            word.clear();
        }
        else {
            word.push_back(x);
        }
    }
    return words;
}

bool isItIdentificator(const std::string& information) {
    for (size_t i = 0; i < identifiers.size(); ++i) {
        if (information == identifiers.at(i)) {
            return false;
        }
    }
    for (auto letter : information) {
        if (letter == '"') {
            return false;
        }
        for (auto letters_sholdn_t_have : name_can_t_have) {
            if (letter == letters_sholdn_t_have) {
                return false;
            }
        }
    }
    if (!information.size()) {
        return false;
    }
    return true;
}

void filterString(std::string& str) {
    for (size_t i = 0; i < symbols_to_filter.size(); ++i) {
        if (str.at(str.size() - 1) == symbols_to_filter.at(i)) {
            str.pop_back();
        }
        if (str.at(0) == symbols_to_filter.at(i)) {
            str.erase(0, 1);
        }
    }
}

int main()
{
    std::multimap<std::string, size_t> data_repeat;
    std::map<std::string, size_t> data_no_repeat;
    std::ifstream fin("INPUT.txt"); 
    if (!fin.is_open()) {
        std::cout << "This file can't be open!\n";
    }
    else {
        std::string line;
        std::pair<std::string, size_t> piece;
        size_t counter = 1;
        while (getline(fin, line)) {
            counter++;
            std::vector<std::string> words = divideIntoWords(line);
            for (auto word : words) {
                if (isItIdentificator(word)) {
                    filterString(word);
                    piece = std::make_pair(word, counter);
                    data_repeat.insert(piece);
                    data_no_repeat.insert(piece);
                }
            }
        }
        for (auto it = data_no_repeat.begin(); it != data_no_repeat.end(); ++it) {
            std::cout << "Word '" << (*it).first << "' was found at: ";
            for (auto it_2 = data_repeat.begin(); it_2 != data_repeat.end(); ++it_2) {
                if ((*it).first == (*it_2).first) {
                    std::cout << (*it_2).second << " ";
                }
            }
            std::cout << std::endl;
        }
        fin.close();
    }
    system("pause");
    return 0;
}

