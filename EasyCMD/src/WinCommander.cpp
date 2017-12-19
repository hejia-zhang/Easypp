#include "WinCommander.h"
#include <iostream>
#include <namedpipeapi.h>
#include <processthreadsapi.h>
#include <winbase.h>
#include <winuser.h>
#include <string>

const size_t MAX_COMMAND_LEN = 200;

using namespace Easypp::EasyCMD;

bool WinCommander::Init()
{
    if (!EasyCreatePipe())
    {
        return false;
    }

    if (!EasyCreateProcess())
    {
        return false;
    }
}

bool WinCommander::EasyCreatePipe()
{
    SECURITY_ATTRIBUTES t_sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
    if (!CreatePipe(&m_pPipeRead, &m_pPipeWrite, &t_sa, 0))
    {
        return false;
    }
    return true;
}

bool WinCommander::EasyCreateProcess()
{
    STARTUPINFO t_si = { sizeof(STARTUPINFO)};
    GetStartupInfo(&t_si);
    t_si.wShowWindow = SW_SHOW;
    t_si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    t_si.hStdInput = m_pPipeRead;
    t_si.hStdOutput = m_pPipeWrite;
    t_si.hStdError = (void *)(STD_ERROR_HANDLE);
}

int WinCommander::SendCommand(const std::string& cmd)
{
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