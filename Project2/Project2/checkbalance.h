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
	/// Summary for checkbalance
	/// </summary>
	public ref class checkbalance : public System::Windows::Forms::Form
	{
	public:
		checkbalance(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		checkbalance(int userIndex) {
			// Initialize the form
			InitializeComponent();
			// Use 'user' as needed
			loggedInUserIndex = userIndex;


		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~checkbalance()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(checkbalance::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(149, 346);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"check";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &checkbalance::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12));
			this->label1->Location = System::Drawing::Point(12, 111);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"your balance ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12));
			this->label2->Location = System::Drawing::Point(126, 111);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 24);
			this->label2->TabIndex = 2;
			// 
			// checkbalance
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(870, 570);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"checkbalance";
			this->Text = L"checkbalance";
			this->Load += gcnew System::EventHandler(this, &checkbalance::checkbalance_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;


		}
#pragma endregion

		void performcheckbalance() {

			User currentUser = usertList.getElementAt(loggedInUserIndex);
			label2->Text = "$" + currentUser.getBankAccount().getBalance();

		}


	private: System::Void checkbalance_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		performcheckbalance();
	     }
	};
}
