// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local listings of the pinned image
// with types from the header beside this file.
// Code origin: original reconstruction from binary analysis; names from CommonLibSSE-NG (MIT) and powerof3/CommonLibSSE (GPL-3.0); no external implementation body is copied The names CreateDuplicateForm and IsParentForm come from powerof3/CommonLibSSE 654e55f, which is GPL-3.0; that licence applies to those functions; Function2c1210, QCanHideLOD, Function2c5ca0: original reconstruction from binary analysis; names from CommonLibSSE-NG (MIT) and powerof3/CommonLibSSE (GPL-3.0); no external implementation body is copied; Written for this reconstruction from the listing; names from the header
// The names CreateDuplicateForm and IsParentForm come from powerof3/CommonLibSSE 654e55f, which is GPL-3.0; that licence applies to those functions.
// 0x2cbed0 TESObjectCELL::EnterReferenceListLock
// 0x2be9b0 TESObjectCELL::GetbhkWorld
// 0x2bc660 TESObjectCELL::GetCoordinates
// 0x2cbef0 TESObjectCELL::ExitReferenceListLock
// 0x2be700 TESObjectCELL::GetEncounterZone
// 0x2be530 TESObjectCELL::GetOwner
// 0x2bb180 TESObjectCELL::GetLocation
// 0x2bb150 TESObjectCELL::Function2bb150
// 0x2bf600 TESObjectCELL::Function2bf600
// 0x2bf550 TESObjectCELL::Function2bf550
// 0x2c5c70 TESObjectCELL::Function2c5c70
// 0x224a90 TESObjectCELL::Function224a90
// 0x2bf580 TESObjectCELL::Function2bf580
// 0x2bf5c0 TESObjectCELL::Function2bf5c0
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x2c5ca0 TESObjectCELL::Function2c5ca0
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
// 0x2c5ce0 TESObjectCELL::QCanHideLOD
#include "TESObjectCELL.h"

void TESObjectCELL::EnterReferenceListLock()
{
    spinLock.Lock();
}

bhkWorld* TESObjectCELL::GetbhkWorld() const
{
    if (cellFlags & 1) {
        return extraList.GetbhkWorld();
    }
    return *gExteriorbhkWorld;
}

void TESObjectCELL::GetCoordinates(std::int32_t& a_x, std::int32_t& a_y)
{
    EXTERIOR_DATA* exterior = (cellFlags & 1) ? nullptr : cellData.exterior;
    if (exterior) {
        a_x = exterior->cellX;
        a_y = exterior->cellY;
        return;
    }
    a_x = 0;
    a_y = 0;
}

void TESObjectCELL::ExitReferenceListLock()
{
    spinLock.Unlock();
}

BGSEncounterZone* TESObjectCELL::GetEncounterZone() const
{
    if (loadedData) {
        return loadedData->encounterZone;
    }
    BGSEncounterZone* zone = extraList.GetEncounterZone();
    if (!zone && !(cellFlags & 1) && worldSpace) {
        zone = worldSpace->encounterZone;
    }
    return zone;
}

TESForm* TESObjectCELL::GetOwner()
{
    TESForm* owner = extraList.GetOwner();
    if (!owner) {
        BGSEncounterZone* zone = GetEncounterZone();
        if (zone && zone != gDefaultEncounterZone) {
            owner = zone->zoneOwner;
        }
    }
    return owner;
}

BGSLocation* TESObjectCELL::GetLocation() const
{
    BGSEncounterZone* zone = GetEncounterZone();
    zone = ResolveFormRef(this, zone);
    if (zone && zone != gDefaultEncounterZone) {
        BGSLocation* location = ResolveFormRef(zone, zone->location);
        if (location) {
            return location;
        }
    }
    BGSLocation* location = extraList.GetExtraLocation();
    if (!location && !(cellFlags & 1) && worldSpace) {
        return worldSpace->GetLocation();
    }
    return location;
}

// CreateDuplicateForm: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
TESForm* TESObjectCELL::CreateDuplicateForm(bool a_createEditorID, void* a_arg2)
{
    return nullptr;
}

// IsParentForm: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
bool TESObjectCELL::IsParentForm()
{
    return true;
}

// GetWorldSpaceOfExteriorCell: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
TESWorldSpace* TESObjectCELL::GetWorldSpaceOfExteriorCell()
{
    if (cellFlags & 1) {
        return nullptr;
    }
    return worldSpace;
}

void TESObjectCELL::Function2bb150(bool a_set)
{
    if (a_set) {
        formFlags |= 0x400;
    } else {
        formFlags &= ~0x400;
    }
}

bool TESObjectCELL::Function2bf600() const
{
    std::uint16_t flags = cellFlags;
    if (TestBit(flags, 5)) {
        return true;
    }

    if (TestBit(flags, 6)) {
        return true;
    }

    return false;
}

void TESObjectCELL::Function2bf550(bool a_set)
{
    if (a_set) {
        cellFlags |= 1;
    } else {
        cellFlags &= ~1;
    }
}

void TESObjectCELL::Function2c5c70(bool a_set)
{
    if (a_set) {
        cellFlags |= 0x10;
    } else {
        cellFlags &= ~0x10;
    }
}

bool TESObjectCELL::Function224a90(TESForm* a_form, TESForm*& a_outA, TESForm*& a_outB)
{
    a_outA = nullptr;
    a_outB = nullptr;
    if (a_form) {
        if (a_form->formType == 0x47) {
            a_outB = a_form;
            return true;
        }

        if (a_form->formType == 0x3c) {
            a_outA = a_form;
            return true;
        }
    }

    return false;
}

void TESObjectCELL::Function2bf580(bool a_set)
{
    if (a_set) {
        cellFlags |= 0x20;
    } else {
        cellFlags &= ~0x20;
    }

    return Unk_0A(2);
}

void TESObjectCELL::Function2bf5c0(bool a_set)
{
    if (a_set) {
        cellFlags |= 0x40;
    } else {
        cellFlags &= ~0x40;
    }

    return Unk_0A(2);
}



void TESObjectCELL::Function2c5ca0(LODSource* a_src)
{
    LODRecord* rec = a_src->GetLODNode()->GetRecord();
    if (rec) {
        rec->value = 0;
    }
}


bool TESObjectCELL::QCanHideLOD() const
{
    const LOADED_CELL_DATA* data = loadedData;
    if (data) {
        return gCellLODThreshold > data->lodValue;
    }
    return false;
}
