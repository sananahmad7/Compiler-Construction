#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	CCProject::MyForm frm;
	Application::Run(% frm);
}