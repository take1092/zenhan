#include <iostream>
#include <Windows.h>
#include <imm.h>

using namespace std;

int main(int argc, char* argv[])
{
    const LPARAM IMC_GETOPENSTATUS = 5;
	const LPARAM IMC_SETOPENSTATUS = 6;

	HWND hwnd = GetForegroundWindow();
	if(hwnd == NULL) return 0;

	HWND ime =  ImmGetDefaultIMEWnd(hwnd);
	if(ime == NULL) return 0;

	LRESULT stat;
	if(argc < 2){
		stat = SendMessage(ime, WM_IME_CONTROL, IMC_GETOPENSTATUS, 0);
	}
	else{
		stat = (LPARAM)atoi(argv[1]);
		SendMessage(ime, WM_IME_CONTROL, IMC_SETOPENSTATUS, stat);
	}
	printf("%lld\n", stat);
	return 0;
}