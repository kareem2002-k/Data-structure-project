#pragma once

namespace Project2 {

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
	protected:
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
			this->deposit = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// deposit
			// 
			this->deposit->Location = System::Drawing::Point(137, 333);
			this->deposit->Name = L"deposit";
			this->deposit->Size = System::Drawing::Size(191, 80);
			this->deposit->TabIndex = 0;
			this->deposit->Text = L"button1";
			this->deposit->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(423, 333);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(191, 80);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// operations
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(869, 590);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->deposit);
			this->Name = L"operations";
			this->Text = L"operations";
			this->Load += gcnew System::EventHandler(this, &operations::operations_Load);
			this->ResumeLayout(false);

		}

		// ---------------------functions---------------------

#pragma endregion
	private: System::Void operations_Load(System::Object^ sender, System::EventArgs^ e) {



	}
	};
}
