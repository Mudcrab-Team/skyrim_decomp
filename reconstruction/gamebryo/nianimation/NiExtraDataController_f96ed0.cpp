// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// NiExtraDataController: EXE_RTTI
// GetCtlrID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0xf96ed0 NiExtraDataController::IsEqual
// NiExtraDataController::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
#include "NiExtraDataController_f96ed0.h"

// ExtraDataView: GUESS(low); file-local view of the extra data object; the padding virtuals put IsEqual on slot 0x1C.
class ExtraDataView
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual bool IsEqual(ExtraDataView* a_other);  // 1C
};

bool NiExtraDataController::IsEqual(NiExtraDataController* a_object)
{
    if (!BaseIsEqual(a_object)) {
        return false;
    }

    ExtraDataView* mine = static_cast<ExtraDataView*>(extraData);
    ExtraDataView* theirs = static_cast<ExtraDataView*>(a_object->extraData);
    if (mine) {
        if (!theirs || !mine->IsEqual(theirs)) {
            return false;
        }
    } else if (theirs) {
        return false;
    }
    if (a_object->member != member) {
        return false;
    }
    return true;
}
