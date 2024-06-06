#pragma once
#include <string>
#include <vector>

class RussianDecrypt {
public:
	static std::wstring CaesarCypherCrack(std::wstring& inputText);

private:
	static double CalculateD(const std::vector<double>& p, const std::vector<double>& f, int s, const std::wstring& alphabet);
};

