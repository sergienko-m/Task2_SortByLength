🧾 Завдання 2 (Варіант 7)

Умова:
Дано масив A(10). Вивести елементи масиву у зростаючому порядку їх довжини.

🔹 Алгоритм

Ввести 10 рядків у масив A.

Відсортувати масив за довжиною (stable_sort).

Вивести рядки з довжинами.

### 🔹 Код (C++ wide-console)

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <io.h>
#include <fcntl.h>
using namespace std;

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    vector<wstring> A(10);
    wcout << L"Введіть 10 елементів масиву A:\\n";
    for (int i=0;i<10;i++){ wcout<<i+1<<L". "; getline(wcin,A[i]); }

    stable_sort(A.begin(),A.end(),[](auto&a,auto&b){return a.size()<b.size();});

    wcout<<L"\\nЕлементи у зростаючому порядку довжини:\\n";
    for (auto&x:A) wcout<<x<<L" (довжина = "<<x.size()<<L")\\n";
}
