// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiBSplineData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
void ReleaseSplineMemoryf77810(void*);
// volatile: the target updates this counter atomically.
extern volatile long gSplineDataCountf77810;
class SplineDataBasef77810
{
public:
    virtual ~SplineDataBasef77810();
    std::uint64_t state;
};
class SplineDataDtorLeaff77810 : public SplineDataBasef77810
{
public:
    SplineDataDtorLeaff77810();
    ~SplineDataDtorLeaff77810() override;
    void* first;
    void* second;
    std::uint64_t unknown20;
};
