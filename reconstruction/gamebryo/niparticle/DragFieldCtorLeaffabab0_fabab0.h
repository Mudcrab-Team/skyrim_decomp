// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysDragFieldModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct DragFieldVectorfabab0 { float x; float y; float z; };
class DragFieldBasefabab0
{
public:
    DragFieldBasefabab0(void*, void*, void*, float, bool, float);
    virtual ~DragFieldBasefabab0();
    std::uint8_t state[0x48];
};
class DragFieldCtorLeaffabab0 : public DragFieldBasefabab0
{
public:
    DragFieldCtorLeaffabab0(void*, void*, void*, float, bool, float, bool, const DragFieldVectorfabab0*);
    bool useDirection;
    DragFieldVectorfabab0 direction;
};
