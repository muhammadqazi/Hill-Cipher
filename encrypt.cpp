#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
using namespace std;

void cipher_algoritham(int matrix_key[3][3], int matrix_message[3][1], int matrix_cipher[3][1], string key, string message);
void show_progress_bar(int time, const std::string &message, char symbol);

int main()
{

    bool validate = true;
    string message, key;
    int matrix_key[3][3], matrix_message[3][1], matrix_cipher[3][1];

    system("clear");
    show_progress_bar(100, "Loading Hill-Cipher ...", '#');
    system("clear");
    cout << "\033[1;31m"
         << "["
         << "\033[1;37m"
         << " v 1.0.0"
         << "\033[1;31m"
         << " ]"
         << "\033[1;31m"
         << "\t\t["
         << "\033[1;37m"
         << " by Hosam Alhamawi"
         << "\033[1;31m"
         << " ]"
         << "\033[1;31m"
         << "\t\t[ "
         << "\033[1;37m"
         << "https://github.com/hosamalhamwi"
         << "\033[1;31m"
         << " ]\n\n";
    cout << "\033[1;31m"
         << "--------------------------------------------------------------------------------------------------\n\n";
    cout << "\033[1;31m"
         << "Hill Cipher:\n\n";

    do
    {

        cout << "Please enter the message :"
             << "\033[1;37m" << endl;
        cin >> message;

        if (message.length() < 15)
        {
            system("clear");
            cout << "\033[1;31m"
                 << "The message must be 15 characters long" << endl;
            validate = true;
        }
        else
        {
            system("clear");
            cout << "\033[1;31m"
                 << "Please enter the key :"
                 << "\033[1;37m" << endl;
            cin >> key;
            validate = false;
        }
    } while (validate);

    cipher_algoritham(matrix_key, matrix_message, matrix_cipher, key, message);

    return 0;
}

void cipher_algoritham(int matrix_key[3][3], int matrix_message[3][1], int matrix_cipher[3][1], string key, string message)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix_key[i][j] = (key[i * 3 + j]) % 65;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        matrix_message[i][0] = (message[i]) % 65;
    }
    for (int i = 0; i < 3; i++)
    {
        matrix_cipher[i][0] = 0;
        for (int j = 0; j < 3; j++)
        {
            matrix_cipher[i][0] += matrix_key[i][j] * matrix_message[j][0];
        }
        matrix_cipher[i][0] = matrix_cipher[i][0] % 26;
    }

    cout << "Plain Text : " << message << endl;
    cout << "Key : " << key << endl;
    cout << "The encrypted message is: ";

    for (int i = 0; i < 3; i++)
    {
        cout << char(matrix_cipher[i][0] + 65);
    }
}

void show_progress_bar(int time, const std::string &message, char symbol)
{
    std::string progress_bar;
    const double progress_level = 1.42;

    std::cout << "\n\033[1;31m" << message << "\n\n";

    for (double percentage = 0; percentage <= 100; percentage += progress_level)
    {
        progress_bar.insert(0, 1, symbol);
        std::cout << "\033[1;31m"
                  << "\r [ "
                  << "\033[1;37m" << std::ceil(percentage) << '%' << "\033[1;31m"
                  << " ] " << progress_bar;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }
    std::cout << "\n\n";
}
