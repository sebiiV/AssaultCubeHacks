// AssaultCubeHack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

#include "proc.h"
#include "ammo.h"
#include "health.h"
#include "offsets.h"

int main()
{
	// get procid of target process
	DWORD procID = GetProcID(application);

	// getmodulebase address
	uintptr_t moduleBase = GetModuleBaseAddress(procID, application);

	// get handle to process
	HANDLE hProcess = 0;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procID);

	// resolve base address of pointer chain
	uintptr_t dynamicPtrBaseAddress = moduleBase + initialOffset;
	std::cout << "DynamicPtrBaseAddr = " << "0x" << std::hex << dynamicPtrBaseAddress << std::endl;

	// the hack loop
	while (!(GetAsyncKeyState(VK_DELETE)))
	{
		hackAmmo(hProcess, dynamicPtrBaseAddress);
		hackHealth(hProcess, dynamicPtrBaseAddress);
		Sleep(1);
	}

	return 0;
}
