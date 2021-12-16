#include "MyForm.h"
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace Project1;

int main() 
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm);

    return 0;
}