#include <limits>
#include <cstddef>
#include <string>
#include <bit>
#include <type_traits>
#include <sstream>
#include <iostream>

template <typename T>
requires std::is_signed_v <T>
std::string to_power_of_two(T val) {
    const bool negative = val < 0;
    using U = std::make_unsigned_t <T>;

    const U uval = negative ? static_cast <U> (- val) : static_cast <U> (val);
    const auto width = std::bit_width(uval) - negative;

    std::ostringstream ss;
    ss << (negative ? '-' : '+') << "2^" << width;
    if (! negative) {
        ss << "-1";
    }

    return ss.str ();
}

template <typename T>
requires std::is_unsigned_v <T>
std::string to_power_of_two(T val) {
    std::ostringstream ss;
    ss << "+2^" << std::bit_width(val) << "-1";
    return ss.str ();
}

template <typename T>
void print(const std::string &name) {
    std::cout << "**** " << name <<  " ****" << std::endl;
    if constexpr (std::is_unsigned_v <T>) {
        std::cout << "Min: " << std::dec << std::numeric_limits<T>::min() << std::endl;
    } else {
        std::cout << "Min: " << std::dec << std::numeric_limits<T>::min() << " = " << to_power_of_two(std::numeric_limits<T>::min()) << std::endl;
    }
    std::cout << "Max: " << std::dec << std::numeric_limits<T>::max() << " = " << to_power_of_two(std::numeric_limits<T>::max()) << std::endl;
}

#define PRINT(x) print <x> (#x)

int main() {
    std::cout << "Below is a list of max and min values for all numeric types on this system: " << '\n';
    std::cout << "From: https://en.cppreference.com/w/cpp/language/types" << '\n';
    std::cout << '\n';
    std::cout << "*********** Integer Ranges ************" << '\n';
    PRINT(short int);
    std::cout << '\n';
    PRINT(unsigned short int);
    std::cout << '\n';
    PRINT(int);
    std::cout << '\n';
    PRINT(unsigned int);
    std::cout << '\n';
    PRINT(long int);
    std::cout << '\n';
    PRINT(unsigned long int);
    std::cout << '\n';
    PRINT(long long int);
    std::cout << '\n';
    PRINT(unsigned long long int);
    std::cout << '\n';
    PRINT(int16_t);
    std::cout << '\n';
    PRINT(int32_t);
    std::cout << '\n';
    PRINT(int64_t);
    std::cout << '\n';
    PRINT(uint16_t);
    std::cout << '\n';
    PRINT(uint32_t);
    std::cout << '\n';
    PRINT(uint64_t);

    std::cout << '\n';

    std::cout << "*********** Floating Point Ranges ************" << '\n';
    std::cout << "**** float ****" << '\n';
    std::cout << "Min (±): " << std::dec << std::numeric_limits<float>::min() << '\n';
    std::cout << "Max (±): " << std::dec << std::numeric_limits<float>::max() << '\n';

    std::cout << '\n';

    std::cout << "**** double ****" << '\n';
    std::cout << "Min (±): " << std::dec << std::numeric_limits<double>::min() << '\n';
    std::cout << "Max (±): " << std::dec << std::numeric_limits<double>::max() << '\n';

    std::cout << '\n';

    std::cout << "**** long double ****" << '\n';
    std::cout << "Min (±): " << std::dec << std::numeric_limits<long double>::min() << '\n';
    std::cout << "Max (±): " << std::dec << std::numeric_limits<long double>::max() << '\n';

    return 0;
}
