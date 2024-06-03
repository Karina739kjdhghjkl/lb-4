#pragma once

#include <Windows.h>
#include "functions.h"

namespace WindowsFormsApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
            container = new FunctionContainer();
            container->add(new LinearFunction());
            container->add(new QuadraticFunction());
            container->add(new CubicFunction());
        }

    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
            delete container;
        }

    private:
        FunctionContainer* container;
        System::Windows::Forms::TextBox^ textBox;
        System::Windows::Forms::Button^ button;
        System::Windows::Forms::Label^ label;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->textBox = (gcnew System::Windows::Forms::TextBox());
            this->button = (gcnew System::Windows::Forms::Button());
            this->label = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBox
            // 
            this->textBox->Location = System::Drawing::Point(50, 50);
            this->textBox->Name = L"textBox";
            this->textBox->Size = System::Drawing::Size(100, 20);
            this->textBox->TabIndex = 0;
            this->textBox->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox_TextChanged);
            // 
            // button
            // 
            this->button->Location = System::Drawing::Point(160, 50);
            this->button->Name = L"button";
            this->button->Size = System::Drawing::Size(75, 23);
            this->button->TabIndex = 1;
            this->button->Text = L"Рахувати";
            this->button->UseVisualStyleBackColor = true;
            this->button->Click += gcnew System::EventHandler(this, &MainForm::OnComputeClick);
            // 
            // label
            // 
            this->label->Location = System::Drawing::Point(50, 80);
            this->label->Name = L"label";
            this->label->Size = System::Drawing::Size(200, 23);
            this->label->TabIndex = 2;
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->label);
            this->Controls->Add(this->button);
            this->Controls->Add(this->textBox);
            this->Name = L"MainForm";
            this->Text = L"Функція суми";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        void OnComputeClick(System::Object^ sender, System::EventArgs^ e) {
            double x;
            if (Double::TryParse(this->textBox->Text, x)) {
                double sum = container->computeSum(x);
                this->label->Text = "Сума значень функцій: " + sum;
            }
            else {
                this->label->Text = "Невірний ввід!";
            }
        }
    private: System::Void textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}

int main()
{
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
    WindowsFormsApp::MainForm form;
    System::Windows::Forms::Application::Run(% form);
    return 0;
}
