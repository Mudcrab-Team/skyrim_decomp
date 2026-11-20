// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BGSListForm: EXE_RTTI
// GetCount: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x320390 BGSListForm::GetCount
#include "BGSListForm.h"
// GetCount: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t BGSListForm::GetCount() const
{
    return member;
}

void BGSListForm::Revert(BGSLoadFormBuffer* a_buf)
{
    RevertBase(a_buf);
    if (a_buf->value44 < 0) {
        ClearList();
    }
}
