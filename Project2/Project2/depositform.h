#pragma once
#ifndef MYDEPOSIT_H
#define MYDEPOSIT_H
#include "Transaction.h"
#include "BankAccount.h"
#include "User.h"

namespace Project2 {
	extern   LinkedList<User> usertList;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for depositform
	/// </summary>
	public ref class depositform : public System::Windows::Forms::Form
	{
	public:
	
		
		depositform(int userIndex)  {
			// Initialize the form
			InitializeComponent();
			// Use 'user' as needed
			loggedInUserIndex = userIndex;
			
			
		}
		

		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~depositform()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: int loggedInUserIndex;
	private: System::Windows::Forms::Label^ label2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(185, 203);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 22);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(185, 344);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 46);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &depositform::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(99, 262);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(397, 262);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// depositform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(561, 481);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"depositform";
			this->Text = L"depositform";
			this->Load += gcnew System::EventHandler(this, &depositform::depositform_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void depositform_Load(System::Object^ sender, System::EventArgs^ e) {
	}

		   
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		double inputValue;

		Double::TryParse(textBox1->Text, inputValue);
		
		performdeposit( inputValue);

		showlist();

	
		
	}

		   void showlist() {
			   String^ userListText = ""; // Initialize an empty string to hold user information

			   User currentUser = usertList.getElementAt(loggedInUserIndex);



			   for (int i = 0; i < usertList.getSize(); i++) {
				    currentUser = usertList.getElementAt(i);

				   // Concatenate user information
				   String^ userInfo = gcnew String((currentUser.getUsername() + " - " + currentUser.getPassword()).c_str());
				   userListText += userInfo + Environment::NewLine; // Add a newline between each user
				   
			   }
		   }
		  
		   void performdeposit(double amount) {


			   User currentUser = usertList.getElementAt(loggedInUserIndex);

		

			   // Retrieve the current balance
			   double currentBalance = currentUser.getBankAccount().getBalance();

			   // Update the user's balance
			   currentBalance += amount;

			   // Set the new balance to the user's bank account
			   currentUser.getBankAccount().setBalance(currentBalance);

			 //  usertList.getElementAt(loggedInUserIndex).bankAccount.setBalance(currentBalance);
			   // Update the user in the usertList
			   usertList.replaceElementAt(loggedInUserIndex, currentUser);

			//   usertList.getElementAt(loggedInUserIndex).bankAccount.setBalance(currentBalance);

			   label1->Text = "Balance after deposit: $" + currentUser.getBankAccount().getBalance();


			   
		   }
			
			
	};
}
#endif