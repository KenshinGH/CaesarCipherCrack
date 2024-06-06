#pragma once
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include <iostream>
#include "Decrypt.h"
#include "RussianDecrypt.h"

namespace CaesarCipherCrack {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для decryptor_form
	/// </summary>
	public ref class decryptor_form : public System::Windows::Forms::Form
	{
	public:
		decryptor_form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~decryptor_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonCrack;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;


		   System::String^ inputText;
	private: System::Windows::Forms::Button^ buttonSave;

	private: System::Windows::Forms::Button^ buttonOpen;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(decryptor_form::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonCrack = (gcnew System::Windows::Forms::Button());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"VK Sans Display", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(55, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(417, 50);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Caesar Cipher Crack";
			this->label1->Click += gcnew System::EventHandler(this, &decryptor_form::label1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->richTextBox1->Location = System::Drawing::Point(4, 146);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(494, 385);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &decryptor_form::richTextBox1_TextChanged);
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->richTextBox2->Location = System::Drawing::Point(0, 0);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(486, 387);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"VK Sans Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(129, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(205, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Enter encrypted text";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"VK Sans Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(700, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(156, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Decrypted text";
			// 
			// buttonCrack
			// 
			this->buttonCrack->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonCrack->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonCrack->Font = (gcnew System::Drawing::Font(L"Cascadia Mono PL SemiBold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCrack->Location = System::Drawing::Point(435, 537);
			this->buttonCrack->Name = L"buttonCrack";
			this->buttonCrack->Size = System::Drawing::Size(132, 35);
			this->buttonCrack->TabIndex = 5;
			this->buttonCrack->Text = L"CRACK";
			this->buttonCrack->UseVisualStyleBackColor = true;
			this->buttonCrack->Click += gcnew System::EventHandler(this, &decryptor_form::buttonCrack_Click);
			// 
			// buttonSave
			// 
			this->buttonSave->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonSave->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonSave->Font = (gcnew System::Drawing::Font(L"VK Sans Display", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSave->Location = System::Drawing::Point(889, 24);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(99, 35);
			this->buttonSave->TabIndex = 6;
			this->buttonSave->Text = L"Save";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &decryptor_form::buttonSave_Click);
			// 
			// buttonOpen
			// 
			this->buttonOpen->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonOpen->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonOpen->Font = (gcnew System::Drawing::Font(L"VK Sans Display", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonOpen->Location = System::Drawing::Point(784, 24);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(99, 35);
			this->buttonOpen->TabIndex = 7;
			this->buttonOpen->Text = L"Open";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &decryptor_form::buttonOpen_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(504, 121);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(494, 412);
			this->tabControl1->TabIndex = 8;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->richTextBox2);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"VK Sans Display", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(486, 383);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"English";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox3);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"VK Sans Display", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(486, 383);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Russian";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// richTextBox3
			// 
			this->richTextBox3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->richTextBox3->Location = System::Drawing::Point(-4, 0);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->Size = System::Drawing::Size(494, 385);
			this->richTextBox3->TabIndex = 9;
			this->richTextBox3->Text = L"";
			// 
			// decryptor_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->ClientSize = System::Drawing::Size(1000, 580);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->buttonOpen);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->buttonCrack);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(1018, 581);
			this->Name = L"decryptor_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"decryptor_form";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	inputText = this->richTextBox1->Text;
}

private: System::Void buttonCrack_Click(System::Object^ sender, System::EventArgs^ e) {
	// Расшифровка шифра на английском
	msclr::interop::marshal_context context;
	std::wstring stdInputText = context.marshal_as<std::wstring>(inputText);
	std::wstring stdDecryptedText = Decrypt::CaesarCipherCrack(stdInputText);
	System::String^ DecryptedText = gcnew System::String(stdDecryptedText.c_str());
	this->richTextBox2->Text = DecryptedText;
 
	// Расшифровка шифра на русском
	std::wstring wstdInputText = context.marshal_as<std::wstring>(inputText);
	std::wstring wstdDecryptedText = RussianDecrypt::CaesarCypherCrack(wstdInputText);
	System::String^ russianDecryptedText = gcnew System::String(wstdDecryptedText.c_str());
	this->richTextBox3->Text = russianDecryptedText;
}

private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ encryptedText = richTextBox1->Text;
	String^ decryptedText = richTextBox2->Text;

	saveTextToFile("inputText.txt", encryptedText);
	saveTextToFile("outputText.txt", decryptedText);
	MessageBox::Show("Text saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void buttonOpen_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		System::String^ filePath = openFileDialog1->FileName;

		try {
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filePath);
			this->richTextBox1->Text = reader->ReadToEnd();
			reader->Close();
		}

		catch (System::Exception^ ex) {
			MessageBox::Show("Error open file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
	   void saveTextToFile(String^ fileName, String^ text) {
		   try {
			   std::string stdFileName = msclr::interop::marshal_as<std::string>(fileName);
			   std::string stdText = msclr::interop::marshal_as<std::string>(text);
			   File::WriteAllText(gcnew String(stdFileName.c_str()), text);
		   }

		   catch (Exception^ ex) {
			   MessageBox::Show("Error saving text to file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		   }
	   }
};
}
