#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generate_password(int length, bool use_upper, bool use_lower, bool use_digits, bool use_special) {
    std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lower = "abcdefghijklmnopqrstuvwxyz";
    std::string digits = "0123456789";
    std::string special = "!@#$%^&*()-_=+[]{};:,.<>?";

    std::string charset = "";

    if (use_upper) charset += upper;
    if (use_lower) charset += lower;
    if (use_digits) charset += digits;
    if (use_special) charset += special;

    if (charset.empty()) {
        std::cerr << "No character types selected!\n";
        exit(1);
    }

    std::string password = "";
    for (int i = 0; i < length; ++i) {
        int index = rand() % charset.length();
        password += charset[index];
    }

    return password;
}

int main() {
    srand(time(0));
    int length;
    char choice;

    std::cout << "=== Password Generator ===\n";

    std::cout << "Password length: ";
    std::cin >> length;

    std::cout << "Include uppercase letters? (y/n): ";
    std::cin >> choice;
    bool use_upper = (choice == 'y' || choice == 'Y');

    std::cout << "Include lowercase letters? (y/n): ";
    std::cin >> choice;
    bool use_lower = (choice == 'y' || choice == 'Y');

    std::cout << "Include digits? (y/n): ";
    std::cin >> choice;
    bool use_digits = (choice == 'y' || choice == 'Y');

    std::cout << "Include special characters? (y/n): ";
    std::cin >> choice;
    bool use_special = (choice == 'y' || choice == 'Y');

    std::string password = generate_password(length, use_upper, use_lower, use_digits, use_special);
    std::cout << "Generated Password: " << password << "\n";

    return 0;
}
