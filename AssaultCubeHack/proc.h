#include <vector>
#include <windows.h>
#include <TlHelp32.h>
#include "ntapi.h"

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

DWORD GetProcID(const wchar_t* procName);

uintptr_t GetModuleBaseAddress(DWORD procID, const wchar_t* modName);

/*
I'm using uintptr as its architecture independant
Just make sure to compile same architecture as the game
*/
uintptr_t findVMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);



/*
Sneakier way of getting a handle & Learning about undocumented window functions

Flow is:
getModuleBaseAddressInternalPEB
GetLDREntryInternal
GetPebInternal or GetPebExternal


*/
PEB GetPebExternal(HANDLE hProc);
LDR_DATA_TABLE_ENTRY* GetLDREntryExternal(const wchar_t* modName);
char* GetModuleBaseAddressExternalPEB(const wchar_t* modName);


PEB* GetPEBInternal(); 
LDR_DATA_TABLE_ENTRY* GetLDREntryInternal(const wchar_t* modName); 
char* GetModuleBaseAddressInternalPEB(const wchar_t* modName);
