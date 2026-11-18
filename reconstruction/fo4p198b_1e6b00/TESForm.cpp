// Source exposure: mixed
// Origin: authorized sibling and community declarations
// GPL-3.0: declarations adapted from powerof3/CommonLibSSE at 654e55f7979c1733033d5dbef176e43827bac944, include/RE/F/FORM.h, FORM_ENUM_STRING.h and include/RE/T/TESForm.h.
// TESForm::CreateGroupData: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESForm.cpp:960
// TESForm, FORM, FORM_GROUP: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0); declarations adapted
// names: GUESS(low); signatures and table interpretation remain provisional
// 0x1e6b00 TESForm::CreateGroupData
#include "TESForm.h"
void TESForm::CreateGroupData(FORM* out, FORM_GROUP* parent) {
    if (out && !parent) {
        out->form = formEnumString[2].formCode;
        out->formID = 0;
        out->flags = formEnumString[formType].formCode;
        out->length = 0;
        out->versionControl = 0;
        out->formVersion = 0;
        out->vcVersion = 0;
    }
}
