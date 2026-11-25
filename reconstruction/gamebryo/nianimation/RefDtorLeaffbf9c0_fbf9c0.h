// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiLightDimmerController: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
struct TimelineReffbf9c0;
struct TimelineTablefbf9c0 { void* unused; void (*destroy)(TimelineReffbf9c0*); };
struct TimelineReffbf9c0
{
    TimelineTablefbf9c0* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct TimelinePtrfbf9c0
{
    ~TimelinePtrfbf9c0();
    TimelineReffbf9c0* value;
};
class TimelineBasefbf9c0
{
public:
    virtual ~TimelineBasefbf9c0();
    std::uint8_t state[0x40];
};
class RefDtorLeaffbf9c0 : public TimelineBasefbf9c0
{
public:
    RefDtorLeaffbf9c0();
    ~RefDtorLeaffbf9c0() override;
    TimelinePtrfbf9c0 data;
};
