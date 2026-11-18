// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x30b710 TESWorldSpace::GetFormEditorID
// 0x314930 TESWorldSpace::~TESWorldSpace
// 0x30e8d0 TESWorldSpace::GetCellByPosition
// 0x30d050 TESWorldSpace::FindInFileFast
#include "TESWorldSpace.h"

extern std::uint8_t kRecordFormType;

// The constructor is not compared: it is defined so that this unit emits the vftable and with
// it the deleting destructor, as the original unit did. Its body is a minimal stand-in.
TESWorldSpace::TESWorldSpace()
{
}

const char* TESWorldSpace::GetFormEditorID() const
{
    return editorID.c_str();
}

bool TESWorldSpace::IsParentForm()
{
    return true;
}

bool TESWorldSpace::FindInFileFast(TESFile* a_mod)
{
    OffsetData* offsetData = GetOffsetData();
    if (!a_mod || !a_mod->IsRecordFileLoaded() || !offsetData || offsetData->fileOffset == 0) {
        return false;
    }
    if (!a_mod->Seek(offsetData->fileOffset)) {
        return false;
    }
    return static_cast<std::uint32_t>(a_mod->GetFormType()) == kRecordFormType && a_mod->currentFormID == formID;
}

TESObjectCELL* TESWorldSpace::GetCellByPosition(const NiPoint3& a_pos) const
{
    const std::int32_t cellX = FloorToCell(a_pos.x);
    const std::int32_t cellY = FloorToCell(a_pos.y);
    if (cellX > 0x7FFF || cellY > 0x7FFF || cellX < -0x8000 || cellY < -0x8000) {
        return nullptr;
    }
    return CellAtCoordinates(cellX, cellY);
}
