#include "RussianDecrypt.h"
#include <cmath>
#include <algorithm>
#include <cctype>

double RussianDecrypt::CalculateD(const std::vector<double>& p, const std::vector<double>& f, int s, const std::wstring& alphabet)
{
    double sum = 0;
    for (size_t i = 0; i < alphabet.size(); i++) {
        sum += std::abs(p[i] - f[(i + s) % alphabet.size()]);
    }
    return sum;
}

std::wstring RussianDecrypt::CaesarCypherCrack(std::wstring& inputText)
{
	// Частоты букв в русском языке
    std::vector<double> p = {
    0.07821,  // А
    0.01732,  // Б
    0.04533,  // В
    0.01687,  // Г
    0.02977,  // Д
    0.08398,  // Е
    0.00094,  // Ё
    0.00940,  // Ж
    0.01641,  // З
    0.07367,  // И
    0.01210,  // Й
    0.03486,  // К
    0.04343,  // Л
    0.03203,  // М
    0.06700,  // Н
    0.10983,  // О
    0.02804,  // П
    0.04746,  // Р
    0.05473,  // С
    0.06318,  // Т
    0.02615,  // У
    0.00162,  // Ф
    0.00764,  // Х
    0.00348,  // Ц
    0.01440,  // Ч
    0.00728,  // Ш
    0.00331,  // Щ
    0.00020,  // Ъ
    0.01983,  // Ы
    0.01732,  // Ь
    0.00331,  // Э
    0.00541,  // Ю
    0.01801   // Я
    };

    std::wstring alphabetLower = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    std::wstring alphabetUpper = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

    // Подсчитываем частоты в зашифрованном тексте
    std::vector<double> f(alphabetLower.size(), 0);
    int total = 0;

    for (char c : inputText) {
        auto pos = alphabetLower.find(tolower(c));
        if (pos != std::wstring::npos) {
            f[pos]++;
            total++;
        }
    }

    for (double& count : f) {
        count /= total;
    }

    // Поиск минимального D(s)
    int bestShift = 0;
    double minD = CalculateD(p, f, 0, alphabetLower);

    for (int s = 1; s < alphabetLower.size(); s++) {
        double currentD = CalculateD(p, f, s, alphabetLower);
        if (currentD < minD) {
            minD = currentD;
            bestShift = s;
        }
    }

    // Расшифровка с найденным сдвигом
    std::wstring result;
    for (char c : inputText) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            const std::wstring& alphabet = isUpper ? alphabetUpper : alphabetLower;
            auto pos = alphabet.find(c);
            if (pos != std::wstring::npos) {
                result += alphabet[(pos - bestShift + alphabet.size()) % alphabet.size()];
            }
        }
        else {
            result += c;
        }
    }

    return result;
}


