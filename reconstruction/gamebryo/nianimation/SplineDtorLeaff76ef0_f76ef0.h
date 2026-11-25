// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBSplineData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

void ReleaseSplineStorage(void* memory);
// volatile: the target updates the object counter atomically.
extern volatile long gSplineObjectCount;
class SplineDtorBase
{
public:
    virtual ~SplineDtorBase();
    std::uint64_t state;
};
class SplineDtorLeaff76ef0 : public SplineDtorBase
{
public:
    ~SplineDtorLeaff76ef0() override;
    void* first;
    void* second;
};
