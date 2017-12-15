#include "WinCommander.h"
#include <iostream>

const size_t MAX_COMMAND_LEN = 200;

using namespace Easypp::EasyCMD;

int WinCommander::SendCommand(const std::string& cmd)
{
	SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
	HANDLE hRead, hWrite;
	if (!CreatePipe(&hRead, &hWrite, &sa, 0))
	{
		return -1;
	}

	STARTUPINFO si = { sizeof(STARTUPINFO) };
	GetStartupInfo(&si);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	si.wShowWindow = SW_HIDE;
	si.hStdError = hWrite;
	si.hStdOutput = hWrite;

	int len2 = sizeof(wchar_t) * MultiByteToWideChar(CP_UTF8, 0, cmd, -1, NULL, 0);
	LPWSTR cmd2 = new WCHAR[len2];
	MultiByteToWideChar(CP_UTF8, 0, cmd, -1, cmd2, len2);
	PROCESS_INFORMATION pi;
	
	PVOID OldValue = NULL;
#ifdef COMPILE_FOR_64BIT_SYS
	if (Wow64DisableWow64FsRedirection(&OldValue))
#endif
	{
		if (!CreateProcess(NULL, cmd2, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
		{
			DWORD error = GetLastError();
			CloseHandle(hWrite);
			CloseHandle(hRead);
			delete[]cmd2;
			return -1;
		}
	}
#ifdef COMPILE_FOR_64BIT_SYS
	else
	{
		DWORD error = GetLastError();
		CloseHandle(hWrite);
		CloseHandle(hRead);
		delete[] cmd2;
		return -1;
	}
#endif
	delete[] cmd2;
	CloseHandle(hWrite);
	CloseHandle(hRead);
	return 0;
}