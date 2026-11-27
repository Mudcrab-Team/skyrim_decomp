// Near miss: 0.0% | other
// TESWorldSpace member functions, build sse-steam-1-7-104.
//
// RVA 0x30b710, 22 bytes (GetFormEditorID);
// RVA 0x314930, 52 bytes (~TESWorldSpace, the deleting destructor);
// RVA 0x30e8d0, 129 bytes (GetCellByPosition); RVA 0x30d050, 136 bytes (FindInFileFast).
// Source exposure: mixed
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x312ed0 TESWorldSpace::IsFormTypeChild

#include "include/312ed0/TESWorldSpace.h"

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

bool IsFormTypeChildBase(std::uint8_t a_type);

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

// lab variants
bool LabA(std::uint8_t a_type)
{
    if (a_type == 0x3C) {
        return true;
    }
    if (a_type == 0x4A) {
        return true;
    }
    return IsFormTypeChildBase(a_type);
}
bool LabB(std::uint8_t a_type)
{
    if (a_type == 0x3C) {
        return true;
    } else if (a_type == 0x4A) {
        return true;
    } else {
        return IsFormTypeChildBase(a_type);
    }
}
bool LabC(std::uint8_t a_type)
{
    if (a_type != 0x3C) {
        if (a_type != 0x4A) {
            return IsFormTypeChildBase(a_type);
        }
    }
    return true;
}
bool LabD(std::uint8_t a_type)
{
    switch (a_type) {
    case 0x3C:
        return true;
    case 0x4A:
        return true;
    }
    return IsFormTypeChildBase(a_type);
}
bool LabE(std::uint8_t a_type)
{
    return a_type == 0x3C || a_type == 0x4A || IsFormTypeChildBase(a_type);
}
inline bool LabIsWorldChild(std::uint8_t a_type) { return a_type == 0x4A; }
bool LabF(std::uint8_t a_type)
{
    if (a_type == 0x3C) {
        return true;
    }
    return LabIsWorldChild(a_type) || IsFormTypeChildBase(a_type);
}
bool LabG(std::uint8_t a_type)
{
    if (a_type == 0x3C) {
        return true;
    }
    if (a_type == 0x4A) {
        return true;
    } else {
        return IsFormTypeChildBase(a_type);
    }
}
bool LabH(std::uint32_t a_type)
{
    if (a_type == 0x3C || a_type == 0x4A) {
        return true;
    }
    return IsFormTypeChildBase(static_cast<std::uint8_t>(a_type));
}
bool LabI(std::uint8_t a_type)
{
    bool result = true;
    if (a_type != 0x3C) {
        if (a_type == 0x4A) {
            return result;
        }
        result = IsFormTypeChildBase(a_type);
    }
    return result;
}
bool LabJ(std::uint8_t a_type)
{
    if (a_type == 0x3C) {
        return true;
    }
    switch (a_type) {
    case 0x4A:
        return true;
    default:
        return IsFormTypeChildBase(a_type);
    }
}

// EH lab variants
void LabExtRelease(void* a_p);
void LabExtThrowing(int a_v);
void LabExtNoexcept(int a_v) noexcept;
extern int gLabValue;
struct LabGuardExt
{
    explicit LabGuardExt(void* a_p) : p(a_p) {}
    ~LabGuardExt() { LabExtRelease(p); }
    void* p;
};
struct LabGuardInl
{
    explicit LabGuardInl(int a_v) : saved(gLabValue) { gLabValue = a_v; }
    ~LabGuardInl() { gLabValue = saved; }
    int saved;
};
inline void LabTouch(int a_v) { gLabValue += a_v; }
__forceinline void LabTouchF(int a_v) { gLabValue += a_v; }
inline bool LabNever() { return false; }
inline int LabZero() { return 0; }
inline void LabMaybe(int a_v) { if (LabNever()) { LabExtThrowing(a_v); } }
void LabE1(int a_v) { LabGuardExt g(&gLabValue); LabTouch(a_v); LabExtNoexcept(a_v); }
void LabE2(int a_v) { LabGuardExt g(&gLabValue); LabTouchF(a_v); LabExtNoexcept(a_v); }
void LabE3(int a_v) { LabGuardInl g(a_v); LabExtNoexcept(a_v); }
void LabE4(int a_v) { LabGuardInl g(a_v); if (LabNever()) { LabExtThrowing(a_v); } LabExtNoexcept(a_v); }
void LabE5(int a_v) { LabGuardExt g(&gLabValue); if (LabNever()) { LabExtThrowing(a_v); } LabExtNoexcept(a_v); }
void LabE6(int a_v) { LabGuardExt g(&gLabValue); LabMaybe(a_v); LabExtNoexcept(a_v); }
void LabE7(int a_v) { LabGuardExt g(&gLabValue); for (int i = 0; i < LabZero(); ++i) { LabExtThrowing(i); } LabExtNoexcept(a_v); }
void LabE8(int a_v) { LabExtNoexcept(a_v); { LabGuardExt g(&gLabValue); LabMaybe(a_v); } LabExtNoexcept(a_v); }
void LabE9(int a_v) { LabGuardInl g(a_v); LabMaybe(a_v); LabExtNoexcept(a_v); }
void LabE10(int a_v) { const int n = LabZero(); LabGuardExt g(&gLabValue); if (n) { LabExtThrowing(a_v); } LabExtNoexcept(a_v); }
void LabE11(int a_v) { LabGuardExt g(&gLabValue); LabExtThrowing(a_v); }
void LabE12(int a_v) noexcept { LabGuardExt g(&gLabValue); LabExtThrowing(a_v); }
void LabE13(int a_v) throw() { LabGuardExt g(&gLabValue); LabExtThrowing(a_v); }
__declspec(nothrow) void LabE14(int a_v) { LabGuardExt g(&gLabValue); LabExtThrowing(a_v); }
void LabE15(int a_v) noexcept { LabGuardExt g(&gLabValue); LabExtNoexcept(a_v); }
void LabE16(int a_v) throw() { LabGuardExt g(&gLabValue); LabMaybe(a_v); LabExtNoexcept(a_v); }
inline void LabInner(int a_v) noexcept { LabGuardExt g(&gLabValue); LabExtThrowing(a_v); }
void LabE17(int a_v) { LabInner(a_v); LabExtThrowing(a_v); }
inline void LabInner2(int a_v) throw() { LabGuardExt g(&gLabValue); LabExtThrowing(a_v); }
void LabE18(int a_v) { LabInner2(a_v); LabExtThrowing(a_v); }
void LabE19(int a_v) { LabInner2(a_v); }
