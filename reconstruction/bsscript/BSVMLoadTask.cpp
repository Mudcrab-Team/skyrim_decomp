// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESForm.cpp:827 (BSVMLoadTask::GetDescription)
// BSVMLoadTask: GUESS(low)
// BSVMLoadTask::GetDescription: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
// 0x1e7cb0 BSVMLoadTask::GetDescription
#include "BSVMLoadTask.h"
extern "C" __declspec(dllimport) int strcpy_s(char*, unsigned long long, const char*);
bool BSVMLoadTask::GetDescription(char* description, unsigned int size) const { strcpy_s(description, size, "VMLoadTask"); return true; }
