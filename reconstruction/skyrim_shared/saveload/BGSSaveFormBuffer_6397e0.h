// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveFormBuffer.cpp:55
// BGSSaveFormBuffer::SetHeader: SIBLING(fo4-private@1b765c70, author-permission)
// BGSSaveFormBuffer, BGSChangeFlags, ENUM_FORM_ID, SaveFormHeader, FormIDIndex, FormInfo, FormIDIndex::SetNumericID, FormInfo::SetFormType: GUESS(low); the names are the ones the sibling body uses, the layouts come from the listing
// BGSSaveFormBuffer::unknown00: GUESS(low)
#pragma once

#include <cstdint>

struct BGSChangeFlags
{
    std::uint32_t flags;
};

enum ENUM_FORM_ID : std::int32_t
{
    kFormIDNone = 0
};

#pragma pack(push, 1)
struct FormIDIndex
{
    void SetNumericID(std::uint32_t a_formID);

    std::uint8_t bytes[3];  // 00
};

struct FormInfo
{
    void SetFormType(ENUM_FORM_ID a_type);

    std::uint8_t byte;  // 00
};

struct SaveFormHeader
{
    FormIDIndex formIDIndex;       // 00
    std::uint32_t changeFlags;     // 03
    FormInfo formInfo;             // 07
    std::uint8_t version;          // 08
};
#pragma pack(pop)

class BGSSaveFormBuffer
{
public:
    void SetHeader(std::uint32_t a_formID, BGSChangeFlags a_changeFlags, ENUM_FORM_ID a_formType, std::uint8_t a_version);

    std::uint8_t unknown00[0x18];  // 00
    SaveFormHeader header;         // 18
};
