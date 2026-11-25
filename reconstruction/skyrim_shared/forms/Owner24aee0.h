// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0x3202d0 (skyrim_shared/forms/BGSListForm): source copied, names replaced by placeholders.
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Function24aee0, Owner24aee0: GUESS(low) STANDIN
// entries, GetCount, member, Owner24aee0::Revert, RevertBase, ClearList: GUESS(low) STANDIN
#pragma once
#include "BGSListForm.h"

class Owner24aee0
{
public:
    virtual std::uint32_t GetCount() const;
    virtual void Revert(BGSLoadFormBuffer* a_buf);
    void RevertBase(BGSLoadFormBuffer* a_buf);
    void ClearList();
    const TESForm* Function24aee0(std::uint32_t a_index) const;  // 08
    const TESForm** entries;       // 20
    std::uint8_t padding28[0x4];   // 28
    std::uint32_t member;          // 30
};

