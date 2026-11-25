// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysEmitterCtlrData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
// volatile: the target updates this counter atomically.
extern volatile long gEmitterDataCountfad900;
extern void (*gEmitterKeyDestroyersfad900[])(void*);
class EmitterDataBasefad900
{
public:
    virtual ~EmitterDataBasefad900();
    std::uint8_t state[0x10];
};
class EmitterDataDtorLeaffad900 : public EmitterDataBasefad900
{
public:
    ~EmitterDataDtorLeaffad900() override;
    void* first;
    std::int32_t firstType;
    std::uint8_t unknown24[0xc];
    void* second;
    std::int32_t secondType;
};
