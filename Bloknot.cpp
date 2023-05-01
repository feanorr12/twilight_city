namespace Bloknot{
 
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;
 
    /// <summary>
    /// Сводка для Form1
    /// </summary>
    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
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
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
 
protected: 
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
    private: System::Windows::Forms::Button^  button2;
    private: System::Windows::Forms::Button^  button6;
 
 
 
 
private: System::ComponentModel::IContainer^  components;
 
private:
/// <summary>
/// Требуется переменная конструктора.
/// </summary>
 
 
#pragma region Windows Form Designer generated code
/// <summary>
/// Обязательный метод для поддержки конструктора - не изменяйте
/// содержимое данного метода при помощи редактора кода.
/// </summary>
void InitializeComponent(void)
{
    this->button1 = (gcnew System::Windows::Forms::Button());
    this->label2 = (gcnew System::Windows::Forms::Label());
    this->textBox1 = (gcnew System::Windows::Forms::TextBox());
    this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
    this->button3 = (gcnew System::Windows::Forms::Button());
    this->button4 = (gcnew System::Windows::Forms::Button());
    this->button5 = (gcnew System::Windows::Forms::Button());
    this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
    this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
    this->button2 = (gcnew System::Windows::Forms::Button());
    this->button6 = (gcnew System::Windows::Forms::Button());
    this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
    this->flowLayoutPanel1->SuspendLayout();
    this->SuspendLayout();
    // 
    // button1
    // 
    this->button1->BackColor = System::Drawing::Color::Yellow;
    this->button1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(204)));
    this->button1->Location = System::Drawing::Point(3, 3);
    this->button1->Name = L"button1";
    this->button1->Size = System::Drawing::Size(89, 34);
    this->button1->TabIndex = 1;
    this->button1->Text = L"File Open";
    this->button1->UseVisualStyleBackColor = false;
    this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
    // 
    // label2
    // 
    this->label2->AutoSize = true;
    this->label2->BackColor = System::Drawing::Color::LemonChiffon;
    this->label2->Location = System::Drawing::Point(13, 58);
    this->label2->Name = L"label2";
    this->label2->Size = System::Drawing::Size(0, 13);
    this->label2->TabIndex = 2;
    // 
    // textBox1
    // 
    this->textBox1->BackColor = System::Drawing::Color::MistyRose;
    this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
    this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(204)));
    this->textBox1->Location = System::Drawing::Point(0, 40);
    this->textBox1->MaxLength = 500000;
    this->textBox1->Multiline = true;
    this->textBox1->Name = L"textBox1";
    this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
    this->textBox1->Size = System::Drawing::Size(668, 360);
    this->textBox1->TabIndex = 4;
    // 
    // openFileDialog1
    // 
    this->openFileDialog1->FileName = L"openFileDialog1";
    // 
    // button3
    // 
    this->button3->BackColor = System::Drawing::Color::SpringGreen;
    this->button3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(204)));
    this->button3->Location = System::Drawing::Point(201, 3);
    this->button3->Name = L"button3";
    this->button3->Size = System::Drawing::Size(130, 32);
    this->button3->TabIndex = 7;
    this->button3->Text = L"Сохранить в UTF8";
    this->button3->UseVisualStyleBackColor = false;
    this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
    // 
    // button4
    // 
    this->button4->BackColor = System::Drawing::Color::OrangeRed;
    this->button4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(204)));
    this->button4->Location = System::Drawing::Point(98, 3);
    this->button4->Name = L"button4";
    this->button4->Size = System::Drawing::Size(97, 34);
    this->button4->TabIndex = 8;
    this->button4->Text = L"Из ANSI";
    this->button4->UseVisualStyleBackColor = false;
    this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
    // 
    // button5
    // 
    this->button5->BackColor = System::Drawing::Color::Cyan;
    this->button5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(204)));
    this->button5->Location = System::Drawing::Point(337, 3);
    this->button5->Name = L"button5";
    this->button5->Size = System::Drawing::Size(90, 32);
    this->button5->TabIndex = 9;
    this->button5->Text = L"в Unicode";
    this->button5->UseVisualStyleBackColor = false;
    this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
    // 
    // flowLayoutPanel1
    // 
    this->flowLayoutPanel1->BackColor = System::Drawing::Color::PaleTurquoise;
    this->flowLayoutPanel1->Controls->Add(this->button1);
    this->flowLayoutPanel1->Controls->Add(this->button4);
    this->flowLayoutPanel1->Controls->Add(this->button3);
    this->flowLayoutPanel1->Controls->Add(this->button5);
    this->flowLayoutPanel1->Controls->Add(this->button2);
    this->flowLayoutPanel1->Controls->Add(this->button6);
    this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
    this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
    this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
    this->flowLayoutPanel1->Size = System::Drawing::Size(668, 40);
    this->flowLayoutPanel1->TabIndex = 10;
    // 
    // button2
    // 
    this->button2->BackColor = System::Drawing::Color::Thistle;
    this->button2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(204)));
    this->button2->Location = System::Drawing::Point(433, 3);
    this->button2->Name = L"button2";
    this->button2->Size = System::Drawing::Size(115, 32);
    this->button2->TabIndex = 10;
    this->button2->Text = L"Прозрачность";
    this->button2->UseVisualStyleBackColor = false;
    this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
    // 
    // button6
    // 
    this->button6->BackColor = System::Drawing::Color::LavenderBlush;
    this->button6->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
        static_cast<System::Byte>(204)));
    this->button6->Location = System::Drawing::Point(554, 3);
    this->button6->Name = L"button6";
    this->button6->Size = System::Drawing::Size(89, 34);
    this->button6->TabIndex = 11;
    this->button6->Text = L"Норм";
    this->button6->UseVisualStyleBackColor = false;
    this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
    // 
    // tableLayoutPanel1
    // 
    this->tableLayoutPanel1->AutoSize = true;
    this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
    this->tableLayoutPanel1->ColumnCount = 1;
    this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
        100)));
    this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Left;
    this->tableLayoutPanel1->Location = System::Drawing::Point(0, 40);
    this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
    this->tableLayoutPanel1->RowCount = 1;
    this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
    this->tableLayoutPanel1->Size = System::Drawing::Size(0, 360);
    this->tableLayoutPanel1->TabIndex = 11;
    // 
    // Form1
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->AutoScroll = true;
    this->AutoScrollMinSize = System::Drawing::Size(400, 300);
    this->ClientSize = System::Drawing::Size(668, 400);
    this->Controls->Add(this->textBox1);
    this->Controls->Add(this->tableLayoutPanel1);
    this->Controls->Add(this->flowLayoutPanel1);
    this->Controls->Add(this->label2);
    this->Name = L"Form1";
    this->Text = L"МиниБлокнот";
    this->flowLayoutPanel1->ResumeLayout(false);
    this->ResumeLayout(false);
    this->PerformLayout();
 
}
#pragma endregion
 
StreamReader^SR;
StreamWriter^SW;
 
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
             //File Open
             if(openFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK)
{label2->Text=openFileDialog1->FileName;
SR = gcnew StreamReader(label2->Text, System::Text::Encoding::UTF8, true);
textBox1->Text=SR->ReadToEnd();
SR->Close();
}
 }
 
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
//Сохранить в UTF8
             saveFileDialog1->AddExtension = true;
             saveFileDialog1->DefaultExt = "txt";
               if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
      {
             SW=gcnew StreamWriter(saveFileDialog1->FileName);
 SW->Write(textBox1->Text);
 SW->Close();
 }
  else
MessageBox::Show("Файл не выбран!");
 }
 
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
//Из ANSI
             SR = gcnew StreamReader(label2->Text, System::Text::Encoding::GetEncoding(1251), true);
textBox1->Text=SR->ReadToEnd();
SR->Close();
 
 }
 
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
             //в Unicode
              saveFileDialog1->DefaultExt = "txt";
  if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
      {
             auto Кодировка1 = System::Text::Encoding::Unicode;
auto SW=gcnew StreamWriter(saveFileDialog1->FileName, false, Кодировка1);
SW->Write(textBox1->Text);
SW->Close();
}
  else
MessageBox::Show("Файл не выбран! Нажмите кнопку 'Обзор2'");
 
 
 }
 
 
 
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
             //Прозрачность
             this->Opacity = 0.5;
         }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
              //Норм
             this->Opacity = 1.0;
         }
};
}
