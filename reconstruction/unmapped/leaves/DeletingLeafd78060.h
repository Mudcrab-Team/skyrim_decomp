// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeafd78060: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeafd78060
{
public:
    DeletingLeafd78060();
    virtual ~DeletingLeafd78060();  // compared: 0xd78060
    void* unknown08;
};
static_assert(sizeof(DeletingLeafd78060) == 16, "size observed from the sized delete argument");
