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
	// ������� ���� � ������� �����
    std::vector<double> p = {
    0.07821,  // �
    0.01732,  // �
    0.04533,  // �
    0.01687,  // �
    0.02977,  // �
    0.08398,  // �
    0.00094,  // �
    0.00940,  // �
    0.01641,  // �
    0.07367,  // �
    0.01210,  // �
    0.03486,  // �
    0.04343,  // �
    0.03203,  // �
    0.06700,  // �
    0.10983,  // �
    0.02804,  // �
    0.04746,  // �
    0.05473,  // �
    0.06318,  // �
    0.02615,  // �
    0.00162,  // �
    0.00764,  // �
    0.00348,  // �
    0.01440,  // �
    0.00728,  // �
    0.00331,  // �
    0.00020,  // �
    0.01983,  // �
    0.01732,  // �
    0.00331,  // �
    0.00541,  // �
    0.01801   // �
    };

    std::wstring alphabetLower = L"��������������������������������";
    std::wstring alphabetUpper = L"�����Ũ��������������������������";

    // ������������ ������� � ������������� ������
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

    // ����� ������������ D(s)
    int bestShift = 0;
    double minD = CalculateD(p, f, 0, alphabetLower);

    for (int s = 1; s < alphabetLower.size(); s++) {
        double currentD = CalculateD(p, f, s, alphabetLower);
        if (currentD < minD) {
            minD = currentD;
            bestShift = s;
        }
    }

    // ����������� � ��������� �������
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


