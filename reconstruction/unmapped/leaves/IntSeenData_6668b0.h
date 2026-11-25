// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Game/Misc/SeenData.cpp:249
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout/misc/seendata.cpp:495
// IntSeenData, IntSeenData::~IntSeenData, SeenData: SIBLING(fo4-private@1b765c70, author-permission)
// IntSeenData::pNextSection, IntSeenData::cSectionX, IntSeenData::cSectionY, IntSeenData::pSeenBits: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
// IntSeenData::unknown2A: GUESS(low)
#pragma once

class SeenData
{
public:
    virtual ~SeenData() {}
};

class IntSeenData : public SeenData
{
public:
    ~IntSeenData() override;

    unsigned int pSeenBits[8];  // 08
    char cSectionX;             // 28
    char cSectionY;             // 29
    char unknown2A[6];          // 2A
    IntSeenData* pNextSection;  // 30
};
static_assert(sizeof(IntSeenData) == 0x38, "IntSeenData size");
