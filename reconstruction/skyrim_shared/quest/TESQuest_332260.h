// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: reduced copy of the declarations needed from reconstruction/forms/TESQuest.h, source file SHA-256 3e1011e2ce64211f971c7c32affc5c14e125b4f4e0ee59a6a405e579b5372eb4, with the member layouts of the base classes and of TESQuest up to the quest data block restored; members after the data block and the virtual slots this unit does not call are left out.
// BaseFormComponent, BaseFormComponent::InitializeDataComponent, ::ClearDataComponent, ::CopyComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm, TESForm::sourceFiles, ::formFlags, ::formID, ::inGameFormFlags, ::formType, ::pad1B, ::pad1C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the TESForm slots 04 and up are not declared, this unit calls none
// TESFileContainer, TESFileContainer::array, TESFileArray, TESFileArray::data, ::size: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout read as in the shared TESForm header
// TESFile, BGSQuestInstanceText, ObjectRefHandle: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque or a 32-bit integer, only used by pointer or by value
// BGSStoryManagerTreeForm, BGSStoryManagerTreeForm::lastVisitorID, ::pad24: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); its slots 3B to 3E are not declared, this unit calls none
// TESFullName, TESFullName::GetFullNameLength, ::GetFullName, ::fullName: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString, BSFixedString::_data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); one pooled string pointer
// BGSBaseAlias: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque, only used by pointer
// BSTArray, BSTArray::data, ::capacity, ::size: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout (data, capacity, size) read from the shared quest header, NG wraps it in an allocator
// BSTArray::pad0C, BSTArray::pad14: GUESS(low); alignment padding after the 32-bit capacity and size
// BSTScatterTable, BSTScatterTable::_pad00, ::_pad08, ::_capacity, ::_free, ::_good, ::_sentinel: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the members of the community table with the allocator flattened into its two fields, key and value types are not modelled
// BSTHashMap: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); an alias of the table stand-in, NG's is a template over key and value
// BSTScatterTable::_allocatorPad00, BSTScatterTable::_entries: GUESS(low); the two fields of the community allocator, which names its members _pad00 and _entries
// BSReadWriteLock, BSReadWriteLock::_writerThread, ::_lock: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESQuest, TESQuest::instanceData, ::currentInstanceID, ::pad054, ::aliases, ::refAliasMap, ::unk0A0, ::aliasAccessLock, ::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the members after data are not declared
// QUEST_DATA, QUEST_DATA::questDelayTime, ::flags, ::priority, ::questType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); plain integers for the stl::enumeration members
#pragma once

#include <cstddef>
#include <cstdint>

class TESFile;
class BGSBaseAlias;
class BGSQuestInstanceText;

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

class BGSStoryManagerTreeForm : public TESForm {
public:
    ~BGSStoryManagerTreeForm() override;  // 00

    // members
    std::uint32_t lastVisitorID;  // 20
    std::uint32_t pad24;          // 24
};
static_assert(sizeof(BGSStoryManagerTreeForm) == 0x28, "layout");

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

class BSTScatterTable {
public:
    std::uint64_t _pad00;            // 00
    std::uint32_t _pad08;            // 08
    std::uint32_t _capacity;         // 0C
    std::uint32_t _free;             // 10
    std::uint32_t _good;             // 14
    const void*   _sentinel;         // 18
    std::uint64_t _allocatorPad00;   // 20
    void*         _entries;          // 28
};
using BSTHashMap = BSTScatterTable;
static_assert(sizeof(BSTHashMap) == 0x30, "layout");

class BSReadWriteLock {
public:
    volatile std::uint32_t _writerThread;  // 0
    volatile std::uint32_t _lock;          // 4
};
static_assert(sizeof(BSReadWriteLock) == 0x8, "layout");

struct QUEST_DATA {
    float         questDelayTime;  // 0
    std::uint16_t flags;           // 4
    std::int8_t   priority;        // 6
    std::uint8_t  questType;       // 7
};
static_assert(sizeof(QUEST_DATA) == 0x8, "layout");

class TESQuest :
    public BGSStoryManagerTreeForm,  // 00
    public TESFullName               // 28
{
public:
    ~TESQuest() override;  // 00

    // members
    BSTArray<BGSQuestInstanceText*> instanceData;       // 38
    std::uint32_t                   currentInstanceID;  // 50
    std::uint32_t                   pad054;             // 54
    BSTArray<BGSBaseAlias*>         aliases;            // 58
    BSTHashMap                      refAliasMap;        // 70
    BSTHashMap                      unk0A0;             // A0
    BSReadWriteLock                 aliasAccessLock;    // D0
    QUEST_DATA                      data;               // D8
};
static_assert(offsetof(TESQuest, data) == 0xD8, "layout");
