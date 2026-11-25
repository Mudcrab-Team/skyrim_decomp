// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from binary analysis; names from CommonLibSSE-NG (MIT) and powerof3/CommonLibSSE (GPL-3.0); no external implementation body is copied
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// The names CreateDuplicateForm and IsParentForm come from powerof3/CommonLibSSE 654e55f, which is GPL-3.0; that licence applies to those declarations.
// Adapted bodies: none declared; tools/check_origin.py reports none above its threshold (0.75)
// at CommonLibSSE-NG b93280e, powerof3/CommonLibSSE 654e55f and momusdigital/fnv_decomp 91e1b6e8.
// TESObjectCELL, GetbhkWorld, GetCoordinates, GetLocation, GetOwner: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EnterReferenceListLock, ExitReferenceListLock, GetEncounterZone: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); names from the Address Library function table, no declaration in the community headers.
// BaseFormComponent, TESForm, BGSEncounterZone, BGSLocation, bhkWorld, TESWorldSpace, LOADED_CELL_DATA, EXTERIOR_DATA, INTERIOR_DATA, ExtraDataList, BSSpinLock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

// LODRecord: GUESS(low); record whose value member sits at 0x144.
struct LODRecord {
    std::uint8_t unk00[0x144];  // 00
    std::uint32_t value;        // 144
};

// LODNode: GUESS(low); virtual slot 5 yields the record.
class LODNode {
public:
    virtual void U00(); virtual void U01(); virtual void U02(); virtual void U03(); virtual void U04();
    virtual LODRecord* GetRecord();
};

// LODSource: GUESS(low); virtual slot 112 yields the node.
class LODSource {
public:
    virtual void U00(); virtual void U01(); virtual void U02(); virtual void U03(); virtual void U04(); virtual void U05(); virtual void U06(); virtual void U07();
    virtual void U08(); virtual void U09(); virtual void U0A(); virtual void U0B(); virtual void U0C(); virtual void U0D(); virtual void U0E(); virtual void U0F();
    virtual void U10(); virtual void U11(); virtual void U12(); virtual void U13(); virtual void U14(); virtual void U15(); virtual void U16(); virtual void U17();
    virtual void U18(); virtual void U19(); virtual void U1A(); virtual void U1B(); virtual void U1C(); virtual void U1D(); virtual void U1E(); virtual void U1F();
    virtual void U20(); virtual void U21(); virtual void U22(); virtual void U23(); virtual void U24(); virtual void U25(); virtual void U26(); virtual void U27();
    virtual void U28(); virtual void U29(); virtual void U2A(); virtual void U2B(); virtual void U2C(); virtual void U2D(); virtual void U2E(); virtual void U2F();
    virtual void U30(); virtual void U31(); virtual void U32(); virtual void U33(); virtual void U34(); virtual void U35(); virtual void U36(); virtual void U37();
    virtual void U38(); virtual void U39(); virtual void U3A(); virtual void U3B(); virtual void U3C(); virtual void U3D(); virtual void U3E(); virtual void U3F();
    virtual void U40(); virtual void U41(); virtual void U42(); virtual void U43(); virtual void U44(); virtual void U45(); virtual void U46(); virtual void U47();
    virtual void U48(); virtual void U49(); virtual void U4A(); virtual void U4B(); virtual void U4C(); virtual void U4D(); virtual void U4E(); virtual void U4F();
    virtual void U50(); virtual void U51(); virtual void U52(); virtual void U53(); virtual void U54(); virtual void U55(); virtual void U56(); virtual void U57();
    virtual void U58(); virtual void U59(); virtual void U5A(); virtual void U5B(); virtual void U5C(); virtual void U5D(); virtual void U5E(); virtual void U5F();
    virtual void U60(); virtual void U61(); virtual void U62(); virtual void U63(); virtual void U64(); virtual void U65(); virtual void U66(); virtual void U67();
    virtual void U68(); virtual void U69(); virtual void U6A(); virtual void U6B(); virtual void U6C(); virtual void U6D(); virtual void U6E(); virtual void U6F();
    virtual LODNode* GetLODNode();
};

// gCellLODThreshold: GUESS(low); global at RVA 0x3275610.
extern std::uint32_t gCellLODThreshold;

class BGSLocation;
class BGSLoadFormBuffer;
class TESFile;
class bhkWorld;

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
    virtual void Unk_0A(std::uint32_t a_arg);
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

// INTERIOR_DATA: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); XCLL data of an interior cell.
struct INTERIOR_DATA {
    std::uint8_t unk00[0x60];  // 00
};

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
    std::uint8_t      unk168[0x10];    // 168
    std::uint32_t     lodValue;        // 178
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
    // Function2bb150, Function2bf550, Function2c5c70, Function2bf600, Function224a90, Function2bf580, Function2bf5c0: GUESS(low); placeholder names
    void               Function2bb150(bool a_set);
    bool               Function2bf600() const;
    void               Function2bf550(bool a_set);
    void               Function2c5c70(bool a_set);
    static bool        Function224a90(TESForm* a_form, TESForm*& a_outA, TESForm*& a_outB);
    void               Function2bf580(bool a_set);
    void               Function2bf5c0(bool a_set);

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
    int  Function2c1210();
    bool QCanHideLOD() const;
    void Function2c5ca0(LODSource* a_src);
};
static_assert(sizeof(TESObjectCELL) == 0x148, "layout");
