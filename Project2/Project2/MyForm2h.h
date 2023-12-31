#pragma once
#ifndef MYFORM2H_H
#define MYFORM2H_H
#include "BankAccount.h"
#include "User.h"
#include <vcclr.h>
#include <msclr/marshal_cppstd.h>
#include "MyForm.h"



namespace Project2 {


	LinkedList<User> registered;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2h
	/// </summary>
	public ref class MyForm2h : public System::Windows::Forms::Form
	{
	public:
		MyForm2h(void)
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
		~MyForm2h()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2h::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(226, 485);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(204, 56);
			this->button1->TabIndex = 0;
			this->button1->Text = L"signup";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2h::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(130, 115);
			this->textBox1->Margin = System::Windows::Forms::Padding(0);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::HighlightText;
			this->textBox2->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox2->Location = System::Drawing::Point(130, 182);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(24, 118);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"user";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(24, 182);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(24, 245);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"account type";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm2h::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(24, 301);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"phone number";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(24, 369);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 16);
			this->label5->TabIndex = 7;
			this->label5->Text = L"address";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::HighlightText;
			this->textBox3->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox3->Location = System::Drawing::Point(130, 245);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 8;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm2h::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::HighlightText;
			this->textBox4->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox4->Location = System::Drawing::Point(130, 301);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 9;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::HighlightText;
			this->textBox5->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox5->Location = System::Drawing::Point(130, 369);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 10;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(12, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 52);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Back";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2h::button2_Click);
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::SystemColors::HighlightText;
			this->textBox6->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox6->Location = System::Drawing::Point(130, 428);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(24, 434);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(89, 16);
			this->label6->TabIndex = 13;
			this->label6->Text = L"initial balance";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(254, 199);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(263, 251);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm2h
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(870, 570);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm2h";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm2h";
			this->Load += gcnew System::EventHandler(this, &MyForm2h::MyForm2h_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		String^ enteredUsername = textBox1->Text;
		String^ enteredpassword = textBox2->Text;
		String^ enteredaccount = textBox3->Text;
		String^ enteredBalance = textBox6->Text;
		String^ enterednumber = textBox4->Text;
		double parsedBalance;
		int parsedphone;

		System::Double::TryParse(enteredBalance, parsedBalance);
		System::Int32::TryParse(enterednumber, parsedphone);

		signin(enteredUsername,enteredpassword, enteredaccount, parsedBalance,parsedphone);
		
	}

		void signin(String^ enteredUsername,String^ enteredpassword, String ^ enteredaccount, double enteredbalance,int enterednumber) {
	

			std::string address = "123 Main St";
			
			//  unique ID mechanism 
			std::string userId = "ID_" + std::to_string(static_cast<long long>(time(0)));

		

			msclr::interop::marshal_context context;
			std::string username = context.marshal_as<std::string>(enteredUsername);
			std::string userpassword = context.marshal_as<std::string>(enteredpassword);
			std::string account = context.marshal_as<std::string>(enteredaccount);
			std::string phoneNumber = context.marshal_as<std::string>(enterednumber.ToString());

			BankAccount account2(account, enteredbalance);
			// if the user already signed 
			for (int i = 0; i < usertList.getSize(); i++) {
				if (username == usertList.getElementAt(i).getUsername() && userpassword == usertList.getElementAt(i).getPassword()) {
					MessageBox::Show("User with the same username and password already exists.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;  
				}
			}
			User newUser(username, userpassword, phoneNumber, address, account2, User::UserRole(User::CUSTOMER));
			newUser.setUserId(userId);

			// Find the correct position to insert in a sorted order
			int index = usertList.getSize();;


		

			// the fields are not empty
			if (String::IsNullOrEmpty(enteredUsername) || String::IsNullOrEmpty(enteredpassword) || String::IsNullOrEmpty(enteredaccount) ) {
				MessageBox::Show("Please enter both username and password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else {
				usertList.insert(index, newUser);
				this->Close();
			}

		}


#pragma endregion
	private: System::Void MyForm2h_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	     this->Close();
   }
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
#endif // MYFORM2H_H