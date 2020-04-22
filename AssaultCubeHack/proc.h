#include <vector>
#include <windows.h>
#include <TlHelp32.h>


DWORD GetProcID(const wchar_t* procName);

uintptr_t GetModuleBaseAddress(DWORD procID, const wchar_t* modName);

/*
I'm using uintptr as its architecture independant
Just make sure to compile same architecture as the game
*/
uintptr_t findVMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);

