//
//  main.cpp
//  лаба 6
//
//  Created by Andrey Scherbakov on 26.02.2024.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    string str;
    cout << "Введите строку: ";
    getline(std::cin, str);

    str += " ";

    char masNum[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char masSim[] = {
        '_', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
        't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C',
        'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
        'X', 'Y', 'Z', '$'};

    int i = 0;
    int a = 0;
    bool flag = true;

    while (str[i] != '\0') {
        for (int j = 0; j < sizeof(masSim) / sizeof(masSim[0]) && flag; j++) {
            if (str[i] == masSim[j] || str[i] == ' ') {
                flag = false;
            }
        }

        if (flag) {
            for (int j = 0; j < sizeof(masNum) / sizeof(masNum[0]) && flag; j++) {
                if (str[i] == masNum[j] && a != i) {
                    flag = false;
                }
            }
        }

        if (flag) {
            while (str[a] != ' ')
                str.erase(a, 1);
            str.erase(a, 1);
            i = a;
        }
        else
            i++;

        if (str[i] == ' ') {
            a = i + 1;
        }
        flag = true;
    }

    cout << str<<"\n";

    return 0;
}
