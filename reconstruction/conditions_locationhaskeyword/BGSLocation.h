// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: reduced copy of the declarations needed from reconstruction/forms/BGSLocation.h, source file SHA-256 ca6d12b9583c3b8c9c2a986de4daf467be7803e524e976275f872b5528e373f5, with the member layouts of the base classes and of BGSLocation restored from the community headers; only methods this unit does not call are left out.
// Names and member offsets follow CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// BaseFormComponent, BaseFormComponent::InitializeDataComponent, ::ClearDataComponent, ::CopyComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm, TESForm::sourceFiles, ::formFlags, ::formID, ::inGameFormFlags, ::formType, ::pad1B, ::pad1C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the TESForm slots 04 and up are not declared, this unit calls none
// TESFileContainer, TESFileContainer::array, TESFileArray, TESFileArray::data, ::size: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout read as in the shared TESForm header
// TESFile: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); opaque, only used by pointer
// TESFullName, TESFullName::GetFullNameLength, ::GetFullName, ::fullName: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString, BSFixedString::_data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); one pooled string pointer
// BGSKeywordForm, BGSKeywordForm::HasKeyword, ::GetDefaultKeyword, ::keywords, ::numKeywords, ::pad14: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSKeyword, BGSMusicType, TESFaction, Actor, BGSLocationRefType, QueuedPromoteLocationReferencesTask: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque, only used by pointer
// BSTArray::pad0C, BSTArray::pad14: GUESS(low); alignment padding after the 32-bit capacity and size
// BSTArray, BSTArray::data, ::capacity, ::size: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout (data, capacity, size) read from the shared quest header, NG wraps it in an allocator
// UnloadedRefData, UnloadedRefData::CellKey, SpecialRefData, UniqueNPCData, OverrideData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); OverrideData is opaque, only a pointer to it is a member
// BGSLocation, BGSLocation::KEYWORD_DATA, ::parentLoc, ::unreportedCrimeFaction, ::musicType, ::worldLocMarker, ::worldLocRadius, ::horseLocMarker, ::pad6C, ::specialRefs, ::uniqueNPCs, ::overrideData, ::promoteRefsTask, ::promotedRefs, ::loadedCount, ::fileOffset, ::keywordData, ::lastChecked, ::cleared, ::everCleared, ::padEE: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSLocation::promoteRefsTask: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares NiPointer, a raw pointer here
// BGSLocation::worldLocMarker, ::horseLocMarker: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares ObjectRefHandle, a 32-bit integer here
#pragma once

#include <cstdint>

class BGSKeyword;
class BGSMusicType;
class TESFaction;
class Actor;
class BGSLocationRefType;
class QueuedPromoteLocationReferencesTask;
class BGSLocation;
class TESFile;
class OverrideData;

class BaseFormComponent {
public:
    virtual ~BaseFormComponent();                          // 00
    virtual void InitializeDataComponent() = 0;            // 01
    virtual void ClearDataComponent() = 0;                 // 02
    virtual void CopyComponent(BaseFormComponent* a_rhs);  // 03
};

struct TESFileArray {
    TESFile**     data;  // 00
    std::uint32_t size;  // 08
};

class TESFileContainer {
public:
    TESFileArray* array;  // 00
};

class TESForm : public BaseFormComponent {
public:
    ~TESForm() override;                                    // 00
    void InitializeDataComponent() override;                // 01
    void ClearDataComponent() override;                     // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    // members
    TESFileContainer sourceFiles;      // 08
    std::uint32_t    formFlags;        // 10
    std::uint32_t    formID;           // 14
    std::uint16_t    inGameFormFlags;  // 18
    std::uint8_t     formType;         // 1A
    std::uint8_t     pad1B;            // 1B
    std::uint32_t    pad1C;            // 1C
};
static_assert(sizeof(TESForm) == 0x20, "layout");

class BSFixedString {
public:
    const char* _data;  // 00
};
static_assert(sizeof(BSFixedString) == 0x8, "layout");

class TESFullName : public BaseFormComponent {
public:
    ~TESFullName() override;                                // 00
    void InitializeDataComponent() override;                // 01
    void ClearDataComponent() override;                     // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    virtual std::uint32_t GetFullNameLength() const;        // 04
    virtual const char*   GetFullName() const;              // 05

    // members
    BSFixedString fullName;  // 08
};
static_assert(sizeof(TESFullName) == 0x10, "layout");

class BGSKeywordForm : public BaseFormComponent {
public:
    ~BGSKeywordForm() override;                                     // 00
    void InitializeDataComponent() override;                        // 01
    void ClearDataComponent() override;                             // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;          // 03
    virtual bool        HasKeyword(const BGSKeyword* a_keyword) const;  // 04
    virtual BGSKeyword* GetDefaultKeyword() const;                  // 05

    // members
    BGSKeyword**  keywords;     // 08
    std::uint32_t numKeywords;  // 10
    std::uint32_t pad14;        // 14
};
static_assert(sizeof(BGSKeywordForm) == 0x18, "layout");

template <class T>
class BSTArray {
public:
    T*            data;      // 00
    std::uint32_t capacity;  // 08
    std::uint32_t pad0C;     // 0C
    std::uint32_t size;      // 10
    std::uint32_t pad14;     // 14
};
static_assert(sizeof(BSTArray<void*>) == 0x18, "layout");

struct UnloadedRefData {
    union CellKey {
        std::uint32_t raw;
    };

    std::uint32_t refID;          // 0
    std::uint32_t parentSpaceID;  // 4
    CellKey       cellKey;        // 8
};
static_assert(sizeof(UnloadedRefData) == 0xC, "layout");

struct SpecialRefData {
    BGSLocationRefType* type;     // 00
    UnloadedRefData     refData;  // 08
    std::uint32_t       pad14;    // 14
};
static_assert(sizeof(SpecialRefData) == 0x18, "layout");

struct UniqueNPCData {
    Actor*        actor;      // 00
    std::uint32_t refID;      // 08
    std::uint32_t pad0C;      // 0C
    BGSLocation*  editorLoc;  // 10
};
static_assert(sizeof(UniqueNPCData) == 0x18, "layout");

class BGSLocation :
    public TESForm,        // 00
    public TESFullName,    // 20
    public BGSKeywordForm  // 30
{
public:
    struct KEYWORD_DATA {
        BGSKeyword*   keyword;  // 00
        float         data;     // 08
        std::uint32_t pad0C;    // 0C
    };
    static_assert(sizeof(KEYWORD_DATA) == 0x10, "layout");

    // members
    BGSLocation*                          parentLoc;               // 48
    TESFaction*                           unreportedCrimeFaction;  // 50
    BGSMusicType*                         musicType;               // 58
    std::uint32_t                         worldLocMarker;          // 60
    float                                 worldLocRadius;          // 64
    std::uint32_t                         horseLocMarker;          // 68
    std::uint32_t                         pad6C;                   // 6C
    BSTArray<SpecialRefData>              specialRefs;             // 70
    BSTArray<UniqueNPCData>               uniqueNPCs;              // 88
    OverrideData*                         overrideData;            // A0
    QueuedPromoteLocationReferencesTask*  promoteRefsTask;         // A8
    BSTArray<std::uint32_t>               promotedRefs;            // B0
    volatile std::int32_t                 loadedCount;             // C8
    std::uint32_t                         fileOffset;              // CC
    BSTArray<KEYWORD_DATA>                keywordData;             // D0
    std::uint32_t                         lastChecked;             // E8
    bool                                  cleared;                 // EC
    bool                                  everCleared;             // ED
    std::uint16_t                         padEE;                   // EE
};
static_assert(sizeof(BGSLocation) == 0xF0, "layout");
