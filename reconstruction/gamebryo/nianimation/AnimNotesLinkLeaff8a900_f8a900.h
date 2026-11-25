// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// BSAnimNotes, LinkObject: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct AnimNoteReff8a900
{
    void* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct AnimStreamf8a900 { AnimNoteReff8a900* GetLinkedObject(); };
struct AnimNotesBasef8a900
{
    void LinkObject(AnimStreamf8a900& stream);
    std::uint8_t state[0x10];
};
struct AnimNotesLinkLeaff8a900 : AnimNotesBasef8a900
{
    void LinkObject(AnimStreamf8a900& stream);
    AnimNoteReff8a900** values;
    std::uint16_t count;
};
