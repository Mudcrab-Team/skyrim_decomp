// Source exposure: mixed (the pinned image and community declarations).
// Code origin: the existing GetType leaf and original reconstruction of LoadFunctionData.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x38eed0 BGSEntryPointFunctionDataText::GetType
// 0x38e7b0 BGSEntryPointFunctionDataText::LoadFunctionData
#include "BGSEntryPointFunctionDataText.h"
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t BGSEntryPointFunctionDataText::GetType() const
{
    return 0x7;
}

// Provide the constructor for the class vtable and owned text.
BGSEntryPointFunctionDataText::BGSEntryPointFunctionDataText() {}

namespace
{
// FileMemoryContext: GUESS(low); select the memory context while reading a record.
class FileMemoryContext
{
public:
    FileMemoryContext() : previous(g_memoryContext_tls_0x768)
    {
        constexpr std::uint32_t kFileMemoryContext = 0x65;
        g_memoryContext_tls_0x768 = kFileMemoryContext;
    }

    ~FileMemoryContext() { g_memoryContext_tls_0x768 = previous; }

private:
    std::uint32_t previous;
};
}

// Load the text payload using the file's allocation context.
bool BGSEntryPointFunctionDataText::LoadFunctionData(TESFile* a_file)
{
    FileMemoryContext context;
    text.LoadFromFile(a_file);
    return true;
}
