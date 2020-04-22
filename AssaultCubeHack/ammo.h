#include <vector>
#include <windows.h>
#include <TlHelp32.h>
#include <iostream>

#include "proc.h"
#include "offsets.h"

int hackAmmo(HANDLE hProcess, uintptr_t dynamicPtrBaseAddress);
