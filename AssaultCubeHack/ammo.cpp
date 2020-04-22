#include "ammo.h"

int hackAmmo(HANDLE hProcess, uintptr_t dynamicPtrBaseAddress) {

	//resolve ammo pointer chain
	std::vector<unsigned int> ammoOffsets = { ac_client_ammoOffsets };
	uintptr_t ammoAddr = findVMAAddy(hProcess, dynamicPtrBaseAddress, ammoOffsets);

	// read ammo value
	int ammoValue = 0;
	ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammoValue, sizeof(ammoValue), nullptr);

	// write ammo value
	int newAmmo = 1337;
	WriteProcessMemory(hProcess, (BYTE*)ammoAddr, &newAmmo, sizeof(newAmmo), nullptr);

	#ifdef DEBUG
	std::cout << "ammoAddr = " << "0x" << std::hex << ammoAddr << std::endl;
	std::cout << "ammoValue = " << std::dec << ammoValue << std::endl;
	#endif

	return 0;
}

