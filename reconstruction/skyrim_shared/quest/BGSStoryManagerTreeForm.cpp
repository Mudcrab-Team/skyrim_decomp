// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x1c72c0 BGSStoryManagerTreeForm::~BGSStoryManagerTreeForm
#include "BGSStoryManagerTreeForm.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BGSStoryManagerTreeForm::BGSStoryManagerTreeForm()
{
}

BGSStoryManagerTreeForm* BGSStoryManagerTreeForm::GetChild(std::uint32_t) const
{
    return nullptr;
}

std::uint32_t BGSStoryManagerTreeForm::QChildCount() const
{
    return 0;
}

