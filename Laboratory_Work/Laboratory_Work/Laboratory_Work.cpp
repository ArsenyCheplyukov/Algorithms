#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <String>
#include <list>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <Windows.h>
#include <chrono>

const double min_accuracy              = 0.000001;
const int max_power                    = 25;
const int max_length                   = 6;
const int maximum_number_in_lesson_3_4 = 20000000;
const int stop_number                  = 10923865;
const std::string words_dividers       = {"?,:!-();_%="};
const std::string numbers_list         = {"9876543210"};

// structs for 1 lesson

struct variables_lesson_1_1 {
    int s;
    int t;
    double x;
};

struct variables_lesson_1_2 {
    double x;
    double y;
};

struct variables_lesson_1_3 {
    double x1;
    double x2;
    double x3;
    double x4;
};

struct variables_lesson_1_4 {
    int k;
    int l;
    int m;
    int n;
};

struct variables_lesson_1_5 {
    double x1;
    double x2;
    double x3;
    double x4;
    double y1;
    double y2;
    double y3;
    double y4;
};

struct variables_lesson_1_6 {
    unsigned long n;
};

/// Lesson 2 structs 

struct variables_lesson_2_1_1 {
    unsigned long n;
    int k;
};

struct variables_lesson_2_1_2 {
    double number;
    int n;                     //number of repetitions
};

struct variables_lesson_2_2 {
    double x_0;
    double x_n;
    double d_x;
};

struct variables_lesson_2_7 {
    double delta_x;
    double x_m;
    double x_0;
    double n;
};

// structs for lesson 3

struct variables_lesson_3_1 {
    int number_of_array;
    std::vector <int> array_of_int;
};

struct variables_lesson_3_2 {
    int number_of_elements;
    std::vector<std::vector <int>> matrix;
};

struct variables_lesson_3_3 {
    int max_number;
};

struct variables_lesson_3_4 {
    int numRow;
    int numColumn;
};

struct variables_lesson_3_5 {
    int matrix_number;
    std::vector<std::vector<int>> matrix;
};

struct variables_lesson_3_7 {
    int matrix_number;
    std::vector <int> matrix_1;
    std::vector <int> matrix_2;
};

struct variables_lesson_5_1 {
    int matrix_number;
    std::vector<int> matrix;
};

struct variables_lesson_5_9 {
    std::vector<int> x;
    std::vector<int> y;
};

std::string binary_repesentation(const unsigned long& number) {
    int mx = 0;
    std::string str;
    while ((number >> mx++) > 1);
    int num = number, bin;
    while (mx > 0)
    {
        bin = pow(2, --mx);
        if (num < bin)
            str += '0';
        else
        {
            str += '1';
            num -= bin;
        }
    }
    return str;
}

int rotation(int number) {
    int answer = 0;
    while (number)
    {
        answer = answer * 10 + number % 10;
        number /= 10;
    }
    return answer;
}

std::vector<char> rotation(std::vector <char> start_number) {
    std::vector <char> answer_vector;
    for (short counter = 0; counter < start_number.size(); counter++) {
        answer_vector.push_back(start_number.at(start_number.size() - counter - 1));
    }
    return answer_vector;
}

std::vector<int> rotation(std::vector <int> start_number) {
    std::vector <int> answer_vector;
    for (int counter = 0; counter < start_number.size(); counter++) {
        answer_vector.push_back(start_number.at(start_number.size() - counter - 1));
    }
    return answer_vector;
}

std::string rotation(std::string start_number) {
    std::string answer_vector;
    for (int counter = 0; counter < start_number.size(); counter++) {
        answer_vector.push_back(start_number.at(start_number.size() - counter - 1));
    }
    return answer_vector;
}

bool simpleNumber(int number) {
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int findMax(std::vector<int> array) {
    int max_element = 0;
    for (int a = 0; a < array.size(); a++) {
        if (array.at(a) > max_element) {
            max_element = array.at(a);
        }
    }
    return max_element;
}

int findIndexMax(std::vector<int> array) {
    int max_element = array.at(0); int max_element_index = 0;
    for (int a = 1; a < array.size(); a++) {
        if (array.at(a) > max_element) {
            max_element = array.at(a);
            max_element_index = a;
        }
    }
    return max_element_index;
}

int findMin(std::vector<int> array) {
    int min_element = array.at(0);
    for (int a = 1; a < array.size(); a++) {
        if (array.at(a) < min_element) {
            min_element = array.at(a);
        }
    }
    return min_element;
}

int findIndexMin(std::vector<int> array) {
    int min_element = array.at(0); int min_element_index = 0;
    for (int a = 1; a < array.size(); a++) {
        if (array.at(a) < min_element) {
            min_element = array.at(a);
            min_element_index = a;
        }
    }
    return min_element_index;
}

int random(int min_number, int max_number){
    // never do this
    int number = (rand() % max_number + min_number);
    return number;
}

std::vector<int> huge_factorial(int number) {
    std::vector<int> answer_vector(number,0);
    answer_vector.at(0) = 1;
    for (int counter = 1; counter <= number; counter++) {
        for (int counter_of_order = 0; counter_of_order < answer_vector.size(); counter_of_order++) {
            answer_vector.at(counter_of_order) *= counter;
            if (answer_vector.at(counter_of_order) >= pow(10, max_length + 1)) {
                answer_vector.at(counter_of_order + 1) += (answer_vector.at(counter_of_order) / pow(10, max_length + 1));
                answer_vector.at(counter_of_order) = answer_vector.at(counter_of_order) % int(pow(10, max_length + 1));
            }
        }
    }
    return answer_vector;
}

int SomeNumberInAnother(std::vector<int> array_of_int, int number) {
    int counter_of_this_number = 0;
    for (int counter = 0; counter < array_of_int.size(); counter++) {
        int half_ans = array_of_int.at(counter);
        while (half_ans > 9) {
            int count = half_ans % 10;
            if (count == number) {
                counter_of_this_number++;
            }
            half_ans /= 10;
        }
        if (half_ans == number) {
            counter_of_this_number++;
        }
    }
    return counter_of_this_number;
}

template<typename T>
void pop_front(std::vector<T>& v)
{
    if (v.size() > 0) {
        v.front() = std::move(v.back());
        v.pop_back();
    }
}

template<typename T>
void write_table(std::vector<std::string> name_of_columns, std::vector<std::vector<T>> data_of_table, std::vector<int> size_of_columns) {
    for (int counter_column = 0; counter_column < name_of_columns.size(); counter_column++) {
        std::cout << std::internal << std::setw(size_of_columns.at(counter_column)) << name_of_columns.at(counter_column);
    }
    for (int counter_row = 0; counter_row < data_of_table.size(); counter_row++) {
        for (int counter_column = 0; counter_column < name_of_columns.size(); counter_column++) {
            std::cout << std::internal << std::setw(size_of_columns.at(counter_column)) << data_of_table.at(counter_row).at(counter_column);
        }
    }
}

class Lesson_1 {
private:
    variables_lesson_1_1 first;
    variables_lesson_1_2 second;
    variables_lesson_1_3 third;
    variables_lesson_1_4 fourth;
    variables_lesson_1_5 fifth;
    variables_lesson_1_6 sixth;
public:

    void initializade_lesson_1() {
        std::cout << "Lesson 1 : \n";
        std::cout << "write s, t(integer)\n";
        std::cin >> first.s >> first.t;
        std::cout << "write x(double)\n";
        std::cin >> first.x;
    }
    void lesson_1_1() {
        double answer = double(tan(pow(first.x, 2)) + sqrt(first.x)) / (first.t * log10(first.x + first.s));
        std::cout << "answer at 1_1_1 is : \n";
        std::cout << answer << "\n";
    }

    void lesson_1_2() {
        double answer = double(1 + sqrt(first.s * first.x)) / pow((1 + pow(first.x, 3)), (1 / first.t));
        std::cout << "answer at 1_1_2 is : \n";
        std::cout << answer << "\n";
    }

    void lesson_1_3() {
        double answer = double(pow(M_E, (0.5 * first.x)) / (sqrt(first.x + first.s * log(pow(first.x, first.t)))));
        std::cout << "answer at 1_1_3 is : \n";
        std::cout << answer << "\n";
    }

    void lesson_1_4() {
        double answer = double((atan(pow(first.x, (1 / first.t)))) / (pow(first.x, 2) + first.s * sin(log(first.x))));
        std::cout << "answer at 1_1_4 is : \n";
        std::cout << answer << "\n";
    }

    void lesson_1_5() {
        double answer = double(pow(first.x, first.t) / (sqrt(pow(first.x, 3) + 1) + log(first.s)));
        std::cout << "answer at 1_1_5 is : \n";
        std::cout << answer << "\n";
    }

    void lesson_1_6() {
        double answer = double((pow(sin(pow(first.x, first.t)), 2)) / (log(pow(first.x, first.t)) * sqrt(1 + pow(first.x, first.s))));
        std::cout << "answer at 1_1_6 is : \n";
        std::cout << answer << "\n";
    }

    void lesson_1_7() {
        double answer = double((1 + pow(first.x, first.t)) / (log(pow(first.x, 3)) * sqrt(pow(first.x, first.s) + 1)));
        std::cout << "answer at 1_1_7 is : \n";
        std::cout << answer << "\n";
    }

    void lesson_1_8() {
        double answer = double((pow(cos(pow(first.x, 2)), 3)) / (first.s * sqrt(first.x)));
        std::cout << "answer at 1_1_8 is : \n";
        std::cout << answer << "\n";
    }

    void lesson_1_9() {
        double answer = double((pow(first.x, 2)) / (log(pow(first.x, first.t)) + pow(cos(pow(first.x, (1 / first.s))), 2)));
        std::cout << "answer at 1_1_9 is : \n";
        std::cout << answer << "\n";
    }
    void lesson_1_10() {
        double answer = double(sqrt(first.t) * ((3 * pow(first.x, first.t)) / sqrt(1 + pow(first.x, first.s))));
        std::cout << "answer at 1_1_10 is : \n";
        std::cout << answer << "\n";
    }

    void lesson_1_11() {
        double answer = double((pow((first.t + pow(first.x, 3)), (1 / first.s))) / (log(pow(first.x, first.t))));
        std::cout << "answer at 1_1_11 is : \n";
        std::cout << answer << "\n";
    }

    void lesson_1_12() {
        double answer = double((pow((1 + pow(first.x, 2)), (1 / first.t))) / (pow(M_E, (sin(first.x) + first.s))));
        std::cout << "answer at 1_1_12 is : \n";
        std::cout << answer << "\n";
    }


    void initializade_lesson_2() {
        std::cout << "Lesson 2 : \n";
        std::cout << "\nwrite x, y(double)\n";
        std::cin >> second.x >> second.y;
    }

    void lesson_2() {
        if (second.y >= 0) {
            if ((second.x >= second.y) && (second.y >= (pow((second.x - 2), 2) - 3))) {
                std::cout << "Funtion includes point(x, y)\n";
            }
            else {
                std::cout << "Function don't include point(x, y)\n";
            }
        }
        else if (second.y < 0) {
            if ((abs(second.y) >= second.x) && (second.y >= (pow((second.x - 2), 2) - 3))) {
                std::cout << "Funtion includes point(x, y)\n";
            }
            else {
                std::cout << "Function don't include point(x, y)\n";
            }
        }
        else {
            std::cout << "Function don't include point(x, y)\n";
        }
    }


    void initializade_lesson_3() {
        std::cout << "Lesson 3 : \n";
        std::cout << "\nwrite x1, x2, x3, x4(double)\n";
        std::cin >> third.x1 >> third.x2 >> third.x3 >> third.x4;
    }

    void lesson_3() {

        if (third.x4 > third.x3) {                             //if loop 
            double x_3_new, x_4_new;
            x_3_new = third.x4;
            x_4_new = third.x3;
            third.x3 = x_3_new;
            third.x4 = x_4_new;
        }

        double x_2_new, x_1_new;
        x_2_new = (third.x1 > third.x2) ? third.x1 : third.x2;             // ternary operator 
        x_1_new = (third.x1 > third.x2) ? third.x2 : third.x1;
        third.x2 = x_2_new;
        third.x1 = x_1_new;

        if (third.x3 > third.x2) {                             // if loop
            double x_2_new, x_3_new;
            x_2_new = third.x3;
            x_3_new = third.x2;
            third.x3 = x_3_new;
            third.x2 = x_2_new;
        }

        double x_3_new, x_4_new;
        x_3_new = (third.x4 > third.x3) ? third.x4 : third.x3;             // ternary operator 
        x_4_new = (third.x4 > third.x3) ? third.x3 : third.x4;
        third.x3 = x_3_new;
        third.x4 = x_4_new;

        std::cout << " x1 = ";
        std::cout << third.x1 << "\n";
        std::cout << " x2 = ";
        std::cout << third.x2 << "\n";
        std::cout << " x3 = ";
        std::cout << third.x3 << "\n";
        std::cout << " x4 = ";
        std::cout << third.x4 << "\n";
        std::cout << "\n";
    }

    void initializade_lesson_4() {
        std::cout << "Lesson 4 : \n";
        std::cout << "\nwrite k, l (elephant) and m, n (horse) :\n";
        std::cin >> fourth.k >> fourth.l >> fourth.m >> fourth.n;
    }

    void lesson_4() {
        if (((abs(fourth.k - fourth.m) == 2) && (abs(fourth.l - fourth.n) == 1)) || ((abs(fourth.k - fourth.m) == 1) && (abs(fourth.l - fourth.n) == 2))) {
            std::cout << "horse beat elephant\n";
        }
        else if (abs(fourth.k - fourth.m) == abs(fourth.l - fourth.n)) {
            std::cout << "elephant beat horse\n";
        }
        else {
            std::cout << "No enyone beat each other \n";
        }
    }

    void initializade_lesson_5() {
        std::cout << "Lesson 5 : \n";
        std::cout << "x1, y1, x2, y2 and x3, y3, x4, y4:\n";
        std::cin >> fifth.x1 >> fifth.y1;
        std::cin >> fifth.x2 >> fifth.y2;
        std::cin >> fifth.x3 >> fifth.y3;
        std::cin >> fifth.x4 >> fifth.y4;
    }

    void lesson_5() {
        if ((fifth.y2 - fifth.y4 >= 0) && (fifth.y3 - fifth.y1 >= 0) && (fifth.x2 - fifth.x4 >= 0) && (fifth.x3 - fifth.x1 >= 0)) {
            std::cout << "Big square include small square\n";
        }
        else {
            std::cout << "Big square don't include small square\n";
        }
    }

    void initializade_lesson_6() {
        std::cout << "Lesson 5 : \n";
        std::cout << "Write 'n' unsigned long \n";
        std::cin >> sixth.n;
    }

    void lesson_6() {
        std::cout << "This number in binary representation is : \n";
        std::cout << binary_repesentation(sixth.n) << "\n";
        std::cout << "Zero bit is : \n";
        std::cout << ((sixth.n) & 1) << "\n";
        std::cout << "First bit is : \n";
        std::cout << ((sixth.n >> 1) & 1) << "\n";
        std::cout << "Fifteens bit is : \n";
        std::cout << ((sixth.n >> 15) & 1) << "\n";
        std::cout << "Inverted 1 and 10 bits are: \n";
        std::cout << (sixth.n ^ 1026) << "\n";
    }
};


//VARIANT 10

class Lesson_2 {
private:
    variables_lesson_2_1_1 first_1;
    variables_lesson_2_1_2 first_2;
    variables_lesson_2_2 second;
    double x_for_lesson_4;
    int k_for_lesson_6;
    variables_lesson_2_7 seventh;
public:
    void initializade_lesson_1_1() {
        std::cout << "Lesson 1 : \n";
        std::cout << "Write n(long int) and k(number of repetitions)\n";
        std::cin >> first_1.n >> first_1.k;
    }
    void lesson_1_1() {
        unsigned long new_n = first_1.n;
        short counter_zero = 0;
        short counter_one = 0;
        short counter_two = 0;
        short counter_three = 0;
        short counter_four = 0;
        short counter_five = 0;
        short counter_six = 0;
        short counter_seven = 0;
        short counter_eight = 0;
        short counter_nine = 0;
        do {
            int int_part_of_number = new_n % 10;
            new_n = new_n / 10;
            switch (int_part_of_number) {
            case 1:
                counter_one += 1;
                break;
            case 2:
                counter_two += 1;
                break;
            case 3:
                counter_three += 1;
                break;
            case 4:
                counter_four += 1;
                break;
            case 5:
                counter_five += 1;
                break;
            case 6:
                counter_six += 1;
                break;
            case 7:
                counter_seven += 1;
                break;
            case 8:
                counter_eight += 1;
                break;
            case 9:
                counter_nine += 1;
                break;
            default:
                counter_zero += 1;

            }
        } while (new_n >= 9);
        if (first_1.k <= counter_one) {
            std::cout << "Number contains more than 'k' equal numbers\n";
            std::cout << "They are ones\n";
        }
        else if (first_1.k <= counter_two) {
            std::cout << "Number contains more than 'k' equal numbers\n";
            std::cout << "They are twoes\n";
        }
        else if (first_1.k <= counter_three) {
            std::cout << "Number contains more than 'k' equal numbers\n";
            std::cout << "They are threes\n";
        }
        else if (first_1.k <= counter_four) {
            std::cout << "Number contains more than 'k' equal numbers\n";
            std::cout << "They are fours\n";
        }
        else if (first_1.k <= counter_five) {
            std::cout << "Number contains more than 'k' equal numbers\n";
            std::cout << "They are fives\n";
        }
        else if (first_1.k <= counter_six) {
            std::cout << "Number contains more than 'k' equal numbers\n";
            std::cout << "They are sixes\n";
        }
        else if (first_1.k <= counter_seven) {
            std::cout << "Number contains more than 'k' equal numbers\n";
            std::cout << "They are sevens\n";
        }
        else if (first_1.k <= counter_eight) {
            std::cout << "Number contains more than 'k' equal numbers\n";
            std::cout << "They are eights\n";
        }
        else if (first_1.k <= counter_nine) {
            std::cout << "Number contains more than 'k' equal numbers\n";
            std::cout << "They are nines\n";
        }
        else if (first_1.k <= counter_zero) {
            std::cout << "Number contains more than 'k' equal numbers\n";
            std::cout << "They are zeroes\n";
        }
        else {
            std::cout << "Number don't consists of more than 'k' equal numbers\n";
        }
    }
    void initializade_lesson_1_2() {
        std::cout << "Lesson 2 : \n";
        std::cout << "Write number(long double) and n(number of repetitions of fractal last numbers)\n";
        std::cin >> first_2.number >> first_2.n;
    }
    void lesson_1_2() {
        int numbers_of_fraction = round(int((first_2.number - int(first_2.number)) * 100000000));
        while ((numbers_of_fraction % 10) == 0) {
            numbers_of_fraction /= 10;
        }
        int inversed_numbers_of_fraction = rotation(numbers_of_fraction);
        int remainder = inversed_numbers_of_fraction % 10;
        inversed_numbers_of_fraction /= 10;
        int counter = 1;
        while (remainder == inversed_numbers_of_fraction % 10) {
            inversed_numbers_of_fraction /= 10;
            counter++;
        }
        if (counter >= first_2.n) {
            std::cout << "This long double include 'n' first equal numbers in it's fractal \n";
        }
        else {
            std::cout << "This long double don't include 'n' first equal numbers in it's fractal \n";
        }
    }
    void initializade_lesson_2() {
        std::cout << "Enter zero_X(double), X_n(double), delta_x(double) \n";
        std::cin >> second.x_0 >> second.x_n >> second.d_x;

    }
    void lesson_2() {
        double current_x = second.x_0;
        do {
            double answer = 1;
            double sum = 1;
            int counter = 1;
            while (abs(answer) > min_accuracy) {
                answer = (counter % 2 == 1) ? -pow(current_x, (counter * 2)) : pow(current_x, (counter * 2));           // 1 - x^2 + x^4 - x^6 + ... 
                counter++;
                sum += answer;
            }
            std::cout << "the answer at 'x' equal to " << current_x << " is : " << sum << "\n";
            current_x += second.d_x;
        } while (current_x < second.x_n);
    }
    void lesson_3() {
        for (int a = 1000; a <= 9999; a++) {
            int reversed = rotation(a);
            if (simpleNumber(reversed) && simpleNumber(a)) {
                std::cout << a << " is super simple \n";
            }
        }
    }

    void initializade_lesson_4() {
        std::cout << "Enter x (0 < x < 1) \n";
        std::cin >> x_for_lesson_4;
    }
    void lesson_4() {
        double answer = 1;
        double sum = 0;
        int itteration_number = 1;
        while (answer >= min_accuracy) {
            answer = (pow((-1), itteration_number) * pow(x_for_lesson_4, (itteration_number + 2))) / ((factorial(itteration_number + 2)) * (itteration_number + 1));
            itteration_number++;
            sum += answer;
        }
        std::cout << "Sum of infinity elements is : " << sum << "\n iterration is :" << itteration_number << "\n";
    }

    void initializade_and_work_lesson_5() {
        int n;
        std::cout << "Write number of numbers in this sequence \n";
        std::cin >> n;
        std::cout << "Write sequences \n";
        int counter = 1;
        int current_pow = -1;
        std::vector<int> max_pow;
        max_pow.resize(n + 1);
        int counter_of_pow = 0;
        for (int a = 0; a < +n; a++) {
            std::cout << "Write " << counter << " element \n";
            int number;
            std::cin >> number;
            if (current_pow == -1) {
                for (int a = 0; a <= max_power; a++) {
                    if (number == pow(3, a)) {
                        current_pow = a;
                        counter_of_pow++;
                    }
                }
            }
            else {
                if (number == pow(3, (current_pow + 1))) {
                    counter_of_pow++;
                    current_pow++;
                }
                else {
                    bool find = 0;
                    for (int a = 0; a <= max_power; a++) {
                        if (number == pow(3, a)) {
                            current_pow = a;
                            max_pow.push_back(counter_of_pow);
                            counter_of_pow = 1;
                            find = true;
                        }
                    }
                    if (!find) {
                        max_pow.push_back(counter_of_pow);
                        current_pow = -1;
                        counter_of_pow = 0;
                    }
                }
            }
            counter++;
        }
        std::cout << "Max reiterrated number is: " << *max_element(max_pow.begin(), max_pow.end()) << "\n";
    }
    void initializade_lesson_6() {
        std::cout << "Write 'k' number of sequence \n";
        std::cin >> k_for_lesson_6;
    }
    void lesson_6() {
        int current_number = 1;
        int counter = 0;
        int answer = 0;
        while (counter < k_for_lesson_6) {
            int number = rotation(pow(current_number, 2));
            if (number > 9) {
                while ((number / 10) > 0) {
                    counter++;
                    answer = number % 10;
                    if (counter == k_for_lesson_6) {
                        goto ANS;
                    }
                    number = (number / 10);
                }
                answer = number;
                if (counter == k_for_lesson_6) {
                    goto ANS;
                }
                counter++;
                current_number++;
            }
            else {
                counter++;
                if (counter == k_for_lesson_6) {
                    answer = pow(current_number, 2);
                    goto ANS;
                }
                current_number++;
            }
        }
    ANS:
        std::cout << "Answer is : " << answer << "\n";
    }
    void initialization_lesson_7() {
        std::cout << "Write numbers x_0(start point), x_m(end_point), delta_x(step of x) \n";
        std::cin >> seventh.x_0 >> seventh.x_m >> seventh.delta_x;
        std::cout << "And also write n \n";
        std::cin >> seventh.n;
    }

    void lesson_7() {
        // Gorner's scheme 
        double count_of_x = seventh.x_m;
        while (count_of_x >= seventh.x_0) {
            int power_of_two = 2 * seventh.n;
            double answer = double(power_of_two);
            double count_of_repetitions = seventh.n;
            int counter_of_pluses = 0;
            int counter_of_multiplication = 0;
            while ((count_of_repetitions > 1) && (power_of_two > 2)) {
                power_of_two -= 2;
                answer += ((answer) * pow(count_of_x, 2)) + (power_of_two);
                counter_of_pluses += 2;
                counter_of_multiplication++;
                count_of_repetitions--;
            }
            answer = (answer * count_of_x) + 5;
            std::cout << "Answer in Gorner's scheme in x equal to " << count_of_x << " is : " << answer << " and counter of pluses is '" << counter_of_pluses << "' and counter of multiplication is '" << counter_of_multiplication << "' \n";
            count_of_x -= seventh.delta_x;
        }
        count_of_x = seventh.x_m;
        while (count_of_x >= seventh.x_0) {
            double answer = 0;
            int counter_of_pluses = 0;
            int counter_of_multiplication = 0;
            double count_of_repetitions = seventh.n;
            while (count_of_repetitions > 0) {
                answer += ((2 * count_of_repetitions) * pow(count_of_x, ((2 * count_of_repetitions) - 1)));
                counter_of_pluses++;
                counter_of_multiplication += 3;
                count_of_repetitions--;
            }
            answer += 5;
            std::cout << "Answer in simple summing in " << count_of_x << " is : " << answer << " and counter of pluses is '" << counter_of_pluses << "' and counter of multiplication is '" << counter_of_multiplication << "' \n";
            answer = 0;
            count_of_x -= seventh.delta_x;
        }
    }
};

class Lesson_3 {
private:
    variables_lesson_3_1 first;
    variables_lesson_3_2 second;
    variables_lesson_3_3 third;
    variables_lesson_3_4 fourth;
    variables_lesson_3_5 fifth;
    variables_lesson_3_7 seventh;
public:
    void initializade_lesson_1() {
        std::cout << "Write numbers of int in your array \n";
        std::cin >> first.number_of_array;
        for (int a = 0; a < first.number_of_array; a++) {
            int number;
            std::cin >> number;
            first.array_of_int.push_back(number);
        }
    }
    void leeson_1() {
        std::vector <std::vector <int>> Two_dimensional_increasing_array;
        std::vector <int> increasing_array;
        bool counter_of_containing_something_in_increasing = false;
        for (int a = 0; a < first.number_of_array - 1; a++) {
            if (counter_of_containing_something_in_increasing == false) {
                if (first.array_of_int.at(a) <= first.array_of_int.at(a + 1)) {
                    if (a != first.number_of_array - 2) {
                        increasing_array.push_back(first.array_of_int.at(a));
                        counter_of_containing_something_in_increasing = true;
                    }
                    else {
                        increasing_array.push_back(first.array_of_int.at(a));
                        increasing_array.push_back(first.array_of_int.at(a + 1));
                        Two_dimensional_increasing_array.push_back(increasing_array);
                        increasing_array.clear();
                    }
                }
            }
            else if (counter_of_containing_something_in_increasing == true) {
                if (first.array_of_int.at(a) <= first.array_of_int.at(a + 1)) {
                    if (a != first.number_of_array - 1) {
                        increasing_array.push_back(first.array_of_int.at(a));
                    }
                    else {
                        increasing_array.push_back(first.array_of_int.at(a));
                        increasing_array.push_back(first.array_of_int.at(a + 1));
                        Two_dimensional_increasing_array.push_back(increasing_array);
                        increasing_array.clear();
                    }
                }
                else {
                    counter_of_containing_something_in_increasing = false;
                    Two_dimensional_increasing_array.push_back(increasing_array);
                    increasing_array.clear();
                }
            }
        }
        if (Two_dimensional_increasing_array.size() != 0) {
            std::vector <int> sizes_of_increasing;
            for (int a = 0; a < int(Two_dimensional_increasing_array.size()); a++) {
                sizes_of_increasing.push_back(Two_dimensional_increasing_array.at(a).size());
            }
            int max_increasing = findMax(sizes_of_increasing);
            for (int a = 0; a < int(Two_dimensional_increasing_array.size()); a++) {
                if (max_increasing == Two_dimensional_increasing_array.at(a).size()) {
                    std::cout << "The largest increasing array is ";
                    for (int b = 0; b < int(Two_dimensional_increasing_array.at(a).size()); b++) {
                        std::cout << Two_dimensional_increasing_array.at(a).at(b) << " ";
                    }
                    std::cout << " \n";
                }
            }
        }
        else {
            std::cout << "There is no increasing elements \n";
        }
    }

    void initializade_lesson_2() {
        std::cout << "Write the number of rows and colums \n";
        std::cin >> second.number_of_elements;
        for (int colums_number = 0; colums_number < second.number_of_elements; colums_number++) {
            for (int rows_number = 0; rows_number < second.number_of_elements; rows_number++) {
                std::vector<int> vec(second.number_of_elements, 0);
                second.matrix.push_back(vec);
            }
        }
        std::cout << "Do you want to initialize this matrix with your own hands (1 - YES, 0 - NO) \n";
        bool answer;
        std::cin >> answer;
        if (answer) {
            for (int colums_number = 0; colums_number < second.number_of_elements; colums_number++) {
                for (int rows_number = 0; rows_number < second.number_of_elements; rows_number++) {
                    std::cout << "Write number at colum " << colums_number + 1 << " and row " << rows_number + 1 << "\n";
                    int number;
                    std::cin >> number;
                    second.matrix.at(colums_number).push_back(number);
                }
            }
            std::cout << "You write array \n";
        }
        else {
            int c = 1;
            for (int colums_number = 0; colums_number < second.number_of_elements; colums_number++) {
                for (int rows_number = 0; rows_number < second.number_of_elements; rows_number++) {
                    second.matrix.at(colums_number).at(rows_number) = c;
                    c++;
                }
            }
        }
        for (int row = 0; row < second.number_of_elements; row++) {
            for (int column = 0; column < second.number_of_elements; column++) {
                std::cout << second.matrix.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }
    }

    void lesson_2() {
        std::vector <std::vector <int>> filled;

        // filling matrix with zeroes
        for (int i = 0; i < second.number_of_elements; i++) {
            std::vector <int> zero(second.number_of_elements, 0);
            filled.push_back(zero);
        }

        for (int i = 0; i < second.number_of_elements; i++) {
            for (int j = 0; j < second.number_of_elements; j++) {
                if (i + j < second.number_of_elements) {
                    std::vector <int> triangle_array;
                    for (int rows_number = 0; rows_number < second.number_of_elements; rows_number++) {
                        for (int colums_number = 0; colums_number < second.number_of_elements; colums_number++) {
                            if ((colums_number + rows_number < second.number_of_elements) && (colums_number >= j) && (rows_number >= i)) {
                                triangle_array.push_back(second.matrix.at(rows_number).at(colums_number));
                            }
                        }
                    }
                    filled.at(i).at(j) = findMax(triangle_array);
                }  else {
                    std::vector <int> triangle_array;
                    for (int rows_number = 0; rows_number < second.number_of_elements; rows_number++) {
                        for (int colums_number = 0; colums_number < second.number_of_elements; colums_number++) {
                            if ((colums_number + rows_number >= second.number_of_elements) && (colums_number <= j) && (rows_number <= i)) {
                                triangle_array.push_back(second.matrix.at(rows_number).at(colums_number));
                            }
                        }
                    }
                    filled.at(i).at(j) = findMax(triangle_array);
                }
            }
        }
        std::cout << std::endl;

        // Write filled matrix
        for (int row = 0; row < second.number_of_elements; row++) {
            for (int column = 0; column < second.number_of_elements; column++) {
                std::cout << filled.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }
    }

    void initializade_lesson_3() {
        std::cout << "Enter the maximum number\n";
        std::cin >> third.max_number; // задаём до какого числа мы будем искать простые
    }
    void lesson_3() {
        std::vector <int> matrix;
        int numerator = 0;
        int number = 0;
        while (numerator < third.max_number) { // идем до x числа и ищем простые
            numerator++;
            for (int counter = numerator - 1; counter > 1; counter--) { // проверяем делится ли число на предшествующие
                if ((numerator % counter == 0) && (rotation(numerator) % counter == 0)) {
                    number++;
                }
            }
            if (number == 0) {
                matrix.push_back(numerator); // помещаем простое число в вектор
            }
            number = 0;
        }
        for (int counter = 0; counter < int(matrix.size()); counter++) {
            std::cout << matrix.at(counter) << " is the super prime number\n";
        }
    }

    void initializade_lesson_4() {
        std::cout << "Enter a number of column \n";
        std::cin >> fourth.numRow;
        std::cout << "Enter a number of row \n";
        std::cin >> fourth.numColumn;
    }

    void lesson_4() {
        std::vector<int> zero_column;
        std::vector<std::vector<int>> matrix;
        std::vector<int> zero(fourth.numColumn, 0);
        std::vector<std::vector<int>> sorted(fourth.numRow, zero);
        int i = 1;

        //fill old matrix with zeroes
        for (int row = 0; row < fourth.numRow; row++) {
            std::vector <int> zero_row(fourth.numColumn, 0);
            matrix.push_back(zero_row);
        }

        // fill matrix with
        std::cout << "Do you want to write it with your own hands (1 - Yes, 0 - No)\n";
        bool answer;
        std::cin >> answer;
        if (answer) {
            for (int colums_number = 0; colums_number < fourth.numRow; colums_number++) {
                for (int rows_number = 0; rows_number < fourth.numColumn; rows_number++) {
                    std::cout << "Write number at colum " << colums_number + 1 << " and row " << rows_number + 1 << "\n";
                    int number;
                    std::cin >> number;
                    matrix.at(colums_number).at(number);
                }
            }
            std::cout << "You write array \n";
        }
        else {
            std::cout << "Fill it with random numbers (1) fil it with increasing numbers (0)\n";
            std::cin >> answer;
            if (answer) {
                std::cout << "Write minimum element and maximum element \n";
                int min_element, max_element;
                std::cin >> min_element >> max_element;
                for (int row_number = 0; row_number < fourth.numRow; row_number++) {
                    for (int column_number = 0; column_number < fourth.numColumn; column_number++) {
                        matrix.at(row_number).at(column_number) = random(min_element, max_element);
                    }
                }
            }
            else {
                int c = 1;
                for (int colums_number = 0; colums_number < fourth.numRow; colums_number++) {
                    for (int rows_number = 0; rows_number < fourth.numColumn; rows_number++) {
                        matrix.at(colums_number).at(rows_number) = c;
                        c++;
                    }
                }
            }
        }
        

        // Writing matrix
        for (int row = 0; row < fourth.numRow; row++) {
            for (int column = 0; column < fourth.numColumn; column++) {
                std::cout << matrix.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }

        //sort matrix of minimal elements and it's indexes
        std::vector <int> array_of_indexes;
        std::vector <int> min_element_array;
        for (int row_of_old_matrix = 0; row_of_old_matrix < fourth.numRow; row_of_old_matrix++) { 
            min_element_array.push_back(findMin(matrix.at(row_of_old_matrix)));
            array_of_indexes.push_back(row_of_old_matrix);
        }

        for (int row = 0; row < fourth.numRow; row++) {
            for (int row1 = 0; row1 < fourth.numRow; row1++) {
                if (min_element_array.at(row1) < min_element_array.at(row)) {
                    std::swap(min_element_array.at(row), min_element_array.at(row1));
                    std::swap(array_of_indexes.at(row), array_of_indexes.at(row1));
                }
            }
        }

        for (int row = 0; row < fourth.numRow; row++) {
            for (int row1 = 0; row1 < fourth.numRow; row1++) {
                if (row == array_of_indexes.at(row1)) {
                    sorted.at(row1) = matrix.at(row);
                }
            }
            std::cout << std::endl;
        }

        std::cout << "And sorted matrix is : \n";
        for (int row = 0; row < fourth.numRow; row++) {
            for (int column = 0; column < fourth.numColumn; column++) {
                std::cout << sorted.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }
    }

    void initialize_lesson_5() {
        std::cout << "Write column number and rows number (1 number)\n";
        std::cin >> fifth.matrix_number;
        for (int colums_number = 0; colums_number < fifth.matrix_number; colums_number++) {
            for (int rows_number = 0; rows_number < fifth.matrix_number; rows_number++) {
                std::vector<int> vec(fifth.matrix_number, 0);
                fifth.matrix.push_back(vec);
            }
        }
        std::cout << "Do you want to write it with your own hands (1 - Yes, 0 - No)\n";
        bool answer;
        std::cin >> answer;
        if (answer) {
            for (int colums_number = 0; colums_number < fifth.matrix_number; colums_number++) {
                for (int rows_number = 0; rows_number < fifth.matrix_number; rows_number++) {
                    std::cout << "Write number at colum " << colums_number + 1 << " and row " << rows_number + 1 << "\n";
                    int number;
                    std::cin >> number;
                    fifth.matrix.at(colums_number).at(number);
                }
            }
            std::cout << "You write array \n";
        }
        else {
            std::cout << "Fill it with random numbers (1) fil it with increasing numbers (0)\n";
            std::cin >> answer;
            if (answer) {
                std::cout << "Write minimum element and maximum element \n";
                int min_element, max_element;
                std::cin >> min_element >> max_element;
                for (int row_number = 0; row_number < fifth.matrix_number; row_number++) {
                    for (int column_number = 0; column_number < fifth.matrix_number; column_number++) {
                        fifth.matrix.at(row_number).at(column_number) = random(min_element, max_element);
                    }
                }
            }
            else {
                int c = 1;
                for (int colums_number = 0; colums_number < fifth.matrix_number; colums_number++) {
                    for (int rows_number = 0; rows_number < fifth.matrix_number; rows_number++) {
                        fifth.matrix.at(colums_number).at(rows_number) = c;
                        c++;
                    }
                }
            }
        }
    }

    void lesson_5() {
        std::cout << "And 'A' matrix is : \n";
        for (int row = 0; row < fifth.matrix_number; row++) {
            for (int column = 0; column < fifth.matrix_number; column++) {
                std::cout << fifth.matrix.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }
        std::vector<std::vector<int>> new_matrix;
        for (int colums_number = 0; colums_number < fifth.matrix_number; colums_number++) {
            for (int rows_number = 0; rows_number < fifth.matrix_number; rows_number++) {
                std::vector<int> vec(fifth.matrix_number, 0);
                new_matrix.push_back(vec);
            }
        }
        for (int row_counter = 0; row_counter < fifth.matrix_number; row_counter++) {
            for (int column_counter = 0; column_counter < fifth.matrix_number; column_counter++) {
            int min_of_elements;
            int definer_of_row_or_column = abs(row_counter - column_counter);
            bool is_it_column = (row_counter <= column_counter);
            if (is_it_column) {
                min_of_elements = fifth.matrix.at(0).at(0);
                for (int row_index_counter = 0; row_index_counter < fifth.matrix_number; row_index_counter++) {
                    for (int column_index_counter = 0; column_index_counter < fifth.matrix_number; column_index_counter++) {
                        if (((row_index_counter + 1) + (fifth.matrix_number - (column_counter + 1))) >= definer_of_row_or_column) {
                            if (min_of_elements > fifth.matrix.at(row_index_counter).at(column_index_counter)) {
                                min_of_elements = fifth.matrix.at(row_index_counter).at(column_index_counter);
                            }
                        }
                    }
                }
            } else {
                min_of_elements = fifth.matrix.at(definer_of_row_or_column).at(0);
                for (int row_index_counter = 0; row_index_counter < fifth.matrix_number; row_index_counter++) {
                    for (int column_index_counter = 0; column_index_counter < fifth.matrix_number; column_index_counter++) {
                        if (((row_index_counter + 1) + (fifth.matrix_number - (column_counter + 1))) >= definer_of_row_or_column + fifth.matrix_number) {
                            if (min_of_elements > fifth.matrix.at(row_index_counter).at(column_index_counter)) {
                                min_of_elements = fifth.matrix.at(row_index_counter).at(column_index_counter);
                            }
                        }
                    }
                }
            }
            new_matrix.at(row_counter).at(column_counter) = min_of_elements;
            }
        }
        std::cout << "And 'B' matrix is : \n";
        for (int row = 0; row < fifth.matrix_number; row++) {
            for (int column = 0; column < fifth.matrix_number; column++) {
                std::cout << new_matrix.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }
    }

    void initialization_and_work_lesson_6() {
        int input;
        std::cout << "Write number to factorial\n";
        std::cin >> input;
        std::vector<int> array_factorial = huge_factorial(input);
        std::cout << "The factorial of that number is : ";
        for (int count = 0; count < array_factorial.size(); count++) {
            if (array_factorial.at(count)) {
                std::cout << array_factorial.at(count);
            }
        }
        std::cout << std::endl;
        std::cout << "And of threes in this code is: " << SomeNumberInAnother(array_factorial, 3) << std::endl;
    }

    int whatnum(int length, int row, int column) {
        int at_what = 0;
        for (int num = length; num > row; num--) {
            at_what += num;
        }
        at_what += abs(column - row) + 1;
        return at_what;
    }

    std::vector<std::vector<int>> two_dimetional_matrix(std::vector<int> start_vector, int length) {
        std::vector <std::vector<int>> new_matrix;
        for (int a = 0; a < length; a++) {
            std::vector<int> zero_vector(length, 0);
            new_matrix.push_back(zero_vector);
        }
        for (int row = 0; row < length; row++) {
            for (int column = 0; column < length; column++) {
                if (row <= column) {
                    new_matrix.at(row).at(column) = start_vector.at(whatnum(length, (length - row), (length - column)) - 1);
                }
                else {
                    new_matrix.at(row).at(column) = new_matrix.at(column).at(row);
                }
            }
        }
        return new_matrix;
    }

    void initializing_and_work_lesson_7() {
        std::cout << "Write max number of array\n";
        std::cin >> seventh.matrix_number;
        std::vector<int> new_vector(((seventh.matrix_number + 1) * seventh.matrix_number / 2), 0);
        std::vector<std::vector<int>> new_matrix;
        std::vector<std::vector<int>> full_matrix1;
        std::vector<std::vector<int>> full_matrix2;

        for (int a = 0; a < seventh.matrix_number; a++) {
            std::vector<int> zero_vector(seventh.matrix_number, 0);
            new_matrix.push_back(zero_vector);
        }

        std::cout << "Write first triangle array\n";
        for (int a = 0; a < (seventh.matrix_number + 1) * seventh.matrix_number / 2; a++) {
            int number;
            std::cin >> number;
            seventh.matrix_1.push_back(number);
        }

        std::cout << "Write second triangle array\n";
        for (int a = 0; a < (seventh.matrix_number + 1) * seventh.matrix_number / 2; a++) {
            int number;
            std::cin >> number;
            seventh.matrix_2.push_back(number);
        }

        full_matrix1 = two_dimetional_matrix(seventh.matrix_1, seventh.matrix_number);
        for (int row = 0; row < seventh.matrix_number; row++) {
            for (int column = 0; column < seventh.matrix_number; column++) {
                std::cout << full_matrix1.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }
        full_matrix2 = two_dimetional_matrix(seventh.matrix_2, seventh.matrix_number);
        for (int row = 0; row < seventh.matrix_number; row++) {
            for (int column = 0; column < seventh.matrix_number; column++) {
                std::cout << full_matrix2.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }
        for (int row = 0; row < seventh.matrix_number; row++) {
            for (int column = 0; column < seventh.matrix_number; column++) {
                int row_sum = 0;
                for (int local = 0; local < seventh.matrix_number; local++) {
                    row_sum += full_matrix1.at(row).at(local) * full_matrix2.at(local).at(column);
                }
                new_matrix.at(row).at(column) = row_sum;
            }
        }
        std::cout << "And sorted matrix is: \n";
        for (int row = 0; row < seventh.matrix_number; row++) {
            for (int column = 0; column < seventh.matrix_number; column++) {
                std::cout << new_matrix.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }
    }
};

int FromAnyToDec(int from, std::string start_number) {
    int converted_number = 0;
    int size_of_number = start_number.size();
    for (int counter = 0; counter < size_of_number; counter++) {
        switch (start_number.at(counter)) {
        case '1':
            converted_number += pow(from, (size_of_number - counter - 1));
            break;
        case '2':
            converted_number += 2 * pow(from, (size_of_number - counter - 1));
            break;
        case '3':
            converted_number += 3 * pow(from, (size_of_number - counter - 1));
            break;
        case '4':
            converted_number += 4 * pow(from, (size_of_number - counter - 1));
            break;
        case '5':
            converted_number += 5 * pow(from, (size_of_number - counter - 1));
            break;
        case '6':
            converted_number += 6 * pow(from, (size_of_number - counter - 1));
            break;
        case '7':
            converted_number += 7 * pow(from, (size_of_number - counter - 1));
            break;
        case '8':
            converted_number += 8 * pow(from, (size_of_number - counter - 1));
            break;
        case '9':
            converted_number += 9 * pow(from, (size_of_number - counter - 1));
            break;
        case 'A':
            converted_number += 10 * pow(from, (size_of_number - counter - 1));
            break;
        case 'B':
            converted_number += 11 * pow(from, (size_of_number - counter - 1));
            break;
        case 'C':
            converted_number += 12 * pow(from, (size_of_number - counter - 1));
            break;
        case 'D':
            converted_number += 13 * pow(from, (size_of_number - counter - 1));
            break;
        case 'E':
            converted_number += 14 * pow(from, (size_of_number - counter - 1));
            break;
        case 'F':
            converted_number += 15 * pow(from, (size_of_number - counter - 1));
            break;
        }
    }
    return converted_number;
}

std::string FromDecToAny(int from, int to) {
    std::string converted_number;
    while (from >= to) {
        int digit = from % to;
        switch (digit) {
        case 0:
            converted_number.push_back('0');
            break;
        case 1:
            converted_number.push_back('1');
            break;
        case 2:
            converted_number.push_back('2');
            break;
        case 3:
            converted_number.push_back('3');
            break;
        case 4:
            converted_number.push_back('4');
            break;
        case 5:
            converted_number.push_back('5');
            break;
        case 6:
            converted_number.push_back('6');
            break;
        case 7:
            converted_number.push_back('7');
            break;
        case 8:
            converted_number.push_back('8');
            break;
        case 9:
            converted_number.push_back('9');
            break;
        case 10:
            converted_number.push_back('A');
            break;
        case 11:
            converted_number.push_back('B');
            break;
        case 12:
            converted_number.push_back('C');
            break;
        case 13:
            converted_number.push_back('D');
            break;
        case 14:
            converted_number.push_back('E');
            break;
        case 15:
            converted_number.push_back('F');
            break;
        }
        from /= to;
    }
    switch (from) {
    case 0:
        converted_number.push_back('0');
        break;
    case 1:
        converted_number.push_back('1');
        break;
    case 2:
        converted_number.push_back('2');
        break;
    case 3:
        converted_number.push_back('3');
        break;
    case 4:
        converted_number.push_back('4');
        break;
    case 5:
        converted_number.push_back('5');
        break;
    case 6:
        converted_number.push_back('6');
        break;
    case 7:
        converted_number.push_back('7');
        break;
    case 8:
        converted_number.push_back('8');
        break;
    case 9:
        converted_number.push_back('9');
        break;
    case 10:
        converted_number.push_back('A');
        break;
    case 11:
        converted_number.push_back('B');
        break;
    case 12:
        converted_number.push_back('C');
        break;
    case 13:
        converted_number.push_back('D');
        break;
    case 14:
        converted_number.push_back('E');
        break;
    case 15:
        converted_number.push_back('F');
        break;
    }
    return converted_number;
}

std::string findrepeats(const std::string & in) {
    std::string answer;
    int asciiArray[256];
    char ch;
    int charconv;
    bool foundAny = false;
    for (int i = 0; i < 256; i++) asciiArray[i] = 0;
    for (unsigned int i = 0; i < in.length(); i++)
    {
        ch = in[i];
        charconv = static_cast<int>(ch);
        asciiArray[charconv]++;
    }
    for (unsigned int i = 0; i < 256; i++)
    {
        char static alreadyprinted;

        if (asciiArray[i] > 1)
        {
            foundAny = true;
            answer.push_back(static_cast<char>(i));
        }
    }
    return answer;
}

std::vector<std::string> find_words_in_string() {
    std::vector<std::string> list_of_words;
    std::string word;
    std::cout << "Write string {in that case number of words} (also don't forget to add '#' in the end)\n";
    char number = '0';

    while (number != '#') {
        std::cin >> number;
        if (number != '#') {
            word.push_back(number);
        }
    }
    std::vector <int> counter_of_division_symbols = { 0 };
    std::vector <int> counter_of_length;

    // Finding counters where are dividing_symbols
    for (int counter = 0; counter < word.size(); counter++) {
        for (int counter_of_dividers = 0; counter_of_dividers < words_dividers.size(); counter_of_dividers++) {
            if (word.at(counter) == words_dividers.at(counter_of_dividers)) {
                counter_of_division_symbols.push_back(counter);
            }
        }
    }

    // Creating array of words length
    for (int counter = 0; counter < counter_of_division_symbols.size() - 1; counter++) {
        int number = (counter_of_division_symbols.at(counter + 1) - counter_of_division_symbols.at(counter) - 1);
        counter_of_length.push_back(number);
    }
    counter_of_length.at(0) += 1;

    // Creating array of words
    for (int counter = 0; counter < counter_of_length.size(); counter++) {
        std::string current_word;
        for (int word_count = counter_of_division_symbols.at(counter); word_count < counter_of_division_symbols.at(counter + 1); word_count++) {
            current_word.push_back(word.at(word_count));
        }
        list_of_words.push_back(current_word);
    }
    for (int counter = 1; counter < counter_of_length.size(); counter++) {
        list_of_words.at(counter).erase(list_of_words.at(counter).begin());
    }
    return list_of_words;
}

class Lesson_4 {
private:
    std::string word;
public:
    void initialization_and_working_lesson_1() {
        int counter_of_numbers = 0; int counter_of_ints = 0;
        std::vector<std::string> words_list = find_words_in_string();
        for (int counter_of_words = 0; counter_of_words < words_list.size(); counter_of_words++) {
            int number_size = 0; int digit_size = 0;
             
            int first_number = 0;
            for (int counter_of_digits = 0; counter_of_digits < numbers_list.size(); counter_of_digits++) {
                if (words_list.at(counter_of_words).at(0) == numbers_list.at(counter_of_digits)) {
                    first_number = numbers_list.at(counter_of_digits);
                }
            }

            if (first_number != 0) {
                for (int counter = 0; counter < words_list.at(counter_of_words).size(); counter++) {
                    for (int counter_of_digits = 0; counter_of_digits < numbers_list.size(); counter_of_digits++) {
                        if (words_list.at(counter_of_words).at(counter) == numbers_list.at(counter_of_digits)) {
                            digit_size++;
                        }
                    }
                    number_size++;
                }
                if (number_size == digit_size) {
                    counter_of_numbers++;
                }
            }
            else {
                if (words_list.at(counter_of_words).size() == 3) {
                    if ((words_list.at(counter_of_words).at(0) == 'i') && (words_list.at(counter_of_words).at(1) == 'n') && (words_list.at(counter_of_words).at(2) == 't')) {
                        counter_of_ints++;
                    }
                }
            }
        }
        if (counter_of_ints) {
            std::cout << "This string have number of int identifier : " << counter_of_ints << "\n";
        }
        else {
            std::cout << "This string doesn't have int identifiers \n";
        }
        if (counter_of_numbers) {
            std::cout << "This string have  : " << counter_of_numbers << " numbers \n";
        }
        else {
            std::cout << "This string doesn't have ints \n";
        }
    }

    void initialization_and_working_lesson_2() {
        std::cout << "Write 'q' system converted from and write system 'p' converted to (don't forget to add '#' in the end) :\n";
        int q = 0; int p = 0;
        std::cin >> q >> p;
        char number = '0';
        std::cout << "Write number in q-system\n";
        while (number != '#') {
            std::cin >> number;
            if (number != '#') {
                word.push_back(number);
            }
        }
        int dec_num = FromAnyToDec(q, word);
        std::cout << dec_num << "\n";
        std::string answer = FromDecToAny(dec_num, p);
        answer = rotation(answer);
        for (int counter = 0; counter < answer.size(); counter++) {
            std::cout << answer.at(counter);
        }
    }

    void initialization_and_working_lesson_3() {
        std::vector<std::vector<char>> list_of_words;
        std::cout << "Write string {in that case number of words} (also don't forget to add '#' in the end)\n";
        char number = '0';
        
        while (number != '#') {
            std::cin >> number;
            if (number != '#') {
                word.push_back(number);
            }
        }

        // Finding counters where are dividing_symbols
        std::vector <int> counter_of_division_symbols = { 0 };
        std::vector <int> counter_of_length;
        for (int counter = 0; counter < word.size(); counter++) {                                       
            for (int counter_of_dividers = 0; counter_of_dividers < words_dividers.size(); counter_of_dividers++) {
                if (word.at(counter) == words_dividers.at(counter_of_dividers)) {
                    counter_of_division_symbols.push_back(counter);
                }
            }
        }
        // Creating array of words length
        for (int counter = 0; counter < counter_of_division_symbols.size() - 1; counter++) {                 
            int number = (counter_of_division_symbols.at(counter + 1) - counter_of_division_symbols.at(counter) - 1);
            counter_of_length.push_back(number);
        }
        counter_of_length.at(0) += 1;

        // Creating array of words
        for (int counter = 0; counter < counter_of_length.size(); counter++) {                 
            std::vector<char> current_word;
            for (int word_count = counter_of_division_symbols.at(counter); word_count < counter_of_division_symbols.at(counter + 1); word_count++) {
                current_word.push_back(word.at(word_count));
            }
            list_of_words.push_back(current_word);
        }

        for (int counter = 1; counter < counter_of_length.size(); counter++) {
            list_of_words.at(counter).erase(list_of_words.at(counter).begin());
        }

        // Checking for repetition of any symbols and add them in vector
        std::vector<std::string> new_list_of_words;
        for (int counter_of_words = 0; counter_of_words < list_of_words.size(); counter_of_words++) {                                
            std::string string_word = std::string(list_of_words.at(counter_of_words).begin(), list_of_words.at(counter_of_words).end());
            std::string duplicate_symbols = findrepeats(string_word);
            std::string current_end_word; 
            // Delete repeated symbols from list
            for (int counter_of_letters = 0; counter_of_letters < string_word.size(); counter_of_letters++) {                         
                bool having_duplication = false;
                for (int counter_of_duplicate = 0; counter_of_duplicate < duplicate_symbols.size(); counter_of_duplicate++) {
                    if (string_word.at(counter_of_letters) == duplicate_symbols.at(counter_of_duplicate)) {
                        having_duplication = true;
                    }
                }
                if (!having_duplication) {
                    current_end_word.push_back(string_word.at(counter_of_letters));
                }
            }
            new_list_of_words.push_back(current_end_word);
        }

        // Write this list of words
        std::cout << "The new words are : \n";                                                                                   
        for (int counter_of_words = 0; counter_of_words < list_of_words.size(); counter_of_words++) {
            std::cout << "At " << counter_of_words + 1 << " is : " << new_list_of_words.at(counter_of_words) << "\n";
        }
    }
};

void cut_from_string(std::string &text, int start_position, int number_of_symbols) {
    text.erase(start_position, number_of_symbols);
}

double f1(double x) {
    return pow((x + 1), 2) - 5;
}

double f2(double x, double s) {
    return pow(x, 2) - pow(M_E, x) - 1.5 * s;
}

double integral_f(double x, double t) {
    return pow(sin(pow(x, t)), 2) / sqrt(1 + pow(x, 3));
}

class Lesson_5 {
private:
    variables_lesson_5_1 first;
public:
    void initialization_lesson_1() {
        std::cout << "Write simetrical matrix number (it should be odd)\n";
        std::cin >> first.matrix_number;
        for (int counter = 0; counter < pow(first.matrix_number, 2); counter++) {
            first.matrix.push_back(0);
        }
        std::cout << "Do you want to write it with your own hands (1 - Yes, 0 - No)\n";
        bool answer;
        std::cin >> answer;
        if (answer) {
            for (int counter = 0; counter < pow(first.matrix_number, 2); counter++) {
                std::cout << "Write number at colum " << counter + 1 << "\n";
                int number;
                std::cin >> number;
                first.matrix.at(counter);
            }
            std::cout << "You write array \n";
        }
        else {
            std::cout << "Fill it with random numbers (1) fil it with increasing numbers (0)\n";
            std::cin >> answer;
            if (answer) {
                std::cout << "Write minimum element and maximum element \n";
                int min_element, max_element;
                std::cin >> min_element >> max_element;
                for (int counter = 0; counter < pow(first.matrix_number, 2); counter++) {
                    first.matrix.at(counter) = random(min_element, max_element);
                }
            }
            else {
                int c = 1;
                for (int counter = 0; counter < pow(first.matrix_number, 2); counter++) {
                    first.matrix.at(counter) = c;
                    c++;
                }
            }
        }
    }

    void lesson_1() {
        int max_itterator = first.matrix_number - 1;
        int central_index = (max_itterator / 2);
        std::vector<std::vector<int>> new_matrix;
        int x = central_index, y = central_index;
        for (int counter = 0; counter < first.matrix_number; counter++) {
            std::vector <int> vector(first.matrix_number, 0);
            new_matrix.push_back(vector);
        }
        new_matrix.at(central_index).at(central_index) = first.matrix.at(0);
        int current_counter = 1;
        for (int step = 1; step <= (max_itterator / 2); step++) {
            for (int current_x = 1; current_x <= (step * 2) - 1; current_x++) {
                x++;
                new_matrix.at(y).at(x) = first.matrix.at(current_counter);
                current_counter++;
            }
            for (int current_y = 1; current_y <= (step * 2) - 1; current_y++) {
                y++;
                new_matrix.at(y).at(x) = first.matrix.at(current_counter);
                current_counter++;
            }
            for (int current_x = 1; current_x <= (step * 2); current_x++) {
                x--;
                new_matrix.at(y).at(x) = first.matrix.at(current_counter);
                current_counter++;
            }
            for (int current_y = 1; current_y <= (step * 2); current_y++) {
                y--;
                new_matrix.at(y).at(x) = first.matrix.at(current_counter);
                current_counter++;
            }
        }
        for (int current_x = 1; current_x <= max_itterator; current_x++) {
            x++;
            new_matrix.at(y).at(x) = first.matrix.at(current_counter);
            current_counter++;
        }
        std::cout << "And sorted matrix is: \n";
        for (int row = 0; row < first.matrix_number; row++) {
            for (int column = 0; column < first.matrix_number; column++) {
                std::cout << new_matrix.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }
    }

    void initialization_and_work_lesson_2() {
        std::string text;
        std::cout << "Write sentence (don't forget to add '#' in the end, also if you want to divide words - use '_' because ' ' as rule always filtered)\n";
        char number = '0';
        while (number != '#') {
            std::cin >> number;
            if (number != '#') {
                text.push_back(number);
            }
        }

        std::vector <int> position_of_quotes;
        for (int counter = 0; counter < text.size(); counter++) {
            if (text.at(counter) == '"') {
                position_of_quotes.push_back(counter);
            }
        }
        int length = position_of_quotes.at(position_of_quotes.size() - 1) - position_of_quotes.at(0);
        cut_from_string(text, position_of_quotes.at(0), length);
        std::cout << "New text is :" << text << "\n";
    }

    void initialization_and_work_lesson_3() {
        std::vector<std::string> list_of_words = find_words_in_string();
        // Find another knit words, but they starts with first word
        std::vector <std::string> new_text;
        bool is_it_first = true;
        for (int counter_of_last_words = 0; counter_of_last_words <= list_of_words.size(); counter_of_last_words++) {
            for (int counter_of_first_words = 0; counter_of_first_words < list_of_words.size(); counter_of_first_words++) {
                if ((counter_of_last_words != counter_of_first_words) && (list_of_words.at(counter_of_last_words).at(list_of_words.at(counter_of_last_words).size() - 1) == list_of_words.at(counter_of_first_words).at(0)) && is_it_first) {
                    std::string single_word_last = std::string(list_of_words.at(counter_of_last_words).begin(), list_of_words.at(counter_of_last_words).end());
                    std::string single_word_first = std::string(list_of_words.at(counter_of_first_words).begin(), list_of_words.at(counter_of_first_words).end());
                    new_text.push_back(single_word_last);
                    new_text.push_back(single_word_first);
                    is_it_first = false;
                }
                else if ((!is_it_first) && (new_text.at(new_text.size() - 1).at(new_text.at(new_text.size() - 1).size() - 1) == list_of_words.at(counter_of_first_words).at(0))) {
                    std::string single_word = std::string(list_of_words.at(counter_of_first_words).begin(), list_of_words.at(counter_of_first_words).end());
                    new_text.push_back(single_word);
                }
            }
        }
        std::cout << "The new text is : \n";
        if (new_text.size()) {
            for (int counter_of_words = 0; counter_of_words < new_text.size(); counter_of_words++) {
                std::cout << " " << new_text.at(counter_of_words);
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "Don't have enought words to make depended scheme\n";
        }
    }

    int& pointer_to_min_array_element(std::vector <int> &current_array) {
        // finding array of counter of repetitions 
        std::vector<int> array_of_repetitions(current_array.size(), 0);
        for (int first_num = 0; first_num < current_array.size(); first_num++) {
            for (int second_num = 0; second_num < current_array.size(); second_num++) {
                if (current_array.at(first_num) == current_array.at(second_num)) {
                    array_of_repetitions.at(first_num)++;
                    array_of_repetitions.at(second_num)++;
                }
            }
        }
        // find array of minimal elements indexes repetitions
        int min_element = array_of_repetitions.at(0);
        std::vector<int> min_element_array_indexes;
        for (int a = 1; a < array_of_repetitions.size(); a++) {
            if (array_of_repetitions.at(a) < min_element) {
                min_element = array_of_repetitions.at(a);
            }
        }
        for (int i = 0; i < array_of_repetitions.size(); i++) {
            if (array_of_repetitions.at(i) == min_element) {
                min_element_array_indexes.push_back(i);
            }
        }
        // find maximum of this elements
        int max_element = current_array.at(min_element_array_indexes.at(0));
        int index_of_max_element = min_element_array_indexes.at(0);
        for (int counter = 0; counter < current_array.size(); counter++) {
            for (int counter_of_minimal_element_indexes = 0; counter_of_minimal_element_indexes < min_element_array_indexes.size(); counter_of_minimal_element_indexes++) {
                if (counter == min_element_array_indexes.at(counter_of_minimal_element_indexes)) {
                    if (max_element < current_array.at(counter)) {
                        max_element = current_array.at(counter);
                        index_of_max_element = counter;
                    }
                }
            }
        }
        return current_array.at(index_of_max_element);
    }

    void initialization_and_work_lesson_4() {
        std::cout << "Write number that amount you want to rewrite\n";
        int k;
        std::cin >> k;
        std::cout << "Write number of elements in this array\n";
        int n;
        std::cin >> n;
        std::cout << "Do you want to initialize this array with your hands or with random elements? (1 - YES, 0 - NO)\n";
        bool ans;
        std::cin >> ans;
        std::vector <int> array_of_numbers;
        if (ans) {
            for (int counter = 0; counter < n; counter++) {
                int number;
                std::cin >> number; 
                array_of_numbers.push_back(number);
            }
        }
        else {
            std::cout << "Write maximum and minimum numbers\n";
            int min, max;
            std::cin >> min >> max;
            for (int counter = 0; counter < n; counter++) {
                array_of_numbers.push_back(random(min, max));
            }
        }
        for (int counter = 0; counter < n; counter++) {
            std::cout << array_of_numbers.at(counter) << "  ";
        }
        std::cout << std::endl;
        pointer_to_min_array_element(array_of_numbers) = k;
        for (int counter = 0; counter < n; counter++) {
            std::cout << array_of_numbers.at(counter) << "  ";
        }
        std::cout << std::endl;
    }

    double findRoot(double (*f)(double, double), int& counter, double s, double a = 0., double b = 2., double eps = 1e-6) {
        double t = 0;
        while (fabs(b - a) >= eps) {
            t = a + (f(b, s) * (b - a)) / (f(b, s) - f(a, s));  //2
            if (f(a, s) * f(t, s) < 0) {
                b = t;
            }
            else if (f(t, s) * f(b, s) < 0) {
                a = t;
            }
            else
                return t;
            counter++;
        }
        return t;
    }

    double findRoot(double (*f)(double), int& counter, double a = 0., double b = 2., double eps = 1e-6) {
        double t = 0;
        while (fabs(b - a) >= eps) {
            t = a + (f(b) * (b - a)) / (f(b) - f(a));  //2
            if (f(a) * f(t) < 0) {
                b = t;
            }
            else if (f(t) * f(b) < 0) {
                a = t;
            }
            else
                return t;
            counter++;
        }
        return t;
    }

    void initializade_and_work_lesson_5() {
        double a1 = 0, b1 = 2;
        double a2 = -1.5, b2 = 1;
        const double s_start = 0.9, s_end = 1.2, delta_s = 0.02;
        int counter = 0;
        std::cout << " X : " << "   F(X)   " << "  k_iter  " << "\n";
        double answer = findRoot(f1,counter, a1, b1, min_accuracy);
        std::cout << answer << "\t" << f1(answer) << "\t" << counter << "\t";
        std::cout << std::endl;
        std::cout << "     S :     " << "       X :      " << "        F(X) :       " << "       k_iter :      " << "\n";
        for (double counter_of_x = s_start; counter_of_x - 1000 * min_accuracy <= s_end; counter_of_x += delta_s) {
            int counter = 0;
            double answer = findRoot(f2, counter, counter_of_x, a2, b2, min_accuracy);
            std::cout << counter_of_x << "\t\t" << answer << "\t\t" << f2(answer, counter_of_x) << "\t\t" << counter << "\t\t";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    double simpsonIntegral(const double &a, const double &b, const double &t, int& counter, const double &epsilon, const std::function<double(double, double)>& f) {
        double max_height = pow(epsilon, (1 / 4));
        int number_of_itterations = (b - a) / max_height;
        do {
            number_of_itterations++;
        } while (number_of_itterations % 4 > 0);
        double current_height = (b - a) / number_of_itterations;
        double integral = 0, integral_of_two_n = 0;
        do {
            integral = 0; integral_of_two_n = 0;
            double even_sum = 0, odd_sum = 0;
            double current_even_sum = a + current_height, current_odd_sum = a + 2*current_height;
            int needed_number = (number_of_itterations - 2) / 2;
            for (int counter = 0; counter < needed_number; counter++) {
                even_sum += f(current_even_sum, t);
                current_even_sum += 2 * current_height;
                odd_sum += f(current_even_sum, t);
                current_odd_sum += 2 * current_height;
            }
            even_sum += f(current_even_sum, t);
            integral = (current_height / 3) * (f(a, t) + f(b, t) + 4 * even_sum + 2*odd_sum);
            even_sum = 0; odd_sum = 0;
            current_even_sum = a + 2 * current_height; current_odd_sum = a + 4 * current_height;
            needed_number = (number_of_itterations - 2) / 4;
            for (int counter = 0; counter < needed_number; counter++) {
                even_sum += f(current_even_sum, t);
                current_even_sum += 4 * current_height;
                odd_sum += f(current_even_sum, t);
                current_odd_sum += 4 * current_height;
            }
            even_sum += f(current_even_sum, t);
            integral_of_two_n = (2 * current_height / 3) * (f(a, t) + f(b, t) + 4*even_sum + 2 *odd_sum);
            counter = number_of_itterations;
            number_of_itterations *= 2;
            current_height = (b - a) / number_of_itterations;
        } while ((fabs(integral - integral_of_two_n) / 15) <= epsilon);
        return integral;
    }

    void lesson_6() {
        double s1 = 0, s2 = 1.0, delta_s = 0.2;
        double t1 = 1, t2 = 4.0, delta_t = 1;
        double b = 1.234;
        std::cout << "    s :    " << "    t :    " << "    Int    " << "    k_iter    " << "\n";
        for (double current_s = s1; current_s <= s2; current_s += delta_s) {
            for (double current_t = t1; current_t <= t2; current_t += delta_t) {
                int counter = 0;
                double integral = simpsonIntegral(current_s, b, current_t, counter, min_accuracy, integral_f);
                std::cout << std::internal << std::setw(5) << current_s << std::setw(10) << current_t << std::setw(15) << integral << std::setw(10) << counter << " \n";
            }
        }

    }
    
    void input_array(short* A, unsigned short n)
    {
        srand((unsigned)time(NULL));
        for (unsigned short i = 0; i < n; i++)
            A[i] = rand() % 200 - 100;
    }

    void output_array(short* A, unsigned short n)
    {
        for (unsigned short i = 0; i < n; i++)
            std::cout << A[i] << " ";
        std::cout << "\n";
    }

    void sort_bin_insert(int* a, int n) // 
    {
        int x, left, right, sred;
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] > a[i])
            {
                // x – включаемый элемент
                x = a[i];   
                // левая граница отсортированной части массива
                left = 0;   
                // правая граница отсортированной части массива 
                right = i - 1;  
                do {
                    // sred – новая "середина" последовательности
                    sred = (left + right) / 2; 
                    if (a[sred] < x) left = sred + 1;
                    // поиск ведется до тех пор, пока левая граница 
                    else right = sred - 1;
                } while (left <= right); 
                //не окажется правее правой границы
                for (int j = i - 1; j >= left; j--) a[j + 1] = a[j];
                a[left] = x;
            }
        }
    }

    // объявление параметра шаблона функции
    template <typename T> 
    void sort_bin_insert(std::vector <T> &input) // 
    {
        T x, left, right, middle;
        for (int counter = 1; counter < input.size(); counter++)
        {
            if (input.at(counter - 1) < input.at(counter))
            {
                // x – включаемый элемент
                x = input.at(counter);
                // левая граница отсортированной части массива
                left = 0;
                // правая граница отсортированной части массива 
                right = counter - 1;
                do {
                    // middle – новая "середина" последовательности
                    middle = (left + right) / 2;
                    if (input.at(middle) > x) {
                        left = middle + 1;
                    }
                    else {
                        right = middle - 1;
                    }
                    // поиск ведется до тех пор, пока левая граница не окажется правее правой границы 
                } while (left <= right);
                for (int border_counter = counter - 1; border_counter >= left; border_counter--) {
                    input.at(border_counter + 1) = input.at(border_counter);
                }
                input.at(left) = x;
            }
        }
    }

    // объявление параметра шаблона функции
    template <typename T> 
    void simple_choose_sort(std::vector <T> &array_of_T) {
        for (int startIndex = 0; startIndex < array_of_T.size() - 1; startIndex++)
        {
            // В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации.
            // Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
            T smallestIndex = startIndex;

            // Затем ищем элемент поменьше в остальной части массива
            for (int currentIndex = startIndex + 1; currentIndex < array_of_T.size(); currentIndex++)
            {
                // Если мы нашли элемент, который меньше нашего наименьшего элемента,
                if (array_of_T.at(currentIndex) > array_of_T.at(smallestIndex)) {
                    // то запоминаем его
                    smallestIndex = currentIndex;
                }
            }

            // smallestIndex теперь наименьший элемент. 
            // Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
            std::swap(array_of_T.at(startIndex), array_of_T.at(smallestIndex));
        }
    }

    template <typename T> // объявление параметра шаблона функции
    void output_array(std::vector <T> array_of)
    {
        for (unsigned short i = 0; i < array_of.size(); i++) {
            std::cout << array_of.at(i) << " ";
        }
        std::cout << "\n";
    }

    void lesson_7() {
        std::vector <int> numbers_array;
        std::vector <int> array_for_manipulations;
        std::cout << "Write size of your array\n";
        int size;
        std::cin >> size;
        std::cout << "Write how you want to initialize array. (1 - Own hands, 0 - another method)\n";
        bool answer;
        std::cin >> answer;
        if (answer) {
            for (int counter = 0; counter < size; counter++) {
                int number;
                std::cin >> number;
                std::cout << "There are " << size - counter << " indexes left ";
                numbers_array.push_back(number);
            }
        }
        else {
            std::cout << "How do you want to initialize this array(random - 0, increasing - 1, decreasing - 2)\n";
            int ans;
            std::cin >> ans;
            if (!ans) {
                std::cout << "Write minimum and maximum of random number\n";
                int min, max;
                std::cin >> min >> max;
                for (int counter = 0; counter < size; counter++) {
                    numbers_array.push_back(random(min, max));
                }
            }
            else if (ans == 1) {
                int c = 1;
                for (int counter = 0; counter < size; counter++) {
                    numbers_array.push_back(c);
                    c++;
                }
            }
            else if (ans == 2) {
                int c = numbers_array.size();
                for (int counter = 0; counter < size; counter++) {
                    numbers_array.push_back(c);
                    c--;
                }
            }
        }
        for (int counter = 0; counter < numbers_array.size(); counter++) {
            std::cout << numbers_array.at(counter) << " ";
        }
        std::cout << std::endl;
        array_for_manipulations = numbers_array;
        auto begin = std::chrono::steady_clock::now();
        sort_bin_insert(array_for_manipulations);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        output_array(array_for_manipulations);
        std::cout << std::endl;
        std::cout << "And binary insert sort takes " << elapsed_ms.count() << " microseconds\n";
        std::cout << std::endl;
        array_for_manipulations = numbers_array;
        auto begin_1 = std::chrono::steady_clock::now();
        simple_choose_sort(array_for_manipulations);
        auto end_1 = std::chrono::steady_clock::now();
        auto elapsed_ms_1 = std::chrono::duration_cast<std::chrono::microseconds>(end_1 - begin_1);
        output_array(array_for_manipulations);
        std::cout << std::endl;
        std::cout << "And simple choose sort takes " << elapsed_ms_1.count() << " microseconds\n";
    }

    template <typename T> // объявление параметра шаблона функции
    void merge(std::vector <T> &list, int l, int r) {
        if (r == l)
            return;
        if (r - l == 1) {
            if (list.at(r) < list.at(l))
                std::swap(list.at(r), list.at(l));
            return;
        }
        int m = (r + l) / 2;
        merge(list, l, m);
        merge(list, m + 1, r);
        std::vector<T> buffer(list.size(), 0);
        int xl = l;
        int xr = m + 1;
        int curve = 0;
        while (r - l + 1 != curve) {
            if (xl > m)
                buffer.at(curve++) = list.at(xr++);
            else if (xr > r)
                buffer.at(curve++) = list.at(xl++);
            else if (list.at(xl) > list.at(xr))
                buffer.at(curve++) = list.at(xr++);
            else buffer.at(curve++) = list.at(xl++);

        }
        for (int i = 0; i < curve; i++)
            list.at(i + l) = buffer.at(i);
    }

    void lesson_8() {
        std::vector <int> numbers_array;
        std::cout << "Write size of your array\n";
        int size;
        std::cin >> size;
        std::cout << "Write how you want to initialize array. (1 - Own hands, 0 - another method)\n";
        bool answer;
        std::cin >> answer;
        if (answer) {
            for (int counter = 0; counter < size; counter++) {
                int number;
                std::cin >> number;
                std::cout << "There are " << size - counter << " indexes left ";
                numbers_array.push_back(number);
            }
        }
        else {
            std::cout << "How do you want to initialize this array(random - 0, increasing - 1, decreasing - 2)\n";
            int ans;
            std::cin >> ans;
            if (!ans) {
                std::cout << "Write minimum and maximum of random number\n";
                int min, max;
                std::cin >> min >> max;
                for (int counter = 0; counter < size; counter++) {
                    numbers_array.push_back(random(min, max));
                }
            }
            else if (ans == 1) {
                int c = 1;
                for (int counter = 0; counter < size; counter++) {
                    numbers_array.push_back(c);
                    c++;
                }
            }
            else if (ans == 2) {
                int c = numbers_array.size();
                for (int counter = 0; counter < size; counter++) {
                    numbers_array.push_back(c);
                    c--;
                }
            }
        }
        output_array(numbers_array);
        merge(numbers_array, 0 , numbers_array.size() - 1);
        output_array(numbers_array);
    }
    
    void queens_controlling(variables_lesson_5_9 &coordinates, int &completed_figures) {
        if (completed_figures < 5) {
            for (int counter_of_row = 0; counter_of_row < 6; counter_of_row++) {
                for (int counter_of_column = 0; counter_of_column < 6; counter_of_column++) {
                    bool is_this_approach = true;
                    for (int figure_counter = 0; figure_counter < completed_figures; figure_counter++) {
                        if ((counter_of_row == coordinates.y.at(figure_counter)) || (counter_of_column == coordinates.x.at(figure_counter)) || ((counter_of_row + counter_of_column) == (coordinates.x.at(figure_counter) + coordinates.y.at(figure_counter))) || ((counter_of_row - counter_of_column) == (coordinates.y.at(figure_counter) - coordinates.x.at(figure_counter)))) {
                             is_this_approach = false;
                        }
                    }
                    if (is_this_approach) {
                        coordinates.x.at(completed_figures) = counter_of_column;
                        coordinates.y.at(completed_figures) = counter_of_row;
                        completed_figures++;
                        queens_controlling(coordinates, completed_figures);
                    }
                }
            }
        }
        else {
            return;
        }
    }

    void lesson_9() {
        variables_lesson_5_9 coordinates;
        coordinates.x = { 0,0,0,0,0 };
        coordinates.y = { 0,0,0,0,0 };
        int completed_figures = 1;
        queens_controlling(coordinates, completed_figures);
        for (int table_y_counter = 0; table_y_counter < 8; table_y_counter++) {
            for (int c = 0; c < 49; c++) { std::cout << "-"; }
            std::cout << std::endl;
            std::cout << "|     |     |     |     |     |     |     |     |\n";
            for (int table_x_counter = 0; table_x_counter < 8; table_x_counter++) {
                bool having = false;
                for (int position = 0; position < 5; position++) {
                    if ((coordinates.x.at(position) == table_x_counter) && (coordinates.y.at(position) == table_y_counter)) {
                        having = true;
                    }
                }
                if (having) {
                    std::cout << "|  *  ";
                }
                else {
                    std::cout << "|     ";
                }
            }
            std::cout << "|\n|     |     |     |     |     |     |     |     |\n";
        }
        for (int c = 0; c < 49; c++) { std::cout << "-"; }
    }
};

class Lesson_6 {
public:
    void lesson_1() {
        std::vector <double> n;
        std::ifstream fin("INPUT.txt");
        std::ofstream fout("OUTPUT.txt");
        if (fin) {
            while (fin.peek() != EOF)
            {
                double number;
                fin >> number;
                if (number > 1) {
                    fout << number << " ";
                }
                else {
                    n.push_back(number);
                }
            }
            for (int count = 0; count < n.size(); count++) {
                fout << n.at(count) << " ";
            }
            n.clear();
        }
        else {
            std::cout << "error input\n";
        }
        
        fin.close();
        fout.close();
    }
    
    void read_file(std::fstream& infile)
    {
        int v;
        infile.read(reinterpret_cast <char*> (&v), sizeof(int));
        while (!infile.eof()) // до достижения конца файла
        {
            std::cout << v << " " << "\n";

            // чтение элемента из файла infile.read
            infile.read(reinterpret_cast <char*>(&v), sizeof(int));
        }
    }

    double find_average(std::vector <int> grades) {
        int sum = 0;
        for (int counter = 0; counter < grades.size(); counter++) {
            sum += grades.at(counter);
        }
        return (sum / grades.size());
    }

    void made_list_of_best_graders() {
        std::fstream file("TABLE.txt", std::ios::in | std::ios::out);
        std::ofstream output("OUTPUT.txt");
        if (file.is_open()) {
            std::string line;
            std::vector <int> list_of_grades;
            while (getline(file, line)) {
                std::string FLF, gender;
                int years, stage, grades;
                std::istringstream read(line);
                read >> FLF >> years >> gender >> stage >> grades;
                list_of_grades.push_back(grades);
            }
            file.close();
            double average = find_average(list_of_grades);
            std::fstream file("TABLE.txt", std::ios::in | std::ios::out);
            while (getline(file, line)) {
                std::string FLF, gender;
                int years, stage, grades;
                std::istringstream read(line);
                read >> FLF >> years >> gender >> stage >> grades;
                if (double(grades) >= average) {
                    output << FLF << " " << years << " " << gender << " " << stage << " " << grades << " \n";
                }
            }
        }
        file.close();
        output.close();
    }

    void lesson_2() {
        int parcel = 1;
        std::fstream file("TABLE.txt", std::ios::in | std::ios::out);
        if (file.is_open()) {
            std::cout << "File is open\n";
            made_list_of_best_graders();
            std::cout << "List is done \n";
            while (parcel) {
                std::cout << "What do you want to do with file? (1 - write into main file, 2 - read main file, 3 - read new file,  0 - quit) \n";
                std::cin >> parcel;
                if (parcel == 2) {
                    std::ifstream file("TABLE.txt");
                    std::string line;
                    std::cout << std::internal << std::setw(20) << " NAME" << std::setw(20) << "YEARS" << std::setw(20) << "GENDER" << std::setw(20) << "STAGE" << std::setw(20) << "GRADES" << "\n";
                    while (getline(file, line)) {
                        std::string FLF, gender;
                        int years, stage, grades;
                        std::istringstream read(line);
                        read >> FLF >> years >> gender >> stage >> grades;
                        std::cout << std::internal << std::setw(20) << FLF << std::setw(20) << years << std::setw(20) << gender << std::setw(20) << stage << std::setw(20) << grades << "\n";
                    }
                }
                else if (parcel == 1) {
                    std::fstream file("TABLE.txt", std::ios::app);
                    std::string FLF, gender;
                    int years, stage, grades;
                    std::cout << "Write name of this person\n";
                    std::cin >> FLF;
                    std::cout << "Write age of this person\n";
                    std::cin >> years;
                    std::cout << "Write gender of this person\n";
                    std::cin >> gender;
                    std::cout << "Write course of this person\n";
                    std::cin >> stage;
                    std::cout << "Write grades of this person\n";
                    std::cin >> grades;
                    file << FLF << " " << years << " " << gender << " " << stage << " " << grades << " \n";
                    std::cout << "Changes are made \n";
                    made_list_of_best_graders();
                    std::cout << "New list is done \n";
                }
                else if (parcel == 3) {
                    std::fstream output("OUTPUT.txt", std::ios::in | std::ios::out);
                    std::string line;
                    std::cout << std::internal << std::setw(20) << " NAME" << std::setw(20) << "YEARS" << std::setw(20) << "GENDER" << std::setw(20) << "STAGE" << std::setw(20) << "GRADES" << "\n";
                    while (getline(output, line)) {
                        std::string FLF, gender;
                        int years, stage, grades;
                        std::istringstream read(line);
                        read >> FLF >> years >> gender >> stage >> grades;
                        std::cout << std::internal << std::setw(20) << FLF << std::setw(20) << years << std::setw(20) << gender << std::setw(20) << stage << std::setw(20) << grades << "\n";
                    }
                    output.close();
                }
            }
            file.close();
        }
    }

    struct pupil {
        unsigned short school_number : 9;
        unsigned short stage : 4;
        char class_name : 7;

    };

    union Utype {
        pupil student;
    };

    void display_this(Utype human) {
        std::cout << "School number of it is : " << human.student.school_number << "\n";
        std::cout << "Stage of it is         : " << human.student.stage << "\n";
        std::cout << "Class name of it is    : " << human.student.class_name << "\n";
        std::cout << std::endl;
    }

    void lesson_3() {
        int n;
        std::cout << "Write number of this structures\n";
        std::cin >> n;
        std::vector <Utype> array_of_human(n);
        std::map <int, int> map_of_some_number;

        // fill this array and display it
        for (int counter = 0; counter < n; counter++) {
            array_of_human.at(counter).student.school_number = rand() % 277 + 1;
            map_of_some_number[array_of_human.at(counter).student.school_number] = counter;
            array_of_human.at(counter).student.stage = rand() % 11 + 1;
            array_of_human.at(counter).student.class_name = rand() % 9 + 64;
            display_this(array_of_human.at(counter));
        }

        // sort it by elements
        std::cout << "And sorted is :\n";
        std::cout << std::endl;
        for (auto it = map_of_some_number.begin(); it != map_of_some_number.end(); it++) {
            display_this(array_of_human.at(int(it->second)));
        }
    }
};

class Lesson_7 {
private:

public:
    void filling_file_with_random_numbers(const int &number_of_numbers, const int& max_number, const int& min_number) {
        std::ofstream fout("INPUT.txt");
        for (int counter = 0; counter <= number_of_numbers; counter++) {
            fout << (rand() % max_number) + min_number << " ";
        }
        fout.close();
    }

    void lesson_1() {
        std::ifstream fin("INPUT.txt");
        std::ofstream fout("OUTPUT.txt");
        filling_file_with_random_numbers(int(pow(10, 7)), int(pow(10,4)), 0);
        std::cout << "File of random elements created\n";
        if (fin.is_open()) {
            std::vector <bool> input_of_counters(pow(10, 4), false);
            while (fin.peek() != EOF) {
                int number;
                fin >> number;
                if (!input_of_counters.at(number)) {
                    input_of_counters.at(number) = true;
                }
            }
            std::cout << "Output file created\n";
            for (int counter = 0; counter < input_of_counters.size(); counter++) {
                if (input_of_counters.at(counter)) {
                    fout << counter << " ";
                }
            }
            input_of_counters.clear();
        } else {
            std::cout << "error input\n";
        }
        fin.close();
        fout.close();
    }

    std::vector<std::vector<double>> initialization_of_some_square_matrix() {
        int size;
        std::cout << "Write size of this array\n";
        std::cin >> size;
        int answer;
        std::vector <double> zero_row(size, 0);
        std::vector<std::vector<double>> matrix(size, zero_row);
        do {
            std::cout << "What type of initialization do you want?   (0 - random, 1 - increasing, 2 - decreasing, 3 - own hands)\n";
            std::cin >> answer;
        } while (!((answer == 0) || (answer == 1) || (answer == 2) || (answer == 3)));
        if (answer == 3) {
            for (int row = 0; row < size; row++) {
                for (int column = 0; column < size; column++) {
                    double number;
                    std::cin >> number;
                    std::cout << "There are " << pow(size, 2) - (size * row) - column - 1 << " indexes left ";
                    matrix.at(row).at(column) = double(number);
                }
            }
        }
        else if (!answer) {
            std::cout << "Write minimum and maximum of random number\n";
            int min, max;
            std::cin >> min >> max;
            for (int row = 0; row < size; row++) {
                for (int column = 0; column < size; column++) {
                    matrix.at(row).at(column) = double(random(min, max));
                }
            }
        }
        else if (answer == 1) {
            int c = 1;
            for (int row = 0; row < size; row++) {
                for (int column = 0; column < size; column++) {
                    matrix.at(row).at(column) = double(c);
                    c++;
                }
            }
        }
        else if (answer == 2) {
            int c = matrix.size();
            for (int row = 0; row < size; row++) {
                for (int column = 0; column < size; column++) {
                    matrix.at(row).at(column) = double(c);
                    c--;
                }
            }
        }
        return matrix;
    }

    template <typename T>
    std::vector<std::vector<T>> create_square_matrix_from_row(const std::vector<T> &matrix_row, const int &size) {
        std::vector <T> zero_row(size, 0);
        std::vector<std::vector<T>> matrix(size, zero_row);
        int counter = 0;
        for (int row_counter = 0; row_counter < size; row_counter++) {
            for (int column_counter = 0; column_counter < size; column_counter++) {
                matrix.at(row_counter).at(column_counter) = matrix_row.at(counter);
                counter++;
            }
        }
        return matrix;
    }

    template <typename T>
    std::vector<std::vector<T>> square_matrix_in_some_power(const std::vector<std::vector <T>> &square_matrix, const int &power) {
        std::vector<std::vector<T>> new_matrix = square_matrix;
        std::vector<std::vector<T>> answer_matrix = square_matrix;
        for (int counter = 1; counter < power; counter++) {
            for (int row_counter = 0; row_counter < square_matrix.size(); row_counter++) {
                for (int column_counter = 0; column_counter < square_matrix.size(); column_counter++) {
                    int current_number = 0;
                    for (int row_column = 0; row_column < square_matrix.size(); row_column++) {
                        current_number += new_matrix.at(row_column).at(column_counter) * square_matrix.at(row_counter).at(row_column);
                    }
                    answer_matrix.at(row_counter).at(column_counter) = current_number;
                }
            }
            new_matrix = answer_matrix;
        }
        return answer_matrix;
    }

    template <typename T>
    T sum_of_diagonal_elements(const std::vector<std::vector<T>>& matrix) {
        T elements_sum = 0;
        for (int counter = 0; counter < matrix.size(); counter++) {
            elements_sum += matrix.at(counter).at(counter);
        }
        return elements_sum;
    }

    template <typename T>
    void output_matrix(std::vector<std::vector <T>> matrix) {
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix.at(0).size(); column++) {
                std::cout << matrix.at(row).at(column) << "\t";
            }
            std::cout << std::endl;
        }
    }

    void lesson_2() {
        std::vector <std::vector<double>> matrix = initialization_of_some_square_matrix();
        std::cout << "Matrix is: \n";
        output_matrix(matrix);
        std::cout << std::endl;
        std::cout << "Write max number of matrix powers\n";
        int n;
        std::cin >> n;
        for (int counter = 1; counter <= n; counter++) {
            std::vector<std::vector<double>> new_matrix = square_matrix_in_some_power(matrix, counter);
            std::cout << "If n = " << counter << "then matrix is : " << std::endl;
            output_matrix(new_matrix);
            std::cout << std::endl;
            std::cout << "Then sum of diagonal elements is : " << sum_of_diagonal_elements(new_matrix) << std::endl;
        }
    }

    struct list_of_studied{
        std::string name;
        std::string birth;
        int stage;
        int marks;
    };

    void alfabet_order(std::list <list_of_studied>& some_list) {
        std::map<std::string, int> names_in_list;
        int counter = 0;
        for (std::list<list_of_studied>::iterator it_1 = some_list.begin(); it_1 != some_list.end(); it_1++) {
            names_in_list[(*it_1).name] = counter;
            counter++;
        }
        std::list <list_of_studied> new_list;
        for (std::map<std::string,int>::iterator step = names_in_list.begin(); step != names_in_list.end(); step++) {
            std::list<list_of_studied>::iterator current = some_list.begin();
            for (int counter = 0; counter < step->second; counter++) {
                current++;
            }
            new_list.push_back(*current);

        }
    }

    void delete_from_list(std::list <list_of_studied> (&some_list), list_of_studied& info) {
        std::list <list_of_studied> another_list;
        std::list<list_of_studied>::iterator it;
        for (auto it = some_list.begin(); it != some_list.end(); it++) {
            if (std::tie((*it).name, (*it).birth, (*it).marks, (*it).stage) != std::tie(info.name, info.birth, info.marks, info.stage)) {
                another_list.push_back(*it);
            }
        }
        some_list = another_list;
    }

    bool is_this_birth_date(std::string birth) {
        bool answer = false;
        if (birth.size() == 10) {
            if ((birth.at(2) == '.') && (birth.at(5) == '.')) {
                answer = true;
                for (int counter = 0; counter < 10; counter++) {
                    if ((counter != 2) && (counter != 5)) {
                        if ((birth.at(counter) != '0') && (birth.at(counter) != '1') && (birth.at(counter) != '2') && (birth.at(counter) != '3') && (birth.at(counter) != '4') && (birth.at(counter) != '5') && (birth.at(counter) != '6') && (birth.at(counter) != '7') && (birth.at(counter) != '8') && (birth.at(counter) != '9')) {
                            answer = false;
                        }
                    }
                }
            }
        }
        return answer;
    }

    void add_to_list(std::list <list_of_studied>& some_list, list_of_studied& info) {
        some_list.push_back(info);
        alfabet_order(some_list);
    }

    list_of_studied asking_to_add_something() {
        list_of_studied some_list;
        std::cout << "Write it's name\n";
        std::cin >> some_list.name;
        std::cout << "Write it's birth date {00.00.0000}\n";
        std::cin >> some_list.birth;
        while (!is_this_birth_date(some_list.birth)) {
            std::cout << "You  write uncorrect birth, try again\n";
            std::cin >> some_list.birth;
        }
        std::cout << "Write it's course\n";
        std::cin >> some_list.stage;
        while (!((some_list.stage >= 0) && (some_list.stage <= 6))) {
            std::cout << "You  write uncorrect course, try again\n";
            std::cin >> some_list.stage;
        }
        std::cout << "Write it's marks\n";
        std::cin >> some_list.marks;
        while (!((some_list.marks >= 0) && (some_list.marks <= 10))) {
            std::cout << "You  write uncorrect marks, try again\n";
            std::cin >> some_list.marks;
        }
        return some_list;
    }

    int find_average_mark(std::list <list_of_studied>& some_list) {
        std::list<list_of_studied>::iterator it;
        int mark = 0;
        for (auto it = some_list.begin(); it != some_list.end(); it++) {
            mark += (*it).marks;
        }
        return int(mark / some_list.size());
    }

    std::list <list_of_studied> make_list_of_best(std::list <list_of_studied>& some_list, const int &average) {
        std::list <list_of_studied> list_of_best;
        std::list<list_of_studied>::iterator it;
        for (auto it = some_list.begin(); it != some_list.end(); it++) {
            if ((*it).marks > average) {
                list_of_best.push_back((*it));
            }
        }
        return list_of_best;
    }

    void output_data(std::list <list_of_studied>& some_list) {
        std::list<list_of_studied>::iterator it;
        std::cout << std::internal << std::setw(20) << " NAME" << std::setw(20) << "BIRTH" << std::setw(20) << "STAGE" << std::setw(20) << "MARKS" << "\n";
        for (auto it = some_list.begin(); it != some_list.end(); it++) {
            std::cout << std::internal << std::setw(20) << (*it).name << std::setw(20) << (*it).birth << std::setw(20) << (*it).stage << std::setw(20) << (*it).marks << "\n";
        }
    }

    void lesson_3() {
        std::list <list_of_studied> input;
        std::list <list_of_studied> list_of_best;
        int answer;
        std::cout << "Do you want to do something with information in this list (0 - end session, 1 - add someone)\n";
        std::cin >> answer;
        while (answer) {
            if (answer == 1) {
                list_of_studied some_list = asking_to_add_something();
                add_to_list(input, some_list);
            }
            std::cout << "Do you want another input?\n";
            std::cin >> answer;
        }
        std::cout << "List of all is:\n";
        output_data(input);
        int average = find_average_mark(input);
        std::cout << "\n The average mark is :" << average << "\n";
        list_of_best = make_list_of_best(input, average);
        std::cout << "The list of best is: \n";
        output_data(list_of_best);
        std::cout << "And the list of another is : \n";
        std::list<list_of_studied>::iterator it;
        for (auto it = list_of_best.begin(); it != list_of_best.end(); it++) {
            delete_from_list(input, (*it));
        }
        output_data(input);
    }

    int find_position_in_list(std::list<int> some_list, std::list<int> another_list, bool &having) {
        having = false;
        for (int counter = 0; counter < some_list.size(); counter++) {
            std::list<int>::iterator current = some_list.begin();
            std::advance(current, counter);
            if ((*current) == (*another_list.begin())) {
                bool having_at_all_list = true;
                for (int counter_new = 1; counter_new < another_list.size(); counter_new++) {
                    std::list<int>::iterator going_iterator = another_list.begin();
                    current = some_list.begin();
                    std::advance(current, counter);
                    if (counter + another_list.size() <= some_list.size()) {
                        std::advance(current, counter_new);
                        std::advance(going_iterator, counter_new);
                        if ((*current) != (*going_iterator)) {
                            having_at_all_list = false;
                        }
                    }
                    else {
                        having = false;
                        return some_list.size();
                    }
                }
                if (having_at_all_list) {
                    having = having_at_all_list;
                    return counter;
                }
            }
        }
        return some_list.size();
    }

    void input_in_list(std::list<int> (&some_list), const std::list<int>&list_to_delete, const std::list<int>&list_to_import) {
        bool having = true;
        int current_position = find_position_in_list(some_list, list_to_delete, having);
        if (having) {
            std::list<int>::iterator iterator = some_list.begin();
            std::advance(iterator, current_position);
            std::list<int>::iterator end_iterator = iterator;
            std::advance(end_iterator, list_to_delete.size() - 1);
            some_list.erase(iterator, end_iterator);
            iterator = some_list.begin();
            std::advance(iterator, current_position);
            some_list.insert(iterator, list_to_import.begin(), list_to_import.end());   
        }
        else {
            std::cout << "This list doesn't contain another list\n";
        }
    }

    void lesson_4() {
        std::list<int> input;
        bool answer; int length;
        std::cout << "Write the metod you will use to initialize list to input (0 - random, 1 - own hands)\n";
        std::cin >> answer; 
        std::cout << "Write length of input \n";
        std::cin >> length;
        if (!answer) {
            int min, max;
            std::cout << "Write minimum and maximum of randomizing\n";
            std::cin >> min >> max;
            for (int counter = 0; counter < length; counter++) {
                input.push_back(random(min, max));
            }
        }
        else {
            for (int counter = 0; counter < length; counter++) {
                int number;
                std::cin >> number;
                input.push_back(number);
            }
        }
        for (std::list<int>::iterator it_1 = input.begin(); it_1 != input.end(); it_1++) {
            std::cout << (*it_1) << " ";
        }
        std::list<int> list_to_delete;
        std::list<int> list_to_import;
        std::cout << std::endl << "Write number of symbols in deleting list\n";
        int size;
        std::cin >> size;
        std::cout << "Write this list\n";
        for (int counter = 0; counter < size; counter++) {
            int number;
            std::cin >> number;
            list_to_delete.push_back(number);
        }
        std::cout << std::endl << "Write number of symbols in importing list\n";
        
        std::cin >> size;
        std::cout << "Write this list\n";
        for (int counter = 0; counter < size; counter++) {
            int number;
            std::cin >> number;
            list_to_import.push_back(number);
        }
        input_in_list(input, list_to_delete, list_to_import);
        std::cout << "\nAnd new list is: \n";
        for (std::list<int>::iterator it = input.begin(); it != input.end(); it++) {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;
    }

    std::list<int> filling_list(const int &number) {
        std::list<int> input;
        std::cout << "Write the type of filling this list (0 - own hands, 1 - random, 2 - increasing, 3 - decreasing)\n";
        int answer;
        std::cin >> answer;
        switch (answer) {
        case 0: 
            for (int counter = 0; counter <= number; counter++) {
                int current_value;
                std::cin >> current_value;
                input.push_back(current_value);
            }
            break;
        case 1:
            int max, min;
            std::cout << "Write min and max \n";
            std::cin >> min >> max;
            for (int counter = 1; counter <= number; counter++) {
                input.push_back(random(min, max));
            }
            break;
        case 2:
            for (int counter = 1; counter <= number; counter++) {
                input.push_back(counter);
            }
            break;
        case 3:
            for (int counter = number; counter >= 1; counter--) {
                input.push_back(counter);
            }
            break;
        default:
            std::cout << "Error input\n";
            break;
        }
        return input;
    }

    void lesson_6() {
        int n;
        std::cout << "Write number of elements to list in size of two of numbers\n";
        std::cin >> n;
        std::list<int> input = filling_list(n * 2);
        std::cout << "And the full list is:\n";
        for (std::list<int>::iterator it = input.begin(); it != input.end(); it++) {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;
        std::vector<int> array_of_summing_numbers(n, 0);
        for (int counter = 0; counter < n; counter++) {
            array_of_summing_numbers.at(counter) = input.back() + input.front();
            input.pop_front();
            input.pop_back();
        }
        int index = findIndexMax(array_of_summing_numbers);
        std::cout << "Maximum number is: " << findMax(array_of_summing_numbers) << " And index of first and second elements are: "  << index + 1 << " and " << 2*n - index << "\n";
    }
    
    void lesson_7() {
    
    }
};

class Lesson_9 {
private:

public:
    void lesson_4() {
        std::vector<std::string >> identificators;
        std::ifstream fin("INPUT.txt");
        std::map<std::string, size_t> program_data;
        if (fin.is_open()) {
            while (fin.peek() != EOF) {
                
            }
        }
        else {
            std::cout << "error input\n";
        }
        for () {

        }
        fin.close();
    }
};

void INITIALIZING_LESSONS() {
    short lesson_num;
    short laboratory_num;
    std::cout << "What laboratory work do you want : \n";
    std::cin >> laboratory_num;
    std::cout << "What lesson number do you want : \n";
    std::cin >> lesson_num;
    if (laboratory_num == 1) {
        Lesson_1 lesson_1;
        switch (lesson_num) {
        case 1:
            lesson_1.initializade_lesson_1();
            lesson_1.lesson_1_1();
            lesson_1.lesson_1_2();
            lesson_1.lesson_1_3();
            lesson_1.lesson_1_4();
            lesson_1.lesson_1_5();
            lesson_1.lesson_1_6();
            lesson_1.lesson_1_7();
            lesson_1.lesson_1_8();
            break;
        case 2:
            lesson_1.initializade_lesson_2();
            lesson_1.lesson_2();
            break;
        case 3:
            lesson_1.initializade_lesson_3();
            lesson_1.lesson_3();
            break;
        case 4:
            lesson_1.initializade_lesson_4();
            lesson_1.lesson_4();
            break;
        case 5:
            lesson_1.initializade_lesson_5();
            lesson_1.lesson_5();
            break;
        case 6:
            lesson_1.initializade_lesson_6();
            lesson_1.lesson_6();
            break;
        default:
            std::cout << "Invalid input \n";
            break;
        }
    }
    else if (laboratory_num == 2) {
        Lesson_2 lesson_2;
        switch (lesson_num) {
        case 1:
            int page_num;
            std::cout << "What part do you want? \n";
            std::cin >> page_num;
            if (page_num == 1) {
                lesson_2.initializade_lesson_1_1();
                lesson_2.lesson_1_1();
            }
            else if (page_num == 2) {
                lesson_2.initializade_lesson_1_2();
                lesson_2.lesson_1_2();
            }
            else {
                std::cout << "Invalid input \n";
            }
            break;
        case 2:
            lesson_2.initializade_lesson_2();
            lesson_2.lesson_2();
            break;
        case 3:
            lesson_2.lesson_3();
            break;
        case 4:
            lesson_2.initializade_lesson_4();
            lesson_2.lesson_4();
            break;
        case 5:
            lesson_2.initializade_and_work_lesson_5();
            break;
        case 6:
            lesson_2.initializade_lesson_6();
            lesson_2.lesson_6();
            break;
        case 7:
            lesson_2.initialization_lesson_7();
            lesson_2.lesson_7();
            break;
        default:

            std::cout << "Invalid input \n";
            break;
        }
    }
    else if (laboratory_num == 3) {
        Lesson_3 lesson_3;
        switch (lesson_num) {
        case 1:
            lesson_3.initializade_lesson_1();
            lesson_3.leeson_1();
            break;
        case 2:
            lesson_3.initializade_lesson_2();
            lesson_3.lesson_2();
            break;
        case 3:
            lesson_3.initializade_lesson_3();
            lesson_3.lesson_3();
            break;
        case 4:
            lesson_3.initializade_lesson_4();
            lesson_3.lesson_4();
            break;
        case 5:
            lesson_3.initialize_lesson_5();
            lesson_3.lesson_5();
            break;
        case 6:
            lesson_3.initialization_and_work_lesson_6();
            break;
        case 7:
            lesson_3.initializing_and_work_lesson_7();
            break;
        default:
            std::cout << "Invalid input \n";
            break;
        }
    }
    else if (laboratory_num == 4) {
        Lesson_4 lesson_4;
        switch (lesson_num) {
        case 1:
            lesson_4.initialization_and_working_lesson_1();
            break;
        case 2:
            lesson_4.initialization_and_working_lesson_2();
            break;
        case 3:
            lesson_4.initialization_and_working_lesson_3();
            break;
        default:
            std::cout << "Invalid input \n";
            break;
        }
    }
    else if (laboratory_num == 5) {
        Lesson_5 lesson_5;
        switch (lesson_num) {
        case 1:
            lesson_5.initialization_lesson_1();
            lesson_5.lesson_1();
            break;
        case 2:
            lesson_5.initialization_and_work_lesson_2();
            break;
        case 3:
            lesson_5.initialization_and_work_lesson_3();
            break;
        case 4:
            lesson_5.initialization_and_work_lesson_4();
            break;
        case 5:
            lesson_5.initializade_and_work_lesson_5();
            break;
        case 6:
            lesson_5.lesson_6();
            break;
        case 7:
            lesson_5.lesson_7();
            break;
        case 8:
            lesson_5.lesson_8();
            break;
        case 9:
            lesson_5.lesson_9();
            break;
        default:
            std::cout << "Invalid input \n";
            break;
        }
    }
    else if (laboratory_num == 6) {
        Lesson_6 lesson_6;
        switch (lesson_num) {
        case 1:
            std::cout << "I changed pages 1,2,3 in lesson 4\n";
            break;
        case 2:
            lesson_6.lesson_1();
            break;
        case 3:
            lesson_6.lesson_2();
            break;
        case 4:
            lesson_6.lesson_3();
            break;
        default:
            std::cout << "Invalid input \n";
            break;
        }
    }
    else if (laboratory_num == 7) {
        Lesson_7 lesson_7;
        switch (lesson_num) {
        case 1:
            lesson_7.lesson_1();
            break;
        case 2:
            lesson_7.lesson_2();
            break;
        case 3:
            lesson_7.lesson_3();
            break;
        case 4:
            lesson_7.lesson_4();
            break;
        case 5:

            break;
        case 6:
            lesson_7.lesson_6();
            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        default:
            std::cout << "Invalid input \n";
            break;
        }
    } else {
        std::cout << "Invalid input \n";
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_CTYPE, ".1251");
    setlocale(LC_ALL, "Russian");
    INITIALIZING_LESSONS();
    system("pause");
    return 0;
}
