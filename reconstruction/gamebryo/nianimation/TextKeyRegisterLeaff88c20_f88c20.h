// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiTextKeyExtraData, RegisterStreamables: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets and stride observed on the target.
#pragma once
#include <cstdint>
struct TextStreamf88c20;
struct TextKeyf88c20
{
    void Register(TextStreamf88c20& stream);
    std::uint8_t unknown00[0x10];
};
class TextKeyBasef88c20
{
public:
    bool RegisterStreamables(TextStreamf88c20& stream);
    std::uint8_t unknown00[0x18];
};
class TextKeyRegisterLeaff88c20 : public TextKeyBasef88c20
{
public:
    bool RegisterStreamables(TextStreamf88c20& stream);
    std::uint32_t count;
    std::uint32_t unknown1c;
    TextKeyf88c20* keys;
};
