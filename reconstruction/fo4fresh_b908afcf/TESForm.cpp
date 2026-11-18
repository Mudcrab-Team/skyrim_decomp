// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESForm.cpp:766 (TESForm::RemoveChange)
// TESForm, RemoveChange: GUESS(low)
// 0x1e56b0 TESForm::RemoveChange
#include "TESForm.h"
void TESForm::RemoveChange(int flags) { if (saveLoad) saveLoad->RemoveChange(this, flags); }
