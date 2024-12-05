#include "Serializer.h"
#include<Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    int integer;

    cout << "������� ����� (�� 127 ��������): ";
    getline(cin, text);
    if (text.size() > 127) {
        cerr << "������: ����� ������� �������.\n";
        return 1;
    }

    cout << "������� ����� �����: ";
    cin >> integer;

    Serializer serializer(text, integer);
    serializer.SerializeData();

    return 0;
}
