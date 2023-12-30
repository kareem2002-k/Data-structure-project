#pragma once
#ifndef HEADER_FILE_NAME_H
#define HEADER_FILE_NAME_H
#include "MyForm2h.h"

namespace Project2 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    LinkedList<User> users;


    /// <summary>
    /// Summary for homeform
    /// </summary>
    public ref class homeform : public System::Windows::Forms::Form
    {
    public:
        homeform(void)
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
        ~homeform()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;

    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(homeform::typeid));
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(238, 372);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(101, 50);
            this->button1->TabIndex = 0;
            this->button1->Text = L"log in";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &homeform::button1_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(43, 372);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(96, 50);
            this->button2->TabIndex = 1;
            this->button2->Text = L"sign in";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &homeform::button2_Click);
            // 
            // homeform
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(728, 525);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->MinimumSize = System::Drawing::Size(300, 200);
            this->Name = L"homeform";
            this->Text = L"homeform";
            this->Load += gcnew System::EventHandler(this, &homeform::homeform_Load);
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void homeform_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm^ loginForm = gcnew MyForm;
        this->Hide();  // Hide the current form
        loginForm->ShowDialog();
        this->Show();
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm2h^ signupForm = gcnew MyForm2h;
        this->Hide();  // Hide the current form
        signupForm->ShowDialog();
        this->Show();
    }
    };
}
#endif // HEADER_FILE_NAME_H
