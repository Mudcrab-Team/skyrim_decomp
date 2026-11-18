// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// TESValueForm::CopyComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESValueForm.cpp:30
// 0x1f34e0 TESValueForm::CopyComponent
#include "TESValueForm.h"
void TESValueForm::CopyComponent(BaseFormComponent* other) { TESValueForm* copy=dynamic_cast<TESValueForm*>(other); if(copy) { value=copy->value; TESForm* form=dynamic_cast<TESForm*>(this); if(form) form->AddChange(2); } }
