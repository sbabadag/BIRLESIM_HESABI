#pragma once
#include "OpenGL.h"
#include "my_OGL_functions.h"


namespace BIRLESIMHESABI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	/// <summary>
	/// MyForm i�in �zet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		OpenGLForm::COpenGL ^ OpenGL;
		TGroup *Group;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Olu�turucu kodunu buraya ekle
			//
			
			OpenGL = gcnew COpenGL(this, 480, 640);
			Group = new TGroup();
			Group->addObject(new TLine(new TPoint(0, 0, 0), new TPoint(100, 100, 0)));
			
		}

	protected:
		/// <summary>
		///Kullan�lan t�m kaynaklar� temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		///Gerekli tasar�mc� de�i�keni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasar�mc� deste�i i�in gerekli metot - bu metodun 
		///i�eri�ini kod d�zenleyici ile de�i�tirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(830, 584);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);
		//
		

		OpenGL->Render();
		Group->draw();

		OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
