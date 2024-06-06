#include "decryptor_form.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<System::String^>^ args) {
	
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	CaesarCipherCrack::decryptor_form form;
	Application::Run(% form);

	return 0;
}

