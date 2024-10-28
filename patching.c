#include<Windows.h>
#include<winternl.h>
#include<stdio.h>

extern PPEB getPEB(void);
extern BYTE PEBPatcher(void);

int main(int argc, char* argv[]) {
	printf("[*] Getting the PEB ");
	PPEB pPEB = getPEB();
	printf("[+] PEB is : 0x%p\n", pPEB);

	if (pPEB->BeingDebugged != 0) {
		printf("[*] PEB->Being Debugged: 0x%d\n", pPEB->BeingDebugged);
		printf("[*] Debugger Detected!! \n [+] Patching the PEB \n");
		PEBPatcher();
	}
	else {
		printf("[*] PEB->Being Debugged: 0x%d\n", pPEB->BeingDebugged);
		printf("[*] Not Being Debugged\n ");
		MessageBoxW(NULL, L"No Debugger Detected!! ", L"HELLO FRIEND! ", MB_ICONERROR | MB_OK);
		return 0;

	}
	printf("[*] PEB should have been Patched\n ");
	printf("[*] PEB->Being Debugged: 0x%d\n", pPEB->BeingDebugged);
	printf("[*] executing our payload\n");
	MessageBoxW(NULL, L"PATCHED SUCCEED!! ", L"HELLO FRIEND! ", MB_ICONERROR | MB_OK);
	return EXIT_SUCCESS;
}