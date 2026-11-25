// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// BSMultiTargetTreadTransfController: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
class TreadBasef5ea30
{
public:
    TreadBasef5ea30();
    virtual ~TreadBasef5ea30();
    std::uint8_t state[0x40];
};
class TreadCtorLeaff5ea30 : public TreadBasef5ea30
{
public:
    TreadCtorLeaff5ea30(std::uint16_t first, std::uint16_t second);
    void Initialize(std::uint16_t first, std::uint16_t second);
    void* firstArray;
    std::uint16_t firstCount;
    void* secondArray;
    std::uint16_t secondCount;
};
