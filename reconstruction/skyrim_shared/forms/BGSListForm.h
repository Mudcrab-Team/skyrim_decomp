// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BGSListForm: EXE_RTTI
// GetCount: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstddef>
#include <cstdint>
// GetCount: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// BGSLoadFormBuffer: GUESS(low); stand-in for the load buffer, only the signed field at 0x44 that Revert reads
class BGSLoadFormBuffer
{
public:
    std::uint8_t unk00[0x44];  // 00
    std::int32_t value44;      // 44
};
static_assert(offsetof(BGSLoadFormBuffer, value44) == 0x44, "BGSLoadFormBuffer::value44 offset");

// BGSListForm::Revert: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); compared at RVA 0x320a10
// RevertBase, ClearList: GUESS(low); non-virtual callees at RVA 0x1e5850 and 0x3203a0, bound by hint
class BGSListForm
{
public:
    virtual std::uint32_t GetCount() const;
    virtual void Revert(BGSLoadFormBuffer* a_buf);  // compared: 0x320a10
    void RevertBase(BGSLoadFormBuffer* a_buf);
    void ClearList();

    std::uint8_t padding[0x28];
    std::uint32_t member;
};
