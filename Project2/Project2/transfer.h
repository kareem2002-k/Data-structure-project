#pragma once
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
	/// Summary for transfer
	/// </summary>
	public ref class transfer : public System::Windows::Forms::Form
	{
	public:
		transfer(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		transfer(int userIndex) {
			// Initialize the form
			InitializeComponent();
			// Use 'user' as needed
			loggedInUserIndex = userIndex;


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~transfer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int loggedInUserIndex;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(transfer::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(169, 361);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"transfer";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &transfer::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(250, 157);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(109, 22);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(35, 157);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(125, 22);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(42, 95);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"name of the receiver";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(247, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"amount to transfer";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(35, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(76, 31);
			this->button2->TabIndex = 5;
			this->button2->Text = L"back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &transfer::button2_Click);
			// 
			// transfer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(870, 570);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"transfer";
			this->Text = L"transfer";
			this->Load += gcnew System::EventHandler(this, &transfer::transfer_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void transfer_Load(System::Object^ sender, System::EventArgs^ e) {


	}
		
		   void performtransfer() {
			   String^ enteredValue = textBox1->Text;
			   double parsedValue;
			   System::Double::TryParse(enteredValue, parsedValue);

			   String^ enteredname = textBox2->Text;

			   // Find the user to transfer funds to
			   for (int i = 0; i < usertList.getSize(); i++) {
				   User& current = usertList.getElementAt(i);

				   if (enteredname->Equals(gcnew String(current.getUsername().c_str()), StringComparison::OrdinalIgnoreCase)) {
					   // Update the balance of the user to transfer funds to
					   current.getBankAccount().setBalance(current.getBankAccount().getBalance() + parsedValue);

					   // Update the balance of the current user (subtract the transferred amount)
					   User& currentUser = usertList.getElementAt(loggedInUserIndex);
					   currentUser.getBankAccount().setBalance(currentUser.getBankAccount().getBalance() - parsedValue);

					   MessageBox::Show("Transfer successful!", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

					   // Update the user in the usertList
					   usertList.replaceElementAt(loggedInUserIndex, currentUser);
					   usertList.replaceElementAt(i, current);

					   return;
				   }
			   }
			   MessageBox::Show("Entered username: " + enteredname, "Debug Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

			   // If the loop completes without finding a matching user
			   MessageBox::Show("User not found.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
		   }

		
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		performtransfer();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
