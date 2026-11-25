// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiLightDimmerController: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
struct TimelineReff7f160;
struct TimelineTablef7f160 { void* unused; void (*destroy)(TimelineReff7f160*); };
struct TimelineReff7f160
{
    TimelineTablef7f160* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct TimelinePtrf7f160
{
    ~TimelinePtrf7f160();
    TimelineReff7f160* value;
};
class TimelineBasef7f160
{
public:
    virtual ~TimelineBasef7f160();
    std::uint8_t state[0x40];
};
class RefDtorLeaff7f160 : public TimelineBasef7f160
{
public:
    RefDtorLeaff7f160();
    ~RefDtorLeaff7f160() override;
    TimelinePtrf7f160 data;
};
