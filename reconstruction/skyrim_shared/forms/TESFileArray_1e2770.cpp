// Source exposure: mixed (the pinned image listing; sibling shape).
// Code origin: adapted from the cited sibling body
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESFileContainer.cpp:143
// 0x1e2770 TESFileArray::TESFileArray
#include "TESFileArray_1e2770.h"

TESFileArray::TESFileArray(TESFile* const* a_files, std::uint32_t a_size)
{
    pElements = nullptr;
    uiNumElements = a_size;
    AllocateElements();
    for (std::uint32_t i = 0; i < uiNumElements; ++i)
        pElements[i] = a_files[i];
}
