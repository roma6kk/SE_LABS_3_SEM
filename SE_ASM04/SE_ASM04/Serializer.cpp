#include "Serializer.h"

void Serializer::SerializeData() {
    file.open("D:/Poman/prog/C++/3_SEM/SE_3SEM/SE_ASM04/serializer.bin", ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла для сериализации.\n";
        return;
    }

    file.put(textMarker);
    unsigned char textLength = static_cast<unsigned char>(Text.size());
    file.put(textLength);
    file.write(Text.data(), textLength);

    file.put(intMarker);
    unsigned char intSize = sizeof(Integer);
    file.put(intSize);
    file.write(reinterpret_cast<const char*>(&Integer), intSize);

    file.close();
    cout << "Данные успешно сериализованы.\n";
}
