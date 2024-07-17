#pragma once

#include <msclr/marshal_cppstd.h> // Required for string conversion
#include "token.h"
#include "Tree.h"
#include "syntaxAnalysis.h"

#include <cliext/vector>












namespace CCProject {


	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		public:
			MyForm(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::TextBox^ input;
		protected:
		private: System::Windows::Forms::Button^ lexicalBtn;
		private: System::Windows::Forms::Button^ syntaxBtn;
		private: System::Windows::Forms::Button^ treeBtn;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Button^ runAllBtn;
		private: System::Windows::Forms::TextBox^ outputBox;
	private: System::Windows::Forms::Label^ label2;

		
	
	
	


	// ------------------------------ LAB CODE ------------------------------------------------------------------------
	
		public:
			

				
	
	
	
	
		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->input = (gcnew System::Windows::Forms::TextBox());
				this->lexicalBtn = (gcnew System::Windows::Forms::Button());
				this->syntaxBtn = (gcnew System::Windows::Forms::Button());
				this->treeBtn = (gcnew System::Windows::Forms::Button());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->runAllBtn = (gcnew System::Windows::Forms::Button());
				this->outputBox = (gcnew System::Windows::Forms::TextBox());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->SuspendLayout();
				// 
				// input
				// 
				this->input->Location = System::Drawing::Point(189, 119);
				this->input->Multiline = true;
				this->input->Name = L"input";
				this->input->Size = System::Drawing::Size(308, 308);
				this->input->TabIndex = 0;
				// 
				// lexicalBtn
				// 
				this->lexicalBtn->BackColor = System::Drawing::SystemColors::Highlight;
				this->lexicalBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->lexicalBtn->Location = System::Drawing::Point(189, 455);
				this->lexicalBtn->Name = L"lexicalBtn";
				this->lexicalBtn->Size = System::Drawing::Size(308, 64);
				this->lexicalBtn->TabIndex = 1;
				this->lexicalBtn->Text = L"Lexical";
				this->lexicalBtn->UseVisualStyleBackColor = false;
				this->lexicalBtn->Click += gcnew System::EventHandler(this, &MyForm::lexicalBtn_Click);
				// 
				// syntaxBtn
				// 
				this->syntaxBtn->BackColor = System::Drawing::SystemColors::Highlight;
				this->syntaxBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->syntaxBtn->Location = System::Drawing::Point(530, 455);
				this->syntaxBtn->Name = L"syntaxBtn";
				this->syntaxBtn->Size = System::Drawing::Size(315, 64);
				this->syntaxBtn->TabIndex = 2;
				this->syntaxBtn->Text = L"Syntax Analysis";
				this->syntaxBtn->UseVisualStyleBackColor = false;
				this->syntaxBtn->Click += gcnew System::EventHandler(this, &MyForm::syntaxBtn_Click);
				// 
				// treeBtn
				// 
				this->treeBtn->BackColor = System::Drawing::SystemColors::Highlight;
				this->treeBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->treeBtn->Location = System::Drawing::Point(189, 540);
				this->treeBtn->Name = L"treeBtn";
				this->treeBtn->Size = System::Drawing::Size(308, 64);
				this->treeBtn->TabIndex = 3;
				this->treeBtn->Text = L"Tree";
				this->treeBtn->UseVisualStyleBackColor = false;
				this->treeBtn->Click += gcnew System::EventHandler(this, &MyForm::treeBtn_Click);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->label1->Location = System::Drawing::Point(182, 79);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(113, 37);
				this->label1->TabIndex = 4;
				this->label1->Text = L"INPUT";
				// 
				// runAllBtn
				// 
				this->runAllBtn->BackColor = System::Drawing::SystemColors::Highlight;
				this->runAllBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->runAllBtn->Location = System::Drawing::Point(189, 630);
				this->runAllBtn->Name = L"runAllBtn";
				this->runAllBtn->Size = System::Drawing::Size(656, 64);
				this->runAllBtn->TabIndex = 5;
				this->runAllBtn->Text = L"Run All";
				this->runAllBtn->UseVisualStyleBackColor = false;
				this->runAllBtn->Click += gcnew System::EventHandler(this, &MyForm::runAllBtn_Click);
				// 
				// outputBox
				// 
				this->outputBox->Location = System::Drawing::Point(530, 119);
				this->outputBox->Multiline = true;
				this->outputBox->Name = L"outputBox";
				this->outputBox->Size = System::Drawing::Size(315, 308);
				this->outputBox->TabIndex = 6;
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->label2->Location = System::Drawing::Point(523, 79);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(149, 37);
				this->label2->TabIndex = 7;
				this->label2->Text = L"OUTPUT";
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(19, 37);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->ClientSize = System::Drawing::Size(1036, 818);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->outputBox);
				this->Controls->Add(this->runAllBtn);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->treeBtn);
				this->Controls->Add(this->syntaxBtn);
				this->Controls->Add(this->lexicalBtn);
				this->Controls->Add(this->input);
				this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Margin = System::Windows::Forms::Padding(6);
				this->Name = L"MyForm";
				this->Text = L"MyForm";
				this->ResumeLayout(false);
				this->PerformLayout();

			}

			
			// saving input to file
			void SaveToFile(String^ input)
			{
				// Specify the file path where you want to save the input
				String^ filePath = "file.txt";

				try
				{
					// Create or open the file for writing
					StreamWriter^ writer = File::CreateText(filePath);

					// Write the input to the file
					writer->WriteLine(input);

					// Close the file
					writer->Close();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show("Error saving input to file: " + ex->Message);
				}
			}


			


		#pragma endregion
		


		private: System::Void lexicalBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			
			if (!newfile.is_open()) {
				openFile();
			}
			
			String^ value = this->input->Text;
			SaveToFile(value);
			noman_tokenization nkt;

			cliext::vector<String^>^ myArray = gcnew cliext::vector<String^>();

			

			while (!newfile.eof()) {
				nkt = Lexical();

				String^ val = "Token: ";
				val += gcnew String(nkt.name.c_str());
				myArray->push_back(val);
			}

			String^ allTokens = "LEXICAL\n";
			for each (String ^ element in myArray)
			{
				allTokens += "\n";
				allTokens += element;
			}


			//String^ val = gcnew String(nkt.name.c_str());
			//MessageBox::Show(allTokens);
			allTokens = allTokens->Replace("\n", Environment::NewLine);
			outputBox->Text = allTokens;

			newfile.close();
		}
		private: System::Void syntaxBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!newfile.is_open()) {
				openFile();
			}

			String^ value = this->input->Text;
			SaveToFile(value);
			
			bool check = program();
			if (check) {
				outputBox->Text = "The code is Correct!";
				//MessageBox::Show("The code is Correct!");
			}
			else {
				outputBox->Text = "The code have Syntax Error! Please Correct it.";
				//MessageBox::Show("The code have Syntax Error! Please Correct it.");
			}

			// closing file
			newfile.close();
		}
		private: System::Void treeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!newfile.is_open()) {
				openFile();
			}

			String^ value = this->input->Text;
			SaveToFile(value);

			treenode* tr = new treenode();
			tr = Xp_noman();
			string res = "";
			res += displayTree(tr);
			String^ val = gcnew String(res.c_str());
			val = val->Replace("\n", Environment::NewLine);
			outputBox->Text = val;

		}
		private: System::Void runAllBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ value = this->input->Text;
			if (value->Length > 0) {
				
				SaveToFile(value);

				const std::string filePath = "file.txt";

				std::ifstream inputFile(filePath);
				if (inputFile.is_open())
				{
					std::string content;
					char a;
					while (inputFile.get(a)) {
						content += a;
					}
					inputFile.close();

					String^ val = gcnew String(content.c_str());
					MessageBox::Show("Data Read from file: " + val);
				}
				else
				{
					
					MessageBox::Show("Error reading file!");

				}

			}
		}

};
}
