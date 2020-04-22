#include <vector>
#include <windows.h>
#include <TlHelp32.h>
#include <iostream>

#include "proc.h"
#include "offsets.h"


int hackHealth(HANDLE hProcess, uintptr_t dynamicPtrBaseAddress);
