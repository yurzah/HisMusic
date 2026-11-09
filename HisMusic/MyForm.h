#pragma once
#include <windows.h>

#using "D:\\HisMusic\\x64\\Debug\\NAudio.dll"

namespace HisMusic {

    using namespace System;
    using namespace NAudio::Wave;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            trackBar_Volume->Value = 50;
            this->trackBar_Volume->BackColor =
                System::Drawing::Color::FromArgb(43, 43, 43);

            // front
            this->panel_Header->BringToFront();
            this->button_Close->BringToFront();
            this->button_Minimize->BringToFront();

            // ПРи запуску панель пуста
            panel_Home->Visible = false;
            panel_Search->Visible = false;
            panel_Favorites->Visible = false;
            panel_Converter->Visible = false;
        }

    protected:
        ~MyForm()
        {
            if (components)
                delete components;
        }

    private:
        AudioFileReader^ audioFile;
        WaveOutEvent^ outputDevice;
        System::Collections::Generic::List<String^>^ musicFiles =
            gcnew System::Collections::Generic::List<String^>();
        System::Windows::Forms::Panel^ panel_Header;
        System::Windows::Forms::Panel^ panel_Menu;
        System::Windows::Forms::Panel^ panel_Footer;
        System::Windows::Forms::Button^ button_Close;
        System::Windows::Forms::Button^ button_Minimize;
        System::Windows::Forms::Label^ label_Title;
        System::Windows::Forms::Label^ label_HisMusic;
        System::Windows::Forms::Label^ label_Footer;
        System::Windows::Forms::Button^ button_Home;
        System::Windows::Forms::Button^ button_Search;
        System::Windows::Forms::Button^ button_Favorites;
        System::Windows::Forms::Button^ button_Converter;

        // content panels
        System::Windows::Forms::Panel^ panel_Home;
        System::Windows::Forms::Panel^ panel_Search;
        System::Windows::Forms::Panel^ panel_Favorites;
        System::Windows::Forms::Panel^ panel_Converter;
    private: System::Windows::Forms::ListBox^ listBox_Music;
    private: System::Windows::Forms::Button^ button_AddMusic;
    private: System::Windows::Forms::Button^ button_Stop;
    private: System::Windows::Forms::Button^ button_Pause;
    private: System::Windows::Forms::Button^ button_Play;
    private: System::Windows::Forms::Button^ button_AddToFavorites;
    private: System::Windows::Forms::Button^ button_RemoveFavorite;
    private: System::Windows::Forms::Label^ label_CurrentSong;
    private: System::Windows::Forms::Label^ label_HomeInfo;
    private: System::Windows::Forms::TrackBar^ trackBar_Volume;
    private: System::Windows::Forms::TrackBar^ trackBar_Progress;
    private: System::Windows::Forms::Timer^ timer_Music;
    private: System::Windows::Forms::Button^ button_Next;
    private: System::Windows::Forms::Button^ button_Previous;
    private: System::Windows::Forms::ListBox^ listBox_Favorites;
    private: System::Windows::Forms::TextBox^ textBox_Search;
    private: System::Windows::Forms::Button^ button_SearchMusic;



        System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->panel_Header = (gcnew System::Windows::Forms::Panel());
            this->label_HisMusic = (gcnew System::Windows::Forms::Label());
            this->label_Title = (gcnew System::Windows::Forms::Label());
            this->button_Close = (gcnew System::Windows::Forms::Button());
            this->button_Minimize = (gcnew System::Windows::Forms::Button());
            this->panel_Menu = (gcnew System::Windows::Forms::Panel());
            this->button_Converter = (gcnew System::Windows::Forms::Button());
            this->button_Favorites = (gcnew System::Windows::Forms::Button());
            this->button_Search = (gcnew System::Windows::Forms::Button());
            this->button_Home = (gcnew System::Windows::Forms::Button());
            this->panel_Footer = (gcnew System::Windows::Forms::Panel());
            this->button_Next = (gcnew System::Windows::Forms::Button());
            this->button_Previous = (gcnew System::Windows::Forms::Button());
            this->trackBar_Volume = (gcnew System::Windows::Forms::TrackBar());
            this->trackBar_Progress = (gcnew System::Windows::Forms::TrackBar());
            this->button_Play = (gcnew System::Windows::Forms::Button());
            this->label_CurrentSong = (gcnew System::Windows::Forms::Label());
            this->button_Stop = (gcnew System::Windows::Forms::Button());
            this->button_Pause = (gcnew System::Windows::Forms::Button());
            this->label_Footer = (gcnew System::Windows::Forms::Label());
            this->panel_Home = (gcnew System::Windows::Forms::Panel());
            this->label_HomeInfo = (gcnew System::Windows::Forms::Label());
            this->panel_Search = (gcnew System::Windows::Forms::Panel());
            this->textBox_Search = (gcnew System::Windows::Forms::TextBox());
            this->button_SearchMusic = (gcnew System::Windows::Forms::Button());
            this->panel_Favorites = (gcnew System::Windows::Forms::Panel());
            this->listBox_Favorites = (gcnew System::Windows::Forms::ListBox());
            this->button_RemoveFavorite = (gcnew System::Windows::Forms::Button());
            this->panel_Converter = (gcnew System::Windows::Forms::Panel());
            this->listBox_Music = (gcnew System::Windows::Forms::ListBox());
            this->button_AddMusic = (gcnew System::Windows::Forms::Button());
            this->button_AddToFavorites = (gcnew System::Windows::Forms::Button());
            this->timer_Music = (gcnew System::Windows::Forms::Timer(this->components));
            this->panel_Header->SuspendLayout();
            this->panel_Menu->SuspendLayout();
            this->panel_Footer->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_Volume))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_Progress))->BeginInit();
            this->panel_Home->SuspendLayout();
            this->panel_Search->SuspendLayout();
            this->panel_Favorites->SuspendLayout();
            this->panel_Converter->SuspendLayout();
            this->SuspendLayout();
            // 
            // panel_Header
            // 
            this->panel_Header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->panel_Header->Controls->Add(this->label_HisMusic);
            this->panel_Header->Controls->Add(this->label_Title);
            this->panel_Header->Location = System::Drawing::Point(0, 0);
            this->panel_Header->Name = L"panel_Header";
            this->panel_Header->Size = System::Drawing::Size(1300, 80);
            this->panel_Header->TabIndex = 0;
            // 
            // label_HisMusic
            // 
            this->label_HisMusic->AutoSize = true;
            this->label_HisMusic->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 25.8F));
            this->label_HisMusic->ForeColor = System::Drawing::Color::White;
            this->label_HisMusic->Location = System::Drawing::Point(25, 15);
            this->label_HisMusic->Name = L"label_HisMusic";
            this->label_HisMusic->Size = System::Drawing::Size(275, 50);
            this->label_HisMusic->TabIndex = 0;
            this->label_HisMusic->Text = L"🎵 HisMusic";
            // 
            // label_Title
            // 
            this->label_Title->AutoSize = true;
            this->label_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F));
            this->label_Title->ForeColor = System::Drawing::SystemColors::WindowFrame;
            this->label_Title->Location = System::Drawing::Point(420, 25);
            this->label_Title->Name = L"label_Title";
            this->label_Title->Size = System::Drawing::Size(346, 32);
            this->label_Title->TabIndex = 1;
            this->label_Title->Text = L"HisMusic – personal player";
            // 
            // button_Close
            // 
            this->button_Close->BackColor = System::Drawing::Color::Black;
            this->button_Close->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button_Close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Close->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold));
            this->button_Close->ForeColor = System::Drawing::Color::White;
            this->button_Close->Location = System::Drawing::Point(1250, 15);
            this->button_Close->Name = L"button_Close";
            this->button_Close->Size = System::Drawing::Size(40, 35);
            this->button_Close->TabIndex = 2;
            this->button_Close->Text = L"X";
            this->button_Close->UseVisualStyleBackColor = false;
            this->button_Close->Click += gcnew System::EventHandler(this, &MyForm::button_Close_Click);
            // 
            // button_Minimize
            // 
            this->button_Minimize->BackColor = System::Drawing::Color::Black;
            this->button_Minimize->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button_Minimize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Minimize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
            this->button_Minimize->ForeColor = System::Drawing::Color::White;
            this->button_Minimize->Location = System::Drawing::Point(1200, 15);
            this->button_Minimize->Name = L"button_Minimize";
            this->button_Minimize->Size = System::Drawing::Size(40, 35);
            this->button_Minimize->TabIndex = 3;
            this->button_Minimize->Text = L"–";
            this->button_Minimize->UseVisualStyleBackColor = false;
            this->button_Minimize->Click += gcnew System::EventHandler(this, &MyForm::button_Minimize_Click);
            // 
            // panel_Menu
            // 
            this->panel_Menu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->panel_Menu->Controls->Add(this->button_Converter);
            this->panel_Menu->Controls->Add(this->button_Favorites);
            this->panel_Menu->Controls->Add(this->button_Search);
            this->panel_Menu->Controls->Add(this->button_Home);
            this->panel_Menu->Location = System::Drawing::Point(0, 80);
            this->panel_Menu->Name = L"panel_Menu";
            this->panel_Menu->Size = System::Drawing::Size(375, 600);
            this->panel_Menu->TabIndex = 4;
            // 
            // button_Converter
            // 
            this->button_Converter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->button_Converter->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button_Converter->FlatAppearance->BorderSize = 0;
            this->button_Converter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Converter->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14));
            this->button_Converter->ForeColor = System::Drawing::Color::White;
            this->button_Converter->Location = System::Drawing::Point(50, 350);
            this->button_Converter->Name = L"button_Converter";
            this->button_Converter->Size = System::Drawing::Size(260, 60);
            this->button_Converter->TabIndex = 0;
            this->button_Converter->Text = L"⟳ Converter";
            this->button_Converter->UseVisualStyleBackColor = false;
            this->button_Converter->Click += gcnew System::EventHandler(this, &MyForm::button_Converter_Click);
            // 
            // button_Favorites
            // 
            this->button_Favorites->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->button_Favorites->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button_Favorites->FlatAppearance->BorderSize = 0;
            this->button_Favorites->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Favorites->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14));
            this->button_Favorites->ForeColor = System::Drawing::Color::White;
            this->button_Favorites->Location = System::Drawing::Point(50, 250);
            this->button_Favorites->Name = L"button_Favorites";
            this->button_Favorites->Size = System::Drawing::Size(260, 60);
            this->button_Favorites->TabIndex = 1;
            this->button_Favorites->Text = L"❤️ Favorites";
            this->button_Favorites->UseVisualStyleBackColor = false;
            this->button_Favorites->Click += gcnew System::EventHandler(this, &MyForm::button_Favorites_Click);
            // 
            // button_Search
            // 
            this->button_Search->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->button_Search->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button_Search->FlatAppearance->BorderSize = 0;
            this->button_Search->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Search->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14));
            this->button_Search->ForeColor = System::Drawing::Color::White;
            this->button_Search->Location = System::Drawing::Point(50, 150);
            this->button_Search->Name = L"button_Search";
            this->button_Search->Size = System::Drawing::Size(260, 60);
            this->button_Search->TabIndex = 2;
            this->button_Search->Text = L"🔍 Search";
            this->button_Search->UseVisualStyleBackColor = false;
            this->button_Search->Click += gcnew System::EventHandler(this, &MyForm::button_Search_Click);
            // 
            // button_Home
            // 
            this->button_Home->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->button_Home->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button_Home->FlatAppearance->BorderSize = 0;
            this->button_Home->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Home->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16.2F));
            this->button_Home->ForeColor = System::Drawing::Color::White;
            this->button_Home->Location = System::Drawing::Point(50, 50);
            this->button_Home->Name = L"button_Home";
            this->button_Home->Size = System::Drawing::Size(260, 60);
            this->button_Home->TabIndex = 3;
            this->button_Home->Text = L"🏠 Home";
            this->button_Home->UseVisualStyleBackColor = false;
            this->button_Home->Click += gcnew System::EventHandler(this, &MyForm::button_Home_Click);
            // 
            // panel_Footer
            // 
            this->panel_Footer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->panel_Footer->Controls->Add(this->button_Next);
            this->panel_Footer->Controls->Add(this->button_Previous);
            this->panel_Footer->Controls->Add(this->trackBar_Volume);
            this->panel_Footer->Controls->Add(this->trackBar_Progress);
            this->panel_Footer->Controls->Add(this->button_Play);
            this->panel_Footer->Controls->Add(this->label_CurrentSong);
            this->panel_Footer->Controls->Add(this->button_Stop);
            this->panel_Footer->Controls->Add(this->button_Pause);
            this->panel_Footer->Controls->Add(this->label_Footer);
            this->panel_Footer->Location = System::Drawing::Point(0, 680);
            this->panel_Footer->Name = L"panel_Footer";
            this->panel_Footer->Size = System::Drawing::Size(1300, 80);
            this->panel_Footer->TabIndex = 4;
            // 
            // button_Next
            // 
            this->button_Next->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->button_Next->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button_Next->FlatAppearance->BorderSize = 0;
            this->button_Next->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Next->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14));
            this->button_Next->ForeColor = System::Drawing::Color::White;
            this->button_Next->Location = System::Drawing::Point(680, 5);
            this->button_Next->Name = L"button_Next";
            this->button_Next->Size = System::Drawing::Size(50, 45);
            this->button_Next->TabIndex = 8;
            this->button_Next->Text = L"⏭";
            this->button_Next->UseVisualStyleBackColor = false;
            this->button_Next->Click += gcnew System::EventHandler(this, &MyForm::button_Next_Click);
            // 
            // button_Previous
            // 
            this->button_Previous->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->button_Previous->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button_Previous->FlatAppearance->BorderSize = 0;
            this->button_Previous->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Previous->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14));
            this->button_Previous->ForeColor = System::Drawing::Color::White;
            this->button_Previous->Location = System::Drawing::Point(480, 5);
            this->button_Previous->Name = L"button_Previous";
            this->button_Previous->Size = System::Drawing::Size(50, 45);
            this->button_Previous->TabIndex = 7;
            this->button_Previous->Text = L"⏮";
            this->button_Previous->UseVisualStyleBackColor = false;
            this->button_Previous->Click += gcnew System::EventHandler(this, &MyForm::button_Previous_Click);
            // 
            // trackBar_Volume
            // 
            this->trackBar_Volume->AutoSize = false;
            this->trackBar_Volume->Location = System::Drawing::Point(801, 36);
            this->trackBar_Volume->Maximum = 100;
            this->trackBar_Volume->Name = L"trackBar_Volume";
            this->trackBar_Volume->Size = System::Drawing::Size(90, 20);
            this->trackBar_Volume->TabIndex = 5;
            this->trackBar_Volume->TickStyle = System::Windows::Forms::TickStyle::None;
            this->trackBar_Volume->Value = 50;
            this->trackBar_Volume->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Volume_Scroll);
            // 
            // trackBar_Progress
            // 
            this->trackBar_Progress->AutoSize = false;
            this->trackBar_Progress->Enabled = false;
            this->trackBar_Progress->Location = System::Drawing::Point(455, 55);
            this->trackBar_Progress->Maximum = 100;
            this->trackBar_Progress->Name = L"trackBar_Progress";
            this->trackBar_Progress->Size = System::Drawing::Size(300, 15);
            this->trackBar_Progress->TabIndex = 6;
            this->trackBar_Progress->TickStyle = System::Windows::Forms::TickStyle::None;
            // 
            // button_Play
            // 
            this->button_Play->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->button_Play->FlatAppearance->BorderSize = 0;
            this->button_Play->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Play->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button_Play->ForeColor = System::Drawing::Color::White;
            this->button_Play->Location = System::Drawing::Point(580, 5);
            this->button_Play->Name = L"button_Play";
            this->button_Play->Size = System::Drawing::Size(60, 50);
            this->button_Play->TabIndex = 1;
            this->button_Play->Text = L"▶ Play";
            this->button_Play->UseVisualStyleBackColor = false;
            this->button_Play->Click += gcnew System::EventHandler(this, &MyForm::button_Play_Click);
            // 
            // label_CurrentSong
            // 
            this->label_CurrentSong->AutoSize = true;
            this->label_CurrentSong->BackColor = System::Drawing::Color::Transparent;
            this->label_CurrentSong->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->label_CurrentSong->ForeColor = System::Drawing::Color::White;
            this->label_CurrentSong->Location = System::Drawing::Point(930, 31);
            this->label_CurrentSong->Name = L"label_CurrentSong";
            this->label_CurrentSong->Size = System::Drawing::Size(158, 25);
            this->label_CurrentSong->TabIndex = 4;
            this->label_CurrentSong->Text = L"No music playing";
            // 
            // button_Stop
            // 
            this->button_Stop->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->button_Stop->FlatAppearance->BorderSize = 0;
            this->button_Stop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Stop->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->button_Stop->ForeColor = System::Drawing::Color::White;
            this->button_Stop->Location = System::Drawing::Point(620, 12);
            this->button_Stop->Name = L"button_Stop";
            this->button_Stop->Size = System::Drawing::Size(75, 37);
            this->button_Stop->TabIndex = 3;
            this->button_Stop->Text = L"⏹ Stop";
            this->button_Stop->UseVisualStyleBackColor = false;
            this->button_Stop->Click += gcnew System::EventHandler(this, &MyForm::button_Stop_Click);
            // 
            // button_Pause
            // 
            this->button_Pause->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->button_Pause->FlatAppearance->BorderSize = 0;
            this->button_Pause->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_Pause->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->button_Pause->ForeColor = System::Drawing::Color::White;
            this->button_Pause->Location = System::Drawing::Point(520, 12);
            this->button_Pause->Name = L"button_Pause";
            this->button_Pause->Size = System::Drawing::Size(70, 37);
            this->button_Pause->TabIndex = 2;
            this->button_Pause->Text = L"⏸ Pause";
            this->button_Pause->UseVisualStyleBackColor = false;
            this->button_Pause->Click += gcnew System::EventHandler(this, &MyForm::button_Pause_Click);
            // 
            // label_Footer
            // 
            this->label_Footer->AutoSize = true;
            this->label_Footer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold));
            this->label_Footer->ForeColor = System::Drawing::SystemColors::WindowFrame;
            this->label_Footer->Location = System::Drawing::Point(30, 31);
            this->label_Footer->Name = L"label_Footer";
            this->label_Footer->Size = System::Drawing::Size(324, 20);
            this->label_Footer->TabIndex = 0;
            this->label_Footer->Text = L"© 2026 HisMusic. All rights reserved.";
            // 
            // panel_Home
            // 
            this->panel_Home->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->panel_Home->Controls->Add(this->label_HomeInfo);
            this->panel_Home->Location = System::Drawing::Point(425, 130);
            this->panel_Home->Name = L"panel_Home";
            this->panel_Home->Size = System::Drawing::Size(825, 500);
            this->panel_Home->TabIndex = 3;
            this->panel_Home->Visible = false;
            // 
            // label_HomeInfo
            // 
            this->label_HomeInfo->AutoSize = true;
            this->label_HomeInfo->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18));
            this->label_HomeInfo->ForeColor = System::Drawing::Color::White;
            this->label_HomeInfo->Location = System::Drawing::Point(40, 40);
            this->label_HomeInfo->Name = L"label_HomeInfo";
            this->label_HomeInfo->Size = System::Drawing::Size(369, 34);
            this->label_HomeInfo->TabIndex = 0;
            this->label_HomeInfo->Text = L"🎵 Welcome to HisMusic";
            // 
            // panel_Search
            // 
            this->panel_Search->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->panel_Search->Controls->Add(this->textBox_Search);
            this->panel_Search->Controls->Add(this->button_SearchMusic);
            this->panel_Search->Location = System::Drawing::Point(425, 130);
            this->panel_Search->Name = L"panel_Search";
            this->panel_Search->Size = System::Drawing::Size(825, 500);
            this->panel_Search->TabIndex = 2;
            this->panel_Search->Visible = false;
            // 
            // textBox_Search
            // 
            this->textBox_Search->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->textBox_Search->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->textBox_Search->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
            this->textBox_Search->ForeColor = System::Drawing::Color::White;
            this->textBox_Search->Location = System::Drawing::Point(40, 40);
            this->textBox_Search->Name = L"textBox_Search";
            this->textBox_Search->Size = System::Drawing::Size(500, 34);
            this->textBox_Search->TabIndex = 0;
            // 
            // button_SearchMusic
            // 
            this->button_SearchMusic->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
                static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
            this->button_SearchMusic->FlatAppearance->BorderSize = 0;
            this->button_SearchMusic->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_SearchMusic->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
            this->button_SearchMusic->ForeColor = System::Drawing::Color::White;
            this->button_SearchMusic->Location = System::Drawing::Point(570, 35);
            this->button_SearchMusic->Name = L"button_SearchMusic";
            this->button_SearchMusic->Size = System::Drawing::Size(150, 40);
            this->button_SearchMusic->TabIndex = 1;
            this->button_SearchMusic->Text = L"🔍 Search";
            this->button_SearchMusic->UseVisualStyleBackColor = false;
            this->button_SearchMusic->Click += gcnew System::EventHandler(this, &MyForm::button_SearchMusic_Click);
            // 
            // panel_Favorites
            // 
            this->panel_Favorites->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->panel_Favorites->Controls->Add(this->listBox_Favorites);
            this->panel_Favorites->Controls->Add(this->button_RemoveFavorite);
            this->panel_Favorites->Location = System::Drawing::Point(425, 130);
            this->panel_Favorites->Name = L"panel_Favorites";
            this->panel_Favorites->Size = System::Drawing::Size(825, 500);
            this->panel_Favorites->TabIndex = 1;
            this->panel_Favorites->Visible = false;
            // 
            // listBox_Favorites
            // 
            this->listBox_Favorites->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->listBox_Favorites->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->listBox_Favorites->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
            this->listBox_Favorites->ForeColor = System::Drawing::Color::White;
            this->listBox_Favorites->FormattingEnabled = true;
            this->listBox_Favorites->ItemHeight = 28;
            this->listBox_Favorites->Location = System::Drawing::Point(40, 100);
            this->listBox_Favorites->Name = L"listBox_Favorites";
            this->listBox_Favorites->Size = System::Drawing::Size(720, 280);
            this->listBox_Favorites->TabIndex = 2;
            this->listBox_Favorites->DoubleClick += gcnew System::EventHandler(this, &MyForm::listBox_Favorites_DoubleClick);
            // 
            // button_RemoveFavorite
            // 
            this->button_RemoveFavorite->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->button_RemoveFavorite->FlatAppearance->BorderSize = 0;
            this->button_RemoveFavorite->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_RemoveFavorite->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 11));
            this->button_RemoveFavorite->ForeColor = System::Drawing::Color::White;
            this->button_RemoveFavorite->Location = System::Drawing::Point(40, 40);
            this->button_RemoveFavorite->Name = L"button_RemoveFavorite";
            this->button_RemoveFavorite->Size = System::Drawing::Size(240, 45);
            this->button_RemoveFavorite->TabIndex = 3;
            this->button_RemoveFavorite->Text = L"❌ Remove Favorite";
            this->button_RemoveFavorite->UseVisualStyleBackColor = false;
            this->button_RemoveFavorite->Click += gcnew System::EventHandler(this, &MyForm::button_RemoveFavorite_Click);
            // 
            // panel_Converter
            // 
            this->panel_Converter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->panel_Converter->Controls->Add(this->listBox_Music);
            this->panel_Converter->Controls->Add(this->button_AddMusic);
            this->panel_Converter->Controls->Add(this->button_AddToFavorites);
            this->panel_Converter->Location = System::Drawing::Point(425, 130);
            this->panel_Converter->Name = L"panel_Converter";
            this->panel_Converter->Size = System::Drawing::Size(825, 500);
            this->panel_Converter->TabIndex = 0;
            this->panel_Converter->Visible = false;
            this->panel_Converter->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_Converter_Paint);
            // 
            // listBox_Music
            // 
            this->listBox_Music->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->listBox_Music->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->listBox_Music->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
            this->listBox_Music->ForeColor = System::Drawing::Color::White;
            this->listBox_Music->FormattingEnabled = true;
            this->listBox_Music->ItemHeight = 28;
            this->listBox_Music->Location = System::Drawing::Point(40, 120);
            this->listBox_Music->Name = L"listBox_Music";
            this->listBox_Music->Size = System::Drawing::Size(720, 280);
            this->listBox_Music->TabIndex = 1;
            this->listBox_Music->DoubleClick += gcnew System::EventHandler(this, &MyForm::listBox_Music_DoubleClick);
            // 
            // button_AddMusic
            // 
            this->button_AddMusic->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->button_AddMusic->FlatAppearance->BorderSize = 0;
            this->button_AddMusic->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_AddMusic->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12));
            this->button_AddMusic->ForeColor = System::Drawing::Color::White;
            this->button_AddMusic->Location = System::Drawing::Point(40, 40);
            this->button_AddMusic->Name = L"button_AddMusic";
            this->button_AddMusic->Size = System::Drawing::Size(220, 50);
            this->button_AddMusic->TabIndex = 0;
            this->button_AddMusic->Text = L"🎵 Add Music";
            this->button_AddMusic->UseVisualStyleBackColor = false;
            this->button_AddMusic->Click += gcnew System::EventHandler(this, &MyForm::button_AddMusic_Click);
            // 
            // button_AddToFavorites
            // 
            this->button_AddToFavorites->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
                static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
            this->button_AddToFavorites->FlatAppearance->BorderSize = 0;
            this->button_AddToFavorites->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button_AddToFavorites->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12));
            this->button_AddToFavorites->ForeColor = System::Drawing::Color::White;
            this->button_AddToFavorites->Location = System::Drawing::Point(300, 40);
            this->button_AddToFavorites->Name = L"button_AddToFavorites";
            this->button_AddToFavorites->Size = System::Drawing::Size(260, 50);
            this->button_AddToFavorites->TabIndex = 2;
            this->button_AddToFavorites->Text = L"❤️ Add to Favorites";
            this->button_AddToFavorites->UseVisualStyleBackColor = false;
            this->button_AddToFavorites->Click += gcnew System::EventHandler(this, &MyForm::button_AddToFavorites_Click);
            // 
            // timer_Music
            // 
            this->timer_Music->Interval = 500;
            this->timer_Music->Tick += gcnew System::EventHandler(this, &MyForm::timer_Music_Tick);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->ClientSize = System::Drawing::Size(1300, 760);
            this->Controls->Add(this->panel_Converter);
            this->Controls->Add(this->panel_Favorites);
            this->Controls->Add(this->panel_Search);
            this->Controls->Add(this->panel_Home);
            this->Controls->Add(this->panel_Footer);
            this->Controls->Add(this->button_Minimize);
            this->Controls->Add(this->button_Close);
            this->Controls->Add(this->panel_Menu);
            this->Controls->Add(this->panel_Header);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"HisMusic";
            this->panel_Header->ResumeLayout(false);
            this->panel_Header->PerformLayout();
            this->panel_Menu->ResumeLayout(false);
            this->panel_Footer->ResumeLayout(false);
            this->panel_Footer->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_Volume))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_Progress))->EndInit();
            this->panel_Home->ResumeLayout(false);
            this->panel_Home->PerformLayout();
            this->panel_Search->ResumeLayout(false);
            this->panel_Search->PerformLayout();
            this->panel_Favorites->ResumeLayout(false);
            this->panel_Converter->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

        void AddLabelToPanel(Panel^ panel, String^ text)
        {
            Label^ lbl = gcnew Label();
            lbl->AutoSize = true;
            lbl->Text = text;
            lbl->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
            lbl->ForeColor = System::Drawing::Color::White;
            lbl->Location = System::Drawing::Point(50, 40);
            panel->Controls->Add(lbl);
        }

        // Панель перемикання
        void ShowPanel(Panel^ activePanel)
        {
            array<Panel^>^ panels = { panel_Home, panel_Search, panel_Favorites, panel_Converter };
            for each(Panel ^ p in panels)
            {
                p->Visible = (p == activePanel);
            }
        }

    private: System::Void button_Close_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    private: System::Void button_Minimize_Click(System::Object^ sender, System::EventArgs^ e) {
        this->WindowState = FormWindowState::Minimized;
    }
    private: System::Void button_Home_Click(System::Object^ sender, System::EventArgs^ e) {
        ShowPanel(this->panel_Home);
    }
    private: System::Void button_Search_Click(System::Object^ sender, System::EventArgs^ e) {
        ShowPanel(this->panel_Search);
    }
    private: System::Void button_Favorites_Click(System::Object^ sender, System::EventArgs^ e) {
        ShowPanel(this->panel_Favorites);
    }
    private: System::Void button_Converter_Click(System::Object^ sender, System::EventArgs^ e) {
        ShowPanel(this->panel_Converter);
    }
    private: System::Void panel_Converter_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void button_AddMusic_Click(System::Object^ sender, System::EventArgs^ e) {
        OpenFileDialog^ ofd = gcnew OpenFileDialog();

        ofd->Filter = "Music Files|*.mp3;*.wav";

        if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            musicFiles->Add(ofd->FileName);

            String^ songName =
                System::IO::Path::GetFileName(ofd->FileName);

            listBox_Music->Items->Add(L"🎵  " + songName);
            UpdateHomeInfo();
        }
    }
    private: System::Void listBox_Music_DoubleClick(System::Object^ sender, System::EventArgs^ e)
    {
        if (listBox_Music->SelectedIndex < 0)
            return;

        if (outputDevice != nullptr)
        {
            outputDevice->Stop();
            delete outputDevice;
        }

        if (audioFile != nullptr)
        {
            delete audioFile;
        }

        String^ selectedFile = musicFiles[listBox_Music->SelectedIndex];

        audioFile = gcnew AudioFileReader(selectedFile);

        outputDevice = gcnew WaveOutEvent();
        outputDevice->Init(audioFile);
        outputDevice->Play();
        timer_Music->Start();
        String^ songName = System::IO::Path::GetFileNameWithoutExtension(selectedFile);

        if (songName->Length > 30)
        {
            songName = songName->Substring(0, 30) + L"...";
        }

        label_CurrentSong->Text = L"🎵 " + songName;
    }
    private: System::Void button_Play_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (outputDevice != nullptr)
        {
            outputDevice->Play();
        }
    }
    private: System::Void button_Pause_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (outputDevice != nullptr)
        {
            outputDevice->Pause();
        }
    }
    private: System::Void button_Stop_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (outputDevice != nullptr)
        {
            outputDevice->Stop();
            delete outputDevice;
            outputDevice = nullptr;
        }

        if (audioFile != nullptr)
        {
            delete audioFile;
            audioFile = nullptr;
        }

        trackBar_Progress->Value = 0;
        label_CurrentSong->Text = L"No music playing";

        timer_Music->Stop();
    }
    private: System::Void trackBar_Volume_Scroll(System::Object^ sender, System::EventArgs^ e) {
        if (outputDevice != nullptr)
        {
            outputDevice->Volume = trackBar_Volume->Value / 100.0f;
        }
    }
    private: System::Void timer_Music_Tick(System::Object^ sender, System::EventArgs^ e) {

        if (audioFile != nullptr)
        {
            trackBar_Progress->Maximum =
                (int)audioFile->TotalTime.TotalSeconds;

            trackBar_Progress->Value =
                (int)audioFile->CurrentTime.TotalSeconds;

            // Autoplay Next
            if (audioFile->CurrentTime >= audioFile->TotalTime)
            {
                button_Next_Click(nullptr, nullptr);
            }
        }
    }
    private: System::Void button_Previous_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listBox_Music->Items->Count == 0)
            return;

        int index = listBox_Music->SelectedIndex;

        if (index > 0)
        {
            listBox_Music->SelectedIndex = index - 1;
            listBox_Music_DoubleClick(nullptr, nullptr);
        }
    }
    private: System::Void button_Next_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listBox_Music->Items->Count == 0)
            return;

        int index = listBox_Music->SelectedIndex;

        if (index < listBox_Music->Items->Count - 1)
        {
            listBox_Music->SelectedIndex = index + 1;
            listBox_Music_DoubleClick(nullptr, nullptr);
        }
    }
    private: System::Void button_AddToFavorites_Click(System::Object^ sender, System::EventArgs^ e) {

        if (listBox_Music->SelectedIndex >= 0)
        {
            String^ song = listBox_Music->SelectedItem->ToString();

            if (!listBox_Favorites->Items->Contains(song))
            {
                listBox_Favorites->Items->Add(song);
                UpdateHomeInfo();
            }
        }
    }
    private: System::Void listBox_Favorites_DoubleClick(System::Object^ sender, System::EventArgs^ e) {

        if (listBox_Favorites->SelectedIndex < 0)
            return;

        String^ selectedSong =
            listBox_Favorites->SelectedItem->ToString();

        for (int i = 0; i < listBox_Music->Items->Count; i++)
        {
            if (listBox_Music->Items[i]->ToString() == selectedSong)
            {
                listBox_Music->SelectedIndex = i;
                listBox_Music_DoubleClick(nullptr, nullptr);
                break;
            }
        }
    }
    private: System::Void button_SearchMusic_Click(
        System::Object^ sender,
        System::EventArgs^ e)
    {
        String^ searchText = textBox_Search->Text->ToLower();

        for (int i = 0;
            i < listBox_Music->Items->Count;
            i++)
        {
            String^ song =
                listBox_Music->Items[i]->ToString()->ToLower();

            if (song->Contains(searchText))
            {
                ShowPanel(panel_Converter);

                listBox_Music->SelectedIndex = i;

                listBox_Music_DoubleClick(nullptr, nullptr);

                return;
            }
        }

        MessageBox::Show(L"Music not found", L"Search", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    void UpdateHomeInfo() {
    label_HomeInfo->Text = L"🎵 Welcome to HisMusic\n\n" + L"Total songs: " + listBox_Music->Items->Count.ToString() + L"\nFavorites: " + listBox_Favorites->Items->Count.ToString();
    }
    private: System::Void button_RemoveFavorite_Click(
        System::Object^ sender,
        System::EventArgs^ e)
    {
        if (listBox_Favorites->SelectedIndex >= 0)
        {
            listBox_Favorites->Items->RemoveAt(
                listBox_Favorites->SelectedIndex);

            UpdateHomeInfo();
        }
    }
};
}
