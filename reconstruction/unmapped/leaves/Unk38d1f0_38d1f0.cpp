// Source exposure: mixed (community headers; the pinned image listing; sibling decompilation shape).
// Code origin: adapted from the sibling decompilation; adapted bodies: Unk38d1f0::ApplyFunction.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/bgsentrypointfunction.cpp:33
// 0x38d1f0 Unk38d1f0::ApplyFunction
#include "Unk38d1f0_38d1f0.h"

// Calls the handler registered for the entry point function, when there is one.
void Unk38d1f0::ApplyFunction(ENTRY_POINT_FUNCTION function, TESObjectREFR* reference,
                                          ENTRY_POINT_FUNCTION_TYPE type, unsigned char argumentCount, void** arguments,
                                          void* data)
{
    if (ms_kEntryPointFunctionTable[function].pFunction)
    {
        ms_kEntryPointFunctionTable[function].pFunction(reference, type, argumentCount, arguments, data);
    }
}
