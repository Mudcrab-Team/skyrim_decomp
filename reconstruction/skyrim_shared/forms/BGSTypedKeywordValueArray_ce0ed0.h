// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSKeyword.h:18
// BGSTypedKeywordValueArray, BGSTypedKeywordValueArray::Clear, BGSTypedKeywordValueArray::pArray, BGSTypedKeywordValueArray::uiSize, BGSTypedKeywordValue: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to what the body uses
// MemMgrGuard_369ac98, MemMgrInst_369a810, MemMgrEnsure_cde810, MemMgrDeallocate_cde6a0: GUESS(low); the memory manager singleton guard, instance, init and deallocate callees, named by address
// value: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
}

void MemMgrEnsure_cde810(void* self, std::uint32_t* state);
void MemMgrDeallocate_cde6a0(void* self, void* ptr, bool aligned);

template <unsigned N>
struct BGSTypedKeywordValue
{
    std::uint32_t value;
};

template <unsigned N>
class BGSTypedKeywordValueArray
{
public:
    void Clear();

    BGSTypedKeywordValue<N>* pArray;  // 00
    std::uint32_t            uiSize;  // 08
};
