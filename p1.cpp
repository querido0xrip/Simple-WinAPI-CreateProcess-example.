#include <iostream>
#include <windows.h> 


// startupinfo, sw_show
// resultado = Ejecutar notepad.exe sin mostrar la ventana al usuario.

int main () {

PROCESS_INFORMATION pi = {0};// recibe los handles y informacion del proceso.

//configura el inicio del proceso.
STARTUPINFO si = {0}; 

si.cb = sizeof(si);
si.dwFlags = STARTF_USESHOWWINDOW; 
si.wShowWindow = SW_HIDE;

BOOL process = CreateProcess (
    L"C:\\Windows\\System32\\notepad.exe",
    NULL,
    NULL,
    NULL,
    FALSE,
    0,
    NULL,
    NULL,
    &si,
    &pi
);

if (process) {
 std::cout<<"Proceso iniciado ";
 std::cout<<"*PID*: " << pi.dwProcessId << "\n";

}

else {
    std::cout<<"No se encontro o ejecuto el proceso." << "\n";

    std::cout<<"error: " << GetLastError() << "\n";
}





 return 0;
}

