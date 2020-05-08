#include "proc.h"

DWORD GetProcID(const wchar_t* procName)
{
	DWORD procID = 0;
	HANDLE hSnap = (CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		//Before calling the Process32First function, set this member to sizeof(PROCESSENTRY32). If you do not initialize dwSize, Process32First fails.
		procEntry.dwSize = sizeof(procEntry);

		//loop till we find our process
		if (Process32First(hSnap, &procEntry)) {
			do
				if (!_wcsicmp(procEntry.szExeFile, procName)) {
					{
						procID = procEntry.th32ProcessID;
						break;
					}

				} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);
	return procID;
}

uintptr_t GetModuleBaseAddress(DWORD procID, const wchar_t* modName)
{

	uintptr_t modBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procID);

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32  modEntry;
		//Before calling the Process32First function, set this member to sizeof(PROCESSENTRY32). If you do not initialize dwSize, Process32First fails.
		modEntry.dwSize = sizeof(modEntry);
		// Loop till we find our module
		if (Module32First(hSnap, &modEntry)) {
			do {
				if (!_wcsicmp(modEntry.szModule, modName))
				{
					modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
	CloseHandle(hSnap);
	return modBaseAddr;
}

// Emulates how cheatengine finding offsets works
// Keep dereferencing vec<offsets> until we get to our desired value
uintptr_t findVMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
{
	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i){
		if (offsets[i] != 0){ 
			ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
			addr += offsets[i];
		}
	}
	return addr;
}
