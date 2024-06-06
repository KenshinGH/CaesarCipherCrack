#include "Decrypt.h"
#include <cmath>
#include <algorithm>
#include <cctype>

double Decrypt::CalculateD(const std::vector<double>& p, const std::vector<double>& f, int s, const std::wstring& alphabet) {
    double sum = 0;
    for (size_t i = 0; i < alphabet.size(); i++) {
        sum += std::abs(p[i] - f[(i + s) % alphabet.size()]);
    }
    return sum;
}

std::wstring Decrypt::CaesarCipherCrack(std::wstring& inputText) {
    // Частоты букв в английском языке
    std::vector<double> p = {
        0.08167, // A
        0.01492, // B
        0.02782, // C
        0.04253, // D
        0.12702, // E
        0.02228, // F
        0.02015, // G
        0.06094, // H
        0.06966, // I
        0.00153, // J
        0.00772, // K
        0.04025, // L
        0.02406, // M
        0.06749, // N
        0.07507, // O
        0.01929, // P
        0.00095, // Q
        0.05987, // R
        0.06327, // S
        0.09056, // T
        0.02758, // U
        0.00978, // V
        0.02360, // W
        0.00150, // X
        0.01974, // Y
        0.00074  // Z
    };

    std::wstring alphabetLower = L"abcdefghijklmnopqrstuvwxyz";
    std::wstring alphabetUpper = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Подсчитываем частоты букв в зашифрованном тексте
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