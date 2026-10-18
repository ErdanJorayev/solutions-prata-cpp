#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Открываем входные и выходной файлы
    std::ifstream file1("file1.txt");
    std::ifstream file2("file2.txt");
    std::ofstream fileOut("output.txt");

    if (!file1.is_open() || !file2.is_open() || !fileOut.is_open()) {
        std::cerr << "Ошибка при открытии файлов!" << std::endl;
        return 1;
    }

    std::string line1, line2;
    bool has_line1 = static_cast<bool>(std::getline(file1, line1));
    bool has_line2 = static_cast<bool>(std::getline(file2, line2));

    // Построчно объединяем содержимое обоих файлов
    while (has_line1 || has_line2) 
    {
        if (has_line1 && has_line2) 
        {
            // Если строки есть в обоих файлах — соединяем их через пробел
            fileOut << line1 << " " << line2 << "\n";
        } 
        else if (has_line1) 
        {
            // Если строки остались только в первом файле[cite: 7]
            fileOut << line1 << "\n";
        } 
        else 
        {
            // Если строки остались только во втором файле[cite: 7]
            fileOut << line2 << "\n";
        }

        // Читаем следующие строки[cite: 7]
        has_line1 = static_cast<bool>(std::getline(file1, line1));
        has_line2 = static_cast<bool>(std::getline(file2, line2));
    }

    std::cout << "Файлы успешно объединены в output.txt" << std::endl;

    return 0;
}