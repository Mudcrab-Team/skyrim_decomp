// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysDragModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
extern const float gDragXfad1e0;
extern const float gDragYfad1e0;
extern const float gDragZfad1e0;
class DragBasefad1e0
{
public:
    DragBasefad1e0();
    virtual ~DragBasefad1e0();
    std::uint8_t state[0x28];
};
class DragCtorLeaffad1e0 : public DragBasefad1e0
{
public:
    DragCtorLeaffad1e0();
    void* target;
    float x;
    float y;
    float z;
    float threshold;
    float limitA;
    float limitB;
};
