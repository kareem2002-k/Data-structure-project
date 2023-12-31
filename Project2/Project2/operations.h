#pragma once
#ifndef MYFORMop_H
#define MYFORMop_H
#include "depositform.h"
#include "withdrawform.h"
#include "checkbalance.h"

#include "accountdetails.h"
namespace Project2 {
	extern   LinkedList<User> usertList;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for operations
	/// </summary>
	public ref class operations : public System::Windows::Forms::Form
	{
	public:
		operations(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		operations(int userIndex) {
			// Initialize the form
			InitializeComponent();
			// Use 'user' as needed
			loggedInUserIndex = userIndex;


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~operations()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ deposit;
	private: int loggedInUserIndex;
	private: System::Windows::Forms::Button^ withdraw;
	

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(operations::typeid));
			this->deposit = (gcnew System::Windows::Forms::Button());
			this->withdraw = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// deposit
			// 
			this->deposit->Location = System::Drawing::Point(29, 42);
			this->deposit->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->deposit->Name = L"deposit";
			this->deposit->Size = System::Drawing::Size(122, 53);
			this->deposit->TabIndex = 0;
			this->deposit->Text = L"deposit";
			this->deposit->UseVisualStyleBackColor = true;
			this->deposit->Click += gcnew System::EventHandler(this, &operations::deposit_Click);
			// 
			// withdraw
			// 
			this->withdraw->Location = System::Drawing::Point(210, 42);
			this->withdraw->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->withdraw->Name = L"withdraw";
			this->withdraw->Size = System::Drawing::Size(116, 53);
			this->withdraw->TabIndex = 1;
			this->withdraw->Text = L"withdraw";
			this->withdraw->UseVisualStyleBackColor = true;
			this->withdraw->Click += gcnew System::EventHandler(this, &operations::withdraw_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(29, 166);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 53);
			this->button1->TabIndex = 2;
			this->button1->Text = L"check balance";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &operations::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(210, 166);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(116, 53);
			this->button3->TabIndex = 3;
			this->button3->Text = L"transfer";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(29, 287);
			this->button4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(122, 53);
			this->button4->TabIndex = 4;
			this->button4->Text = L"account details";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &operations::button4_Click_1);
			// 
			// operations
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(652, 463);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->withdraw);
			this->Controls->Add(this->deposit);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"operations";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"operations";
			this->Load += gcnew System::EventHandler(this, &operations::operations_Load);
			this->ResumeLayout(false);

		}

		// ---------------------functions---------------------

#pragma endregion
	private: System::Void operations_Load(System::Object^ sender, System::EventArgs^ e) {



	}
	private: System::Void withdraw_Click(System::Object^ sender, System::EventArgs^ e) {

		withdrawform^ withdrawFormInstance = gcnew withdrawform(loggedInUserIndex);

		this->Hide();

		withdrawFormInstance->ShowDialog();

		this->Show();

	}
private: System::Void deposit_Click(System::Object^ sender, System::EventArgs^ e) {

	
	depositform^ depositFormInstance = gcnew depositform(loggedInUserIndex);

	this->Hide();

	depositFormInstance->ShowDialog();

	this->Show();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	checkbalance^ checkFormInstance = gcnew checkbalance(loggedInUserIndex);

	this->Hide();

	checkFormInstance->ShowDialog();

	this->Show();
}
	   
	   
	   
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	

}

private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {

	accountdetails^ checkFormInstance = gcnew accountdetails(loggedInUserIndex);

	this->Hide();

	checkFormInstance->ShowDialog();

	this->Show();
}
};
}

#endif // MYFORMop_H