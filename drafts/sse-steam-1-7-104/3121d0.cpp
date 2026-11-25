// Near miss: 10.0 alignment distance | other
// TESWorldSpace member functions, build sse-steam-1-7-104.
//
// RVA 0x312ed0, 21 bytes (IsFormTypeChild); RVA 0x30b710, 22 bytes (GetFormEditorID);
// RVA 0x314930, 52 bytes (~TESWorldSpace, the deleting destructor);
// RVA 0x30e8d0, 129 bytes (GetCellByPosition); RVA 0x30d050, 136 bytes (FindInFileFast);
// Source exposure: mixed
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x3121d0 TESWorldSpace::GetMaxHeightAt

#include "include/3121d0/TESWorldSpace.h"

extern std::uint8_t kRecordFormType;
extern std::int32_t kHeightBase;
extern BGSEncounterZone* gDefaultEncounterZone;
bool IsFormTypeChildBase(std::uint8_t a_type);
float FloatModulo(float a_value, float a_divisor);
std::uint32_t* HashFormKey(std::uint32_t* a_out, std::uint32_t a_key);

// The constructor is not compared: it is defined so that this unit emits the vftable and with
// it the deleting destructor, as the original unit did. Its body is a minimal stand-in.
TESWorldSpace::TESWorldSpace()
{
}

bool TESWorldSpace::IsFormTypeChild(std::uint8_t a_type)
{
    if (a_type == 0x3C) {
        return true;
    }
    if (a_type == 0x4A) {
        return true;
    }
    return IsFormTypeChildBase(a_type);
}

const char* TESWorldSpace::GetFormEditorID() const
{
    return editorID.c_str();
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
    return a_mod->GetFormType() == kRecordFormType && a_mod->currentFormID == formID;
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

BGSLocation* TESWorldSpace::GetLocationFromPosition(const NiPoint3& a_pos) const
{
    const std::uint32_t cellX = FloorToCell(a_pos.x);
    const std::uint32_t cellY = FloorToCell(a_pos.y);
    const std::uint32_t key = (cellX << 16) | (cellY & 0xFFFF);
    std::uint32_t scratch;
    HashFormKey(&scratch, key);
    BGSLocation* found;
    if (locationMap.Find(key, scratch, found) && found) {
        return found;
    }

    BGSLocation* result = location;
    BGSEncounterZone* zone = encounterZone;
    if (!result && zone) {
        // The pointer holds a form id until the record flag says it was resolved.
        if (!formFlags.initialized) {
            scratch = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(zone));
            TESForm::AddCompileIndex(scratch, GetFile(-1));
            zone = static_cast<BGSEncounterZone*>(TESForm::LookupByID(scratch));
        }
        if (zone && zone != gDefaultEncounterZone) {
            result = zone->location;
        }
    }
    return result;
}

bool TESWorldSpace::GetMaxHeightAt(const NiPoint3& a_pos, float& a_height) const
{
    const std::int32_t cellX = FloorToCell(a_pos.x);
    const std::int32_t cellY = FloorToCell(a_pos.y);
    TESObjectCELL* cell = CellAtCoordinates(cellX, cellY);
    if (cell && cell->CellFillsHeight(a_pos, a_height)) {
        return true;
    }

    const MaxHeightData* data = maxHeightData;
    const std::uint32_t* cells = data ? data->cellData : nullptr;
    if (!data || !cells) {
        return false;
    }
    if (cellX >= data->minX && cellX <= data->maxX && cellY >= data->minY && cellY <= data->maxY) {
        const std::int32_t index = (data->maxY - data->minY + 1) * (cellX - data->minX) - data->minY + cellY;
        const std::uint32_t packed = cells[index];
        const std::uint8_t* heights = reinterpret_cast<const std::uint8_t*>(&packed);
        const float scale = 1.0f / kHalfCellSize;
        const float posX = a_pos.x;
        std::int32_t quadX = static_cast<std::int32_t>(FloatModulo(AbsFloat(posX), 4096.0f) * scale);
        const float posY = a_pos.y;
        std::int32_t quadY = static_cast<std::int32_t>(FloatModulo(AbsFloat(posY), 4096.0f) * scale);
        if (posY < 0.0f) {
            quadY = 1 - quadY;
        }
        if (posX < 0.0f) {
            quadX = 1 - quadX;
        }
        a_height = static_cast<float>(heights[quadX + quadY * 2] * 0x100 + kHeightBase);
    }
    return true;
}
