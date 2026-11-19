// Source exposure: mixed (pinned image listing and community declarations; a local decompile informed control flow and is not in the repo).
// Code origin: original reconstruction from the pinned listing and community declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-only (declarations adapted from powerof3/CommonLibSSE; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// The names CreateDuplicateForm and IsParentForm come from powerof3/CommonLibSSE 654e55f (GPL-3.0); that licence applies to those declarations.
// TESObjectCELL, GetbhkWorld, GetCoordinates, GetLocation, GetOwner: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EnterReferenceListLock, ExitReferenceListLock, GetEncounterZone: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); names from the Address Library function table, no declaration in the community headers.
// BaseFormComponent, TESForm, BGSEncounterZone, BGSLocation, bhkWorld, TESWorldSpace, LOADED_CELL_DATA, EXTERIOR_DATA, INTERIOR_DATA, ExtraDataList, BSSpinLock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class BGSLocation;
class BGSLoadFormBuffer;
class TESFile;
class bhkWorld;

// CellAmbientColors: GUESS(low)
// NiColor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct CellAmbientColors;
class NiColor;

// GetCurrentThreadId: OBSERVED; the lock reads the calling thread through the import at RVA 0x17c8440.
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

// BSSpinLock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); owningThread and lockCount at 0 and 4.
class BSSpinLock {
public:
    // Lock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the callee at RVA 0x1b4d80 takes the number of spin pauses.
    void Lock(std::uint32_t a_pauses = 0);

    void Unlock()
    {
        // lock protocol: the fence orders the owner read after earlier loads.
        _mm_lfence();
        std::uint32_t threadID = GetCurrentThreadId();
        if (owningThread == threadID) {
            if (lockCount == 1) {
                owningThread = 0;
                // lock protocol: the cleared owner is published before the count is released.
                _mm_mfence();
                // the last holder releases the count atomically, as the engine lock does
                _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&lockCount), 0, 1);
            } else {
                // a nested holder drops one level of the recursive count atomically
                _InterlockedDecrement(reinterpret_cast<volatile long*>(&lockCount));
            }
        }
    }

    std::uint32_t owningThread;  // 00
    std::uint32_t lockCount;     // 04
};
static_assert(sizeof(BSSpinLock) == 0x8, "layout");

// BaseFormComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BaseFormComponent {
public:
    virtual ~BaseFormComponent();  // 00
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
};

// TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESForm : public BaseFormComponent {
public:
    virtual void Unk_04();
    virtual void ClearData();  // 05
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void RemoveChange(std::uint32_t a_changeFlags);  // 0B
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Revert(BGSLoadFormBuffer* a_buf);  // 12
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual bool SetFormEditorID(const char* a_str);  // 33
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();

    // AddCompileIndex, GetFile, LookupByID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); RVAs 0x1e6d00, 0x1e5ae0, 0x1e5860.
    static void      AddCompileIndex(std::uint32_t& a_id, TESFile* a_file);
    TESFile*         GetFile(std::int32_t a_idx = -1) const;
    static TESForm*  LookupByID(std::uint32_t a_formID);

    void*         sourceFiles;       // 08
    std::uint32_t formFlags;         // 10
    std::uint32_t formID;            // 14
    std::uint16_t inGameFormFlags;   // 18
    std::uint8_t  formType;          // 1A
    std::uint8_t  pad1B[5];          // 1B
};
static_assert(sizeof(TESForm) == 0x20, "layout");

// BGSLocation: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSLocation : public TESForm {
public:
    std::uint8_t unk20[0x20];  // 20
};

// BGSEncounterZone: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); zoneOwner and
// location are the first two members of its data, at 0x20 and 0x28 in this build.
class BGSEncounterZone : public TESForm {
public:
    TESForm*     zoneOwner;  // 20
    BGSLocation* location;   // 28
};

// ExtraDataList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the callees are
// bound to the RVAs the image encodes, each name below a guess unless noted.
class ExtraDataList {
public:
    // GetOwner: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); RVA 0x164570.
    TESForm* GetOwner();
    // GetEncounterZone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); RVA 0x16a0a0.
    BGSEncounterZone* GetEncounterZone() const;
    // GetExtraLocation: GUESS(low); RVA 0x16a1f0, the location extra of the list.
    BGSLocation* GetExtraLocation() const;
    // GetbhkWorld: GUESS(low); RVA 0x16f140, the physics world an interior cell keeps.
    bhkWorld* GetbhkWorld() const;

    std::uint8_t unk00[0x18];  // 00
};
static_assert(sizeof(ExtraDataList) == 0x18, "layout");

// EXTERIOR_DATA: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); XCLC data of an exterior cell.
// ~EXTERIOR_DATA: GUESS(low); the callee at RVA 0x2d38c0 destroys and frees the data; the image calls it
// with a delete flag, which a plain delete expression on this stand-in does not reproduce.
struct EXTERIOR_DATA {
    ~EXTERIOR_DATA();

    std::int32_t cellX;  // 00
    std::int32_t cellY;  // 04
    std::uint8_t unk08[0x18];  // 08
};

// INTERIOR_DATA, Inherit, kAmbientColor, ambient, directional, fogColorNear,
// fogNear, fogFar, directionalXY, directionalZ, directionalFade, clipDist, fogPower,
// directionalAmbientLightingColors, fogColorFar, fogClamp, lightFadeStart, lightFadeEnd,
// lightingTemplateInheritanceFlags, unk5C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PackedDirectionalLighting, colors: GUESS(low)
// BGSDirectionalAmbientLightingColors::fresnelPower: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct PackedDirectionalLighting {
    std::uint32_t colors[7];  // Six directional colors followed by the specular color.
    float fresnelPower;
};

struct INTERIOR_DATA {
    enum class Inherit : std::uint32_t {
        kAmbientColor = 1
    };

    std::uint32_t ambient;
    std::uint32_t directional;
    std::uint32_t fogColorNear;
    float fogNear;
    float fogFar;
    std::uint32_t directionalXY;
    std::uint32_t directionalZ;
    float directionalFade;
    float clipDist;
    float fogPower;
    PackedDirectionalLighting directionalAmbientLightingColors;
    std::uint32_t fogColorFar;
    float fogClamp;
    float lightFadeStart;
    float lightFadeEnd;
    Inherit lightingTemplateInheritanceFlags;
    std::uint32_t unk5C;
};
static_assert(sizeof(PackedDirectionalLighting) == 0x20, "Packed directional lighting size");
static_assert(sizeof(INTERIOR_DATA) == 0x60, "Interior data size");
static_assert(offsetof(INTERIOR_DATA, directionalAmbientLightingColors) == 0x28, "Directional lighting offset");
static_assert(offsetof(PackedDirectionalLighting, fresnelPower) == 0x1C, "Fresnel power offset");
static_assert(offsetof(INTERIOR_DATA, lightingTemplateInheritanceFlags) == 0x58, "Inheritance flags offset");

// gExteriorbhkWorld: GUESS(low); global at RVA 0x21a0598, a pointer to the physics world pointer
// that exterior cells answer with.
extern bhkWorld** gExteriorbhkWorld;

// gDefaultEncounterZone: GUESS(low); global at RVA 0x31a5728, compared against a cell's zone.
extern BGSEncounterZone* gDefaultEncounterZone;

// TESWorldSpace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESWorldSpace {
public:
    // GetLocation: GUESS(low); RVA 0x30e3b0, the location a world space maps to.
    BGSLocation* GetLocation();

    std::uint8_t      unk00[0x220];     // 00
    BGSEncounterZone* encounterZone;    // 220
};

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value. The image tests
// form flags as a load, a shift by the bit index and a test of the low bit, which this recipe keeps
// only when the shift count reaches the test through an inlined call; a mask test of the member
// folds to a test of memory.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

// ResolveFormRef: GUESS(medium); a form that is not initialised yet (form flag bit 3 clear) keeps
// the form id in the low half of a form pointer member; the id is resolved through the owner's
// file. Used for the zone and location links of a cell and of an encounter zone.
template <class T>
inline T* ResolveFormRef(const TESForm* a_owner, T* a_raw)
{
    if (!TestBit(a_owner->formFlags, 3)) {
        std::uint32_t id = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(a_raw));
        if (id != 0) {
            TESForm::AddCompileIndex(id, a_owner->GetFile(-1));
            return dynamic_cast<T*>(TESForm::LookupByID(id));
        }
    }
    return a_raw;
}

// LOADED_CELL_DATA: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct LOADED_CELL_DATA {
    std::uint8_t      unk00[0x160];    // 00
    BGSEncounterZone* encounterZone;   // 160
};

// TESObjectCELL: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); members at the offsets the
// compared functions read; the layout is the image's (59 virtual slots, size 0x148).
class TESObjectCELL : public TESForm {
public:
    // CellData, exterior, interior: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    union CellData {
        EXTERIOR_DATA* exterior;  // XCLC
        INTERIOR_DATA* interior;  // XCLL
    };

    // Function2bc790: GUESS(low)
    void Function2bc790(CellAmbientColors& a_colors, NiColor& a_specular, float& a_fresnelPower) const;

    void               EnterReferenceListLock();
    void               ExitReferenceListLock();
    bhkWorld*          GetbhkWorld() const;
    // GetCoordinates: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) GUESS(medium); NG declares
    // EXTERIOR_DATA* GetCoordinates(), but the function at RVA 0x2bc660 writes the cell's two
    // coordinates through two reference parameters, so the name is kept with that signature.
    void               GetCoordinates(std::int32_t& a_x, std::int32_t& a_y);
    BGSEncounterZone*  GetEncounterZone() const;
    BGSLocation*       GetLocation() const;
    TESForm*           GetOwner();
    // CreateDuplicateForm, IsParentForm: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); base virtuals in TESForm
    TESForm*           CreateDuplicateForm(bool a_createEditorID, void* a_arg2);
    bool               IsParentForm();
    // GetWorldSpaceOfExteriorCell: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); returns the cell's world space
    TESWorldSpace*     GetWorldSpaceOfExteriorCell();

    std::uint8_t       unk20[0x20];        // 20 - TESFullName base
    std::uint16_t      cellFlags;          // 40
    std::uint16_t      cellGameFlags;      // 42
    std::uint8_t       unk44[4];           // 44
    ExtraDataList      extraList;          // 48
    std::uint8_t       unk60[8];           // 60
    CellData           cellData;           // 68
    std::uint8_t       unk70[0xB0];        // 70
    BSSpinLock         spinLock;           // 120
    TESWorldSpace*     worldSpace;         // 128
    LOADED_CELL_DATA*  loadedData;         // 130
    void*              lightingTemplate;   // 138
    std::uint64_t      unk140;             // 140
};
static_assert(sizeof(TESObjectCELL) == 0x148, "layout");
