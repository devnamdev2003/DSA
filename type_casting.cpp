#include <iostream>
#include <string>
#include <sstream>

int main()
{
    // String to int (Implicit conversion)
    std::string str_num = "123";
    int num = std::stoi(str_num);
    std::cout << "String to int (Implicit): " << num << std::endl;

    // Int to string (Implicit conversion)
    int num2 = 456;
    std::string str_num2 = std::to_string(num2);
    std::cout << "Int to string (Implicit): " << str_num2 << std::endl;

    // Char to int (Implicit conversion)
    char ch = '7';
    int num3 = ch - '0'; // Converts character to integer value
    std::cout << "Char to int (Implicit): " << num3 << std::endl;

    // Int to char (Implicit conversion)
    int num4 = 9;
    char ch2 = num4 + '0'; // Converts integer to character value
    std::cout << "Int to char (Implicit): " << ch2 << std::endl;

    // Float to int (Explicit conversion)
    float f_num = 3.14;
    int num5 = static_cast<int>(f_num);
    std::cout << "Float to int (Explicit): " << num5 << std::endl;

    // Int to float (Implicit conversion)
    int num6 = 100;
    float f_num2 = num6; // Integer implicitly converted to float
    std::cout << "Int to float (Implicit): " << f_num2 << std::endl;

    return 0;
}
