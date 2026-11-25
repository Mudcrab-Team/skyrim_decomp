// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiExtraDataController, PostLinkObject: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct ExtraRefTargetf97180;
struct ExtraRefTablef97180 { void* unused; void (*destroy)(ExtraRefTargetf97180*); };
struct ExtraRefTargetf97180
{
    ExtraRefTablef97180* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct ExtraOwnerf97180 { ExtraRefTargetf97180* Find(void* name); };
struct ExtraStreamf97180;
struct ExtraPostBasef97180
{
    void PostLinkObject(ExtraStreamf97180& stream);
    std::uint8_t unknown00[0x38];
};
struct ExtraPostLinkLeaff97180 : ExtraPostBasef97180
{
    void PostLinkObject(ExtraStreamf97180& stream);
    ExtraOwnerf97180* owner;
    std::uint8_t unknown40[0x10];
    void* name;
    ExtraRefTargetf97180* value;
};
