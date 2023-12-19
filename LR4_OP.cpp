#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;


class Kolo {
public:
    int R;
    double obchyslDovshun() {
        return (2 * 3.14159) * R;
    }
};

class Pramokytnuk {
public:
    int b;
    int a;
    int obchyslPerimetr() {
        return (2*b)+(2*a);
    }
};

class Pramokytnuk_vpus_Kolo: public Kolo, public Pramokytnuk {
public:

    int S_Pramokytnuk() {
        return b * a;
    }

    double S_Kolo() {
        return 3.14159 * pow(R, 2);
    }

    void zapus() {
        ofstream file;
        file.open("figury.txt");
        file << "Enter:\n";
        file << "------------------------\n";
        file << "����:\n";
        file << "�����: " << R;
        file << "\n������� ����: " << obchyslDovshun();
        file << "\n�����: " << S_Kolo();
        file << "\n------------------------\n";
        file << "�����������:\n";
        file << "������: " << b;
        file << "\n������: " << a;
        file << "\n��������: " << obchyslPerimetr();
        file << "\n�����: " << S_Pramokytnuk();

        file.close();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Pramokytnuk_vpus_Kolo p_k;
    cout << "������ ����� ����: ";
    cin >> p_k.R;
    cout << "������ ������ ������������: ";
    cin >> p_k.b;
    cout << "������ ������ ������������: ";
    cin >> p_k.a;
    p_k.zapus();
}

