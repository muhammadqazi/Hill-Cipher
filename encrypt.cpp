#include <iostream>
using namespace std;

void cipher_algoritham(int matrix_key[3][3], int matrix_message[3][1], int matrix_cipher[3][1], string key, string message);

int main()
{

    bool validate = true;
    string message, key;
    int matrix_key[3][3], matrix_message[3][1], matrix_cipher[3][1];

    system("clear");

    do
    {

        cout << "Please enter the message :" << endl;
        cin >> message;

        if (message.length() < 15)
        {
            system("clear");
            cout << "The message must be 15 characters long" << endl;
            validate = true;
        }
        else
        {
            system("clear");

            cout << "Please enter the key :" << endl;

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