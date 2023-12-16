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
        file << "Інформація про фігури:\n";
        file << "------------------------\n";
        file << "Коло:\n";
        file << "Радіус: " << R;
        file << "\nДовжина кола: " << obchyslDovshun();
        file << "\nПлоща: " << S_Kolo();
        file << "\n------------------------\n";
        file << "Прямокутник:\n";
        file << "Ширина: " << b;
        file << "\nВисота: " << a;
        file << "\nПериметр: " << obchyslPerimetr();
        file << "\nПлоща: " << S_Pramokytnuk();

        file.close();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Pramokytnuk_vpus_Kolo p_k;
    cout << "Введіть радіус кола: ";
    cin >> p_k.R;
    cout << "Введіть ширину прямокутника: ";
    cin >> p_k.b;
    cout << "Введіть висоту прямокутника: ";
    cin >> p_k.a;
    p_k.zapus();
}

