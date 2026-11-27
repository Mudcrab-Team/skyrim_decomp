// Type declarations for the TESWorldSpace unit (build sse-steam-1-7-104).
//
// Exposure detail: (binary-analysis of the pinned image, community-headers).
// Source exposure: mixed
// Names follow CharmedBaryon/CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT)
// and powerof3/CommonLibSSE 654e55f7979c1733033d5dbef176e43827bac944 (GPL-3.0); no community
// code is copied. Every class other than TESWorldSpace is a minimal stand-in that declares only
// TESWorldSpace, IsFormTypeChild, GetFormEditorID, SetFormEditorID, FindInFileFast, ClearData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetMaxHeightAt: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); the fork declares it with a NiPoint3 argument and a float out-parameter.
// GetLocationFromPosition, GetCellByPosition: GUESS(medium); both names come from the task brief and appear in neither community header.
// editorID, encounterZone, location, locationMap, maxHeightData, portalGraph: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent, TESForm, TESFile, BGSEncounterZone, BGSLocation, TESObjectCELL, BSString, BSTHashMap, NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AddCompileIndex, GetFile, LookupByID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); RVAs 0x1e6d00, 0x1e5ae0, 0x1e5860.
// Seek, GetFormType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); RVAs 0x1cd860, 0x1cd7d0.
// GetOffsetData: GUESS(low); RVA 0x313020, the per-file offset record of a world space; a field at 0x18 is a file offset.
// IsRecordFileLoaded: GUESS(low); RVA 0x1ce3e0, a check on a plugin file before seeking in it.
// currentFormID: GUESS(low); TESFile member at 0x290, the id of the record the file is positioned at.
// CellAtCoordinates: GUESS(low); RVA 0x1b4b50, the cell of a world space at cell-grid coordinates.
// CellFillsHeight: GUESS(low); RVA 0x2c02b0, TESObjectCELL query that fills a land height for a position.
// HashFormKey: GUESS(low); RVA 0xce2570, writes the hash of a 32-bit key through its first argument.
// kRecordFormType: GUESS(low); global byte at RVA 0x20788b8, the record type a world space is stored under.
// kHeightBase: GUESS(low); global int at RVA 0x207bdc0, added to the packed max-height byte.
// gDefaultEncounterZone: GUESS(low); global at RVA 0x31a5728, compared against a resolved zone.
// IsFormTypeChildBase: GUESS(low); RVA 0x2c4c40, the form-type test the world space falls back to.
// kEmptyString: GUESS(low); global at RVA 0x1b58020, the empty text a BSString returns when it holds nothing.
// ProcessWorldSpaceBase: GUESS(low); RVA 0x30fa00, the world space part of ClearData that runs first.
// NiRefObject, BSPortalGraph, NiPointer, DecRefCount, DeleteThis: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the reference count at 0x08 and slot 1 are read.
// TLSData, taskFlag, GetStaticTLSData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the thread block at gs:[0x58] indexed by the TLS index at RVA 0x369a278.
// MemoryManager, Deallocate: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); RVA 0xcde6a0, the heap manager that frees the max-height block.
// ScopedTaskFlag: GUESS(low); a guard that sets the TLS task flag and restores it; the funclet destructor is RVA 0x147420.
// Set: GUESS(low); RVA 0x10d710, BSString assignment from text.
// gMemoryManager, gMemoryManagerState, InitMemoryManagerOnce, UnkOwned: GUESS(low); the global heap manager at RVA 0x369a810, its once-state word at 0x369ac98 and the init call at 0xcde810.
// FloatModulo: GUESS(low); RVA 0x15a988e, the C runtime fmodf import thunk, declared directly in the source file.
// FormFlagBits, AbsFloat, FloorToCell, MaxHeightData, cellData: GUESS(low); the maxHeightData block; layout from the compared code only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class TESFile;
class BGSLocation;

// kOneFloat, kCellSize, kHalfCellSize: GUESS(low); shared float constants of the image at RVAs 0x1b5be28, 0x18215d4 and 0x18215d8
// (1.0, 4096.0 and 2048.0); the height lookup reads them from memory rather than as literals.
extern const float kOneFloat;
extern const float kCellSize;
extern const float kHalfCellSize;

// Empty text of a BSString (global in the image).
extern const char kEmptyString[];

// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiPoint3 {
    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0xC, "layout");

// OffsetData: GUESS(low); what GetOffsetData returns: only the file offset at 0x18 is read.
struct OffsetData {
    std::uint8_t  unk00[0x18];  // 00
    std::uint32_t fileOffset;   // 18
};

// BSString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct BSString {
    const char* c_str() const
    {
        return data ? data : kEmptyString;
    }

    BSString& operator=(const char* a_str)
    {
        Set(a_str, 0);
        return *this;
    }

    void Set(const char* a_str, std::uint32_t a_extra);

    char*         data;      // 00
    std::uint16_t size;      // 08
    std::uint16_t capacity;  // 0A
    std::uint32_t pad0C;     // 0C
};
static_assert(sizeof(BSString) == 0x10, "layout");

// BSTHashMap: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a scatter table whose
// buckets chain through the entries array; the sentinel marks the end of a chain.
template <class K, class V>
struct BSTHashMap {
    struct Entry {
        K      key;    // 00
        V      value;  // 08
        Entry* next;   // 10
    };

    // Find: writes a_value only on a hit.
    bool Find(const K& a_key, std::uint32_t a_hash, V& a_value) const
    {
        if (!entries) {
            return false;
        }
        const Entry* entry = &entries[(capacity - 1) & a_hash];
        if (!entry->next) {
            return false;
        }
        do {
            if (entry->key == a_key) {
                a_value = entry->value;
                return true;
            }
            entry = entry->next;
        } while (entry != sentinel);
        return false;
    }

    std::uint64_t pad00;      // 00
    std::uint32_t pad08;      // 08
    std::uint32_t capacity;   // 0C
    std::uint32_t free;       // 10
    std::uint32_t good;       // 14
    Entry*        sentinel;   // 18
    std::uint64_t allocator;  // 20
    Entry*        entries;    // 28
};
static_assert(sizeof(BSTHashMap<std::uint32_t, void*>) == 0x30, "layout");

// TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the one query used here.
class TESObjectCELL {
public:
    bool CellFillsHeight(const NiPoint3& a_pos, float& a_height);
};

// BGSLocation: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only named.
class BGSLocation {
public:
    std::uint8_t unk00[0x28];
};

// TESFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESFile {
public:
    bool          Seek(std::uint32_t a_offset);
    std::uint32_t GetFormType();
    bool          IsRecordFileLoaded();

    std::uint8_t  unk000[0x290];  // 000
    std::uint32_t currentFormID;  // 290
};

// BaseFormComponent: STANDIN EXE_RTTI; class name and base from the image RTTI, 4 primary vftable slots
// sizeof BaseFormComponent 0x8: OBSERVED; size argument of operator delete in the deleting destructor (slot 0)
class BaseFormComponent {
public:
    virtual ~BaseFormComponent();  // 00
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
};
static_assert(sizeof(BaseFormComponent) == 0x8, "layout");

// FormFlagBits: GUESS(low); the form flag word with the one flag the compared code tests named.
struct FormFlagBits {
    std::uint32_t low : 3;          // 0 to 2
    std::uint32_t initialized : 1;  // 3
    std::uint32_t high : 28;        // 4 to 31
};
static_assert(sizeof(FormFlagBits) == 0x4, "layout");

// TESForm: STANDIN EXE_RTTI; class name and base from the image RTTI, 59 primary vftable slots
class TESForm : public BaseFormComponent {
public:
    ~TESForm() override;  // 00
    virtual void Unk_04();
    virtual void ClearData();  // 05
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual bool FindInFileFast(TESFile* a_mod);  // 0C
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
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
    virtual const char* GetFormEditorID() const;  // 32
    virtual bool SetFormEditorID(const char* a_str);  // 33
    virtual void Unk_34();
    virtual void Unk_35();
    virtual bool IsFormTypeChild(std::uint8_t a_type);  // 36
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();

    static void     AddCompileIndex(std::uint32_t& a_id, TESFile* a_file);
    TESFile*        GetFile(std::int32_t a_idx = -1) const;
    static TESForm* LookupByID(std::uint32_t a_formID);

    void*         sourceFiles;       // 08
    FormFlagBits  formFlags;         // 10
    std::uint32_t formID;            // 14
    std::uint16_t inGameFormFlags;   // 18
    std::uint8_t  formType;          // 1A
    std::uint8_t  pad1B[5];          // 1B
};
static_assert(sizeof(TESForm) == 0x20, "layout");

// BGSEncounterZone: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); location at 0x28.
class BGSEncounterZone : public TESForm {
public:
    std::uint8_t unk20[0x8];  // 20
    BGSLocation* location;    // 28
};

// NiRefObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiRefObject {
public:
    virtual ~NiRefObject();  // 00
    virtual void DeleteThis();  // 01

    void DecRefCount()
    {
        // reference counting: the count is shared between threads, so the release is atomic.
        if (_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)) == 0) {
            DeleteThis();
        }
    }

    std::uint32_t refCount;  // 08
    std::uint32_t pad0C;     // 0C
};

// BSPortalGraph: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only named.
class BSPortalGraph : public NiRefObject {
};

// NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
template <class T>
struct NiPointer {
    NiPointer& operator=(std::nullptr_t)
    {
        if (object) {
            T* old = object;
            object = nullptr;
            old->DecRefCount();
        }
        return *this;
    }

    T* object;  // 00
};

// UnkOwned: GUESS(low); an owned polymorphic object, released through its virtual destructor.
class UnkOwned {
public:
    virtual ~UnkOwned();
};

// MemoryManager: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class MemoryManager {
public:
    void Deallocate(void* a_mem, bool a_alignmentRequired);

    std::uint8_t unk000[0x480];  // 000
};
extern MemoryManager gMemoryManager;
extern std::uint32_t gMemoryManagerState;
void InitMemoryManagerOnce(MemoryManager* a_manager, std::uint32_t* a_state);

// TLSData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the task flag is declared.
struct TLSData {
    std::uint8_t  unk000[0x768];  // 000
    std::uint32_t taskFlag;       // 768
};

extern const std::uint32_t TlsIndex;

inline TLSData* GetStaticTLSData()
{
    // thread-local access: the engine keeps its per-thread block in a TLS slot, read through the TEB.
    TLSData* const* tlsDataArray = reinterpret_cast<TLSData* const*>(__readgsqword(0x58));
    return tlsDataArray[TlsIndex];
}

// ScopedTaskFlag: GUESS(low); sets the thread's task flag for a scope and restores the old value.
class ScopedTaskFlag {
public:
    explicit ScopedTaskFlag(std::uint32_t a_value)
    {
        TLSData* tls = GetStaticTLSData();
        saved = tls->taskFlag;
        tls->taskFlag = a_value;
    }

    ~ScopedTaskFlag()
    {
        GetStaticTLSData()->taskFlag = saved;
    }

    std::uint32_t saved;
};

// AbsFloat: GUESS(low); absolute value kept in float, as the position code does it.
inline float AbsFloat(float a_value)
{
    // sign-bit mask: avoids the double round trip the CRT fabsf takes.
    return _mm_cvtss_f32(_mm_and_ps(_mm_set_ss(a_value), _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF))));
}

// FloorToCell: GUESS(low); the cell-grid coordinate of a world position, 4096 units per cell.
inline std::int32_t FloorToCell(float a_pos, float a_step = 1.0f)
{
    float whole = static_cast<float>(static_cast<std::int32_t>(a_pos));
    return static_cast<std::int32_t>(a_pos - whole >= 0.0f ? whole : whole - a_step) >> 12;
}

// MaxHeightData: GUESS(low); the block maxHeightData points at: the cell rectangle it covers, then
// one packed word of four height bytes per cell.
struct MaxHeightData {
    std::int16_t  minX;      // 00
    std::int16_t  minY;      // 02
    std::int16_t  maxX;      // 04
    std::int16_t  maxY;      // 06
    std::uint32_t cellData[1];  // 08
};

// TESWorldSpace: EXE_RTTI; class name and base from the image RTTI, 59 primary vftable slots
// sizeof TESWorldSpace 0x358: OBSERVED; size argument of operator delete in the deleting destructor (slot 0)
// Other RTTI bases (not declared here; their vftable pointers lie inside the members): .?AVTESFullName@@, .?AVTESModel@@
class TESWorldSpace : public TESForm {
public:
    TESWorldSpace();
    ~TESWorldSpace() override;                           // 00
    void        ClearData() override;                    // 05
    bool        FindInFileFast(TESFile* a_mod) override;  // 0C
    const char* GetFormEditorID() const override;        // 32
    bool        SetFormEditorID(const char* a_str) override;  // 33
    bool        IsFormTypeChild(std::uint8_t a_type) override;  // 36

    TESObjectCELL* GetCellByPosition(const NiPoint3& a_pos) const;
    BGSLocation*   GetLocationFromPosition(const NiPoint3& a_pos) const;
    bool           GetMaxHeightAt(const NiPoint3& a_pos, float& a_height) const;

    // GetOffsetData, CellAtCoordinates, ProcessWorldSpaceBase: GUESS(low); RVAs 0x313020, 0x1b4b50, 0x30fa00.
    OffsetData*    GetOffsetData() const;
    TESObjectCELL* CellAtCoordinates(std::int32_t a_x, std::int32_t a_y) const;
    void           ProcessWorldSpaceBase();

    std::uint8_t                          unk20[0xE0];       // 20
    BSTHashMap<std::uint32_t, BGSLocation*> locationMap;     // 100
    NiPointer<BSPortalGraph>              portalGraph;       // 130
    UnkOwned*                             unk138;            // 138
    UnkOwned*                             unk140;            // 140
    std::uint8_t                          unk148[0xB8];      // 148
    BSString                              editorID;          // 200
    std::uint8_t                          unk210[0x10];      // 210
    BGSEncounterZone*                     encounterZone;     // 220
    BGSLocation*                          location;          // 228
    std::uint8_t                          unk230[0x120];     // 230
    MaxHeightData*                        maxHeightData;     // 350
};
static_assert(sizeof(TESWorldSpace) == 0x358, "layout");
