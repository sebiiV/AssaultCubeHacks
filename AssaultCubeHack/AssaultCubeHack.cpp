// AssaultCubeHack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <windows.h>
#include "proc.h"
#include <string>


// Probably a better way for declare magic variables
#define application L"ac_client.exe"
#define initialOffset 0x10F4F4
#define ac_client_ammoOffsets 0x374,0x14,0x0
#define ac_client_healthOffsets 0xf8

int hackAmmo(HANDLE hProcess,uintptr_t dynamicPtrBaseAddress) {

	//resolve ammo pointer chain
	std::vector<unsigned int> ammoOffsets = { ac_client_ammoOffsets };
	uintptr_t ammoAddr = findVMAAddy(hProcess, dynamicPtrBaseAddress, ammoOffsets);

	std::cout << "ammoAddr = " << "0x" << std::hex << ammoAddr << std::endl;

	// read ammo value
	int ammoValue = 0;
	ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue), nullptr);
	std::cout << "ammoValue = " << std::dec << ammoValue << std::endl;

	// write ammo value
	int newAmmo = 1337;
	WriteProcessMemory(hProcess, (BYTE*)ammoAddr, &newAmmo, sizeof(newAmmo), nullptr);

	// check ammo values
	ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue), nullptr);
	if (ammoValue == 1337) {
		std::cout << "Ammo set to 1337" << std::endl;
	}
	return 0;
}

int hackHealth(HANDLE hProcess, uintptr_t dynamicPtrBaseAddress) {
	//resolve hleath pointer chain
	std::vector<unsigned int> healthOffsets = { ac_client_healthOffsets };
	uintptr_t healthAddr = findVMAAddy(hProcess, dynamicPtrBaseAddress, healthOffsets);

	std::cout << "healthAddr = " << "0x" << std::hex << healthAddr << std::endl;

	// read ammo value
	int healthValue = 0;
	ReadProcessMemory(hProcess, (BYTE*)healthAddr, &healthValue, sizeof(healthValue), nullptr);
	std::cout << "healthValue = " << std::dec << healthValue << std::endl;

	// write ammo value
	int newAmmo = 1337;
	WriteProcessMemory(hProcess, (BYTE*)healthAddr, &newAmmo, sizeof(newAmmo), nullptr);

	// check ammo values
	ReadProcessMemory(hProcess, (BYTE*)healthAddr, &healthValue, sizeof(healthValue), nullptr);
	if (healthValue == 1337) {
		std::cout << "health set to 1337" << std::endl;
	}
	return 0;
};

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


	// Mash keyboard here to become 1337
	hackAmmo(hProcess, dynamicPtrBaseAddress);
	hackHealth(hProcess, dynamicPtrBaseAddress);

	// requires a key to be hit before closing
	getchar(); 

	return 0;
}
