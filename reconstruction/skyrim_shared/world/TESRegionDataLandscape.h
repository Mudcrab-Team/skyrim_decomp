// Code origin: names, bases, virtual slots and member offsets are taken from CharmedBaryon/CommonLibSSE-NG
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESRegionDataLandscape, TESRegionDataLandscape::IsLoaded, ::GetIconFileName, ::Unk_05, ::~TESRegionDataLandscape, ::GetType, ::CopyFrom, ::LoadIcon, ::SetIconFileName, ::icon: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRegionData, TESRegionData::Type, ::GetType, ::ConstructSelf, ::CopyFrom, ::LoadData, ::LoadDataHeader, ::dataHeader: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); defined here because the shared forms/TESRegionData.h lacks slots 3-7
// TESRegionData::DataHeader: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG's flag enumeration is reduced to a byte
// TESRegionData::ConstructSelf returning TESRegionData*, TESRegionData::Unk_05(TESRegionData*) returning it and CopyFrom's 32-bit mode argument: STANDIN GUESS(low); NG declares void and bool, the listing returns a new object and passes the value 2
// TESTexture, TESTexture::textureName, BaseFormComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to the members the code reads
// BSFixedString, BSFixedString::HasValue: STANDIN GUESS(low); NG's BSFixedString reduced to its data pointer, the callee at address 0xeb1380 returns an int tested for non-zero
// BSStringT, BSString, BSStringT::EMPTY, BSStringT::Set: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the callee at address 0x10d710 is NG's set_cstr, EMPTY lives at address 0x1b58020
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm;
class TESFile;

class BSFixedString
{
public:
    std::int32_t HasValue() const;  // address 0xeb1380

    const char* _data;  // 00
};
static_assert(sizeof(BSFixedString) == 0x8, "BSFixedString size");

class BSStringT
{
public:
    static const char EMPTY[1];

    bool Set(const char* a_str, std::uint32_t a_len = 0);  // address 0x10d710

    char*         _data;      // 00
    std::uint16_t _size;      // 08
    std::uint16_t _capacity;  // 0A
    std::uint32_t pad0C;      // 0C: padding after NG's capacity member
};
using BSString = BSStringT;
static_assert(sizeof(BSStringT) == 0x10, "BSStringT size");

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent();  // 00
};

class TESTexture : public BaseFormComponent
{
public:
    BSFixedString textureName;  // 08 - ICON
};
static_assert(sizeof(TESTexture) == 0x10, "TESTexture size");
static_assert(offsetof(TESTexture, textureName) == 0x8, "TESTexture::textureName offset");

class TESRegionData
{
public:
    enum class Type : std::uint32_t
    {
        kObjects = 2,
        kWeather = 3,
        kMap = 4,
        kLand = 5,
        kGrass = 6,
        kSound = 7,
        kImposter = 8
    };

    struct DataHeader  // RDAT
    {
        std::uint8_t  flags;     // 0
        std::uint8_t  unk09;     // 1
        std::uint8_t  priority;  // 2
        std::uint8_t  unk0B;     // 3
        std::uint32_t unk0C;     // 4
    };
    static_assert(sizeof(DataHeader) == 0x8, "DataHeader size");

    virtual ~TESRegionData();                                                    // 00
    virtual bool           LoadDataHeader(void* a_arg1);                         // 01
    virtual void           LoadData(TESForm* a_form);                            // 02
    virtual Type           GetType() const = 0;                                  // 03
    virtual TESRegionData* ConstructSelf() = 0;                                  // 04
    virtual TESRegionData* Unk_05(TESRegionData* a_src) = 0;                     // 05
    virtual void           CopyFrom(TESRegionData* a_src, std::uint32_t a_copy) = 0;  // 06
    virtual bool           IsLoaded() const = 0;                                 // 07

    DataHeader dataHeader;  // 08 - RDAT
};
static_assert(sizeof(TESRegionData) == 0x10, "TESRegionData size");

class TESRegionDataLandscape : public TESRegionData
{
public:
    ~TESRegionDataLandscape() override;                                          // 00
    Type           GetType() const override;                                     // 03
    TESRegionData* ConstructSelf() override;                                     // 04
    TESRegionData* Unk_05(TESRegionData* a_src) override;                        // 05 - compared: 0x250bc0
    void           CopyFrom(TESRegionData* a_src, std::uint32_t a_copy) override;  // 06
    bool           IsLoaded() const override;                                    // 07 - compared: 0x250dd0
    virtual bool   LoadIcon(TESFile* a_mod);                                     // 08
    virtual void   GetIconFileName(BSString* a_dst);                             // 09 - compared: 0x250980
    virtual bool   SetIconFileName(BSString* a_name);                            // 0A

    TESTexture* icon;  // 10
};
static_assert(sizeof(TESRegionDataLandscape) == 0x18, "TESRegionDataLandscape size");
static_assert(offsetof(TESRegionDataLandscape, icon) == 0x10, "TESRegionDataLandscape::icon offset");
