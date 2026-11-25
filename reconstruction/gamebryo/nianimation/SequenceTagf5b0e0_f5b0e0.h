// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiControllerSequence::IDTag: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target
#pragma once

struct TagString
{
    ~TagString();
    void* value;
};
struct SequenceTagf5b0e0
{
    ~SequenceTagf5b0e0();
    TagString first;
    TagString second;
    TagString third;
    TagString fourth;
    TagString fifth;
};
