// main.cpp  — Task2_SortByLength (wide, UTF-16 console)
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <io.h>
#include <fcntl.h>

int main() {
    // 1) Вмикаємо wide-режим для консолі (UTF-16)
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::vector<std::wstring> A(10);
    std::wcout << L"Введіть 10 елементів масиву A (рядки):\n";

    // якщо перед цим щось читали через >>, приберемо «хвіст» нового рядка
    if (std::wcin.peek() == L'\n')
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');

    for (int i = 0; i < 10; ) {
        std::wcout << std::setw(2) << (i + 1) << L". ";
        std::wstring s;
        std::getline(std::wcin, s);
        if (s.empty()) {
            std::wcout << L"   (рядок порожній, введіть ще раз)\n";
            continue;
        }
        A[i++] = std::move(s);
    }

    // 2) Сортуємо за зростанням довжини (стабільно)
    std::stable_sort(A.begin(), A.end(),
        [](const std::wstring& a, const std::wstring& b) {
            return a.size() < b.size();
        });

    // 3) Виводимо результат
    std::wcout << L"\nЕлементи у зростаючому порядку довжини:\n";
    for (const auto& x : A)
        std::wcout << x << L" (довжина = " << x.size() << L")\n";

    return 0;
}
