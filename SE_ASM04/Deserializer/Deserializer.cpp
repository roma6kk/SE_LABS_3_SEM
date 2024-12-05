#include "Deserializer.h"

void Deserializer::DeserializeData() {
    file.open("D:/Poman/prog/C++/3_SEM/SE_3SEM/SE_ASM04/serializer.bin", ios::binary);
    if (!file) {
        cerr << "������ �������� ����� ��� ��������������.\n";
        return;
    }

    unsigned char marker, length;
    while (file.read(reinterpret_cast<char*>(&marker), sizeof(marker))) {
        file.read(reinterpret_cast<char*>(&length), sizeof(length));

        if (marker == textMarker) { 
            if (length > 127) {
                cerr << "����� ������ ��������� 127 ����.\n";
                break;
            }
            Text.resize(length);
            file.read(&Text[0], length);
        }
        else if (marker == intMarker) { 
            if (length != sizeof(Integer)) {
                cerr << "������������ ����� ��� ������ �����.\n";
                break;
            }
            file.read(reinterpret_cast<char*>(&Integer), length);
        }
        else {
            cerr << "����������� ������: " << static_cast<int>(marker) << "\n";
            break;
        }
    }

    file.close();
    cout << "����������������� ������:\n";
    cout << "�����: " << Text << "\n";
    cout << "����� �����: " << Integer << "\n";
}

void Deserializer::ConvertToAssembler() {
    fileAsm.open("D:/Poman/prog/C++/3_SEM/SE_3SEM/SE_ASM04/GeneratedASM/GeneratedASM.asm");
    if (!fileAsm) {
        cerr << "������ �������� ����� ��� ASM.\n";
        return;
    }

    fileAsm ASM_HEAD;

    fileAsm << "TEXT\tDB \"" << Text << "\", 0\n";
    fileAsm << "INTEGER\tDD " << Integer << "\n";

    fileAsm ASM_FOOTER;

    fileAsm.close();
    cout << "ASM ���� ������� ������.\n";
}
