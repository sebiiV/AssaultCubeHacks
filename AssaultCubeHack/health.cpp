#include "health.h"

int hackHealth(HANDLE hProcess, uintptr_t dynamicPtrBaseAddress) {
	//resolve health pointer chain
	std::vector<unsigned int> healthOffsets = { ac_client_healthOffsets };
	uintptr_t healthAddr = findVMAAddy(hProcess, dynamicPtrBaseAddress, healthOffsets);

	// read ammo value
	int healthValue = 0;
	ReadProcessMemory(hProcess, (BYTE*)healthAddr, &healthValue, sizeof(healthValue), nullptr);

	// write ammo value
	int newAmmo = 1337;
	WriteProcessMemory(hProcess, (BYTE*)healthAddr, &newAmmo, sizeof(newAmmo), nullptr);

	#ifdef DEBUG
	std::cout << "healthAddr = " << "0x" << std::hex << healthAddr << std::endl;
	std::cout << "healthValue = " << std::dec << healthValue << std::endl;
	#endif

	return 0;
};
