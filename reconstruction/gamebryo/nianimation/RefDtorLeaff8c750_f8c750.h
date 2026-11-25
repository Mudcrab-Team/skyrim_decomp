// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// BSRotAccumTransfInterpolator: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
struct TimelineReff8c750;
struct TimelineTablef8c750 { void* unused; void (*destroy)(TimelineReff8c750*); };
struct TimelineReff8c750
{
    TimelineTablef8c750* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct TimelinePtrf8c750
{
    ~TimelinePtrf8c750();
    TimelineReff8c750* value;
};
class TimelineBasef8c750
{
public:
    virtual ~TimelineBasef8c750();
    std::uint8_t state[0x30];
};
class RefDtorLeaff8c750 : public TimelineBasef8c750
{
public:
    RefDtorLeaff8c750();
    ~RefDtorLeaff8c750() override;
    TimelinePtrf8c750 data;
    std::uint8_t unknown40[0x18];
};
