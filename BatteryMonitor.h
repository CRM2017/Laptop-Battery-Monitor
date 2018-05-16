#pragma once
namespace BatteryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for BatteryMonitor
	/// </summary>
	public ref class BatteryMonitor : public System::Windows::Forms::Form
	{
	public:
		BatteryMonitor(void)
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
		~BatteryMonitor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label33;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(100, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(247, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Remaining Power:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(371, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 32);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(32, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(315, 32);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Current Power Scheme:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(371, 106);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 32);
			this->label4->TabIndex = 3;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(46, 161);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(301, 32);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Current Power Source:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(371, 161);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 32);
			this->label6->TabIndex = 5;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(176, 349);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(171, 32);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Technology:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(197, 417);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(150, 32);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Chemistry:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(371, 349);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(93, 32);
			this->label9->TabIndex = 9;
			this->label9->Text = L"label9";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(371, 417);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(109, 32);
			this->label10->TabIndex = 10;
			this->label10->Text = L"label10";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(117, 481);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(230, 32);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Design Capacity:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(117, 542);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(230, 32);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Full       Capacity:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(125, 656);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(222, 32);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Battery      Wear:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(371, 481);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(109, 32);
			this->label14->TabIndex = 14;
			this->label14->Text = L"label14";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(371, 542);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(109, 32);
			this->label15->TabIndex = 15;
			this->label15->Text = L"label15";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(371, 656);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(109, 32);
			this->label16->TabIndex = 16;
			this->label16->Text = L"label16";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(144, 721);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(203, 32);
			this->label17->TabIndex = 17;
			this->label17->Text = L"History Cycles:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(371, 721);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(109, 32);
			this->label18->TabIndex = 18;
			this->label18->Text = L"label18";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(151, 799);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(196, 32);
			this->label19->TabIndex = 19;
			this->label19->Text = L"Battery status:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(125, 867);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(222, 32);
			this->label20->TabIndex = 20;
			this->label20->Text = L"Current Voltage:";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(163, 936);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(184, 32);
			this->label21->TabIndex = 21;
			this->label21->Text = L"Current Rate:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(371, 799);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(109, 32);
			this->label22->TabIndex = 22;
			this->label22->Text = L"label22";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(371, 867);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(109, 32);
			this->label23->TabIndex = 23;
			this->label23->Text = L"label23";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(371, 936);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(109, 32);
			this->label24->TabIndex = 24;
			this->label24->Text = L"label24";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(46, 225);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(916, 32);
			this->label25->TabIndex = 25;
			this->label25->Text = L"Please click left mouse button anywhere to update following information";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(112, 603);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(235, 32);
			this->label26->TabIndex = 26;
			this->label26->Text = L"Current Capacity:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(371, 603);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(109, 32);
			this->label27->TabIndex = 27;
			this->label27->Text = L"label27";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(152, 295);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(195, 32);
			this->label28->TabIndex = 28;
			this->label28->Text = L"Battery Name:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(371, 295);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(109, 32);
			this->label29->TabIndex = 29;
			this->label29->Text = L"label29";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(61, 1002);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(286, 32);
			this->label30->TabIndex = 30;
			this->label30->Text = L"Current Temperature:";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(371, 1002);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(109, 32);
			this->label31->TabIndex = 31;
			this->label31->Text = L"label31";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(141, 1066);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(206, 32);
			this->label32->TabIndex = 32;
			this->label32->Text = L"Relevant Time:";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(371, 1066);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(109, 32);
			this->label33->TabIndex = 33;
			this->label33->Text = L"label33";
			// 
			// BatteryMonitor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1282, 1248);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"BatteryMonitor";
			this->Text = L"BatteryMonitor";
			this->Load += gcnew System::EventHandler(this, &BatteryMonitor::BatteryMonitor_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
   public: static bool batteryexist = true;
	private: System::Void BatteryMonitor_Load(System::Object^  sender, System::EventArgs^  e) {}
	protected:
		virtual void WndProc(Message% m) override;
		virtual void OnFormClosing(FormClosingEventArgs^ e) override;
		virtual void OnLoad(EventArgs^ e) override;
		void loadBatteryInfo();	
};
}
