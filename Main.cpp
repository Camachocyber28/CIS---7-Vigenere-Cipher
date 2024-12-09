#include <iostream>
#include <string>

using namespace std;

void vigenereCipher(char message[], const string& keyword, bool encrypt) {
    char ch;
    int keyLength = keyword.length(), keyIndex = 0;

    for (int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        int keyShift = toupper(keyword[keyIndex % keyLength]) - 'A';

        if (!encrypt) {
            keyShift = -keyShift;
        }

        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + keyShift + 26) % 26) + 'a';
            message[i] = ch;
            keyIndex++;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + keyShift + 26) % 26) + 'A';
            message[i] = ch;
            keyIndex++;
        }
    }
}

int main() {
    char message[100];
    string keyword;
    int choice;

    do {
        cout << "\nSelect an Option:\n1. Encrypt\n2. Decrypt\n3. Exit Program\n";
        cin >> choice;
        cin.ignore();

        if (choice == 1) { 
            cout << "Encrypted Message: ";
            cin.getline(message, 100);

            cout << "Enter Your Key: ";
            cin >> keyword;

            vigenereCipher(message, keyword, true);
            cout << "Encrypted Message: " << message << endl; 
        }
        else if (choice == 2) { 
            cout << "Enter Your Message: ";
            cin.getline(message, 100);

            cout << "Enter Your Key: ";
            cin >> keyword;

            vigenereCipher(message, keyword, false);
            cout << "Decrypted Message: " << message << endl;
        }
        else if (choice == 3) { 
            cout << "Program Exited" << endl;
            break;
        }
        else {
            cout << "Invalid Option! Select 1, 2, or 3." << endl;
        }

    } while (true);

    return 0;
}