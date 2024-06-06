#pragma once
#include <string>
#include <vector>

class Decrypt {
public:
    static std::wstring CaesarCipherCrack(std::wstring& inputText);

private:
    static double CalculateD(const std::vector<double>& p, const std::vector<double>& f, int s, const std::wstring& alphabet);
};
