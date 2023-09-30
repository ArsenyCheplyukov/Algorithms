// 9_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include <stack>


// expression to which we are need answer
std::string input = { "12.5 13.5 45.3 43.8 * / + 13.2 + 173 -" };



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

int main() {
    input.push_back(' ');
    std::stack<double> variables_memory;
    std::vector<std::string> words = divideIntoWords(input);
    for (auto word : words) {
        if ((word.at(0) >= '0') && ((word.at(0)) <= '9')) {
            variables_memory.push(std::stod(word));
        }
        else {
            double a = variables_memory.top();
            variables_memory.pop();
            double b = variables_memory.top();
            variables_memory.pop();
            switch (word.at(0)) {
            case '+':
                variables_memory.push(a + b);
                break;
            case '-':
                variables_memory.push(a - b);
                break;
            case '/':
                variables_memory.push(a / b);
                break;
            case '*':
                variables_memory.push(a * b);
                break;
            }
        }
    }
    std::cout << "Result is: " << variables_memory.top() << std::endl;
    system("pause");
    return 0;
}