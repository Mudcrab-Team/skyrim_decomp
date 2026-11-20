// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x17c1e0 (reconstruction/unmapped/represented/F004Recovered17c1e0.cpp); no external declaration or body reused.
// DeletingLeaf9d4f60: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf9d4f60
{
public:
    DeletingLeaf9d4f60();
    virtual ~DeletingLeaf9d4f60();  // compared: 0x9d4f60 (scalar deleting destructor)
    unsigned char unknown08[40];
};
static_assert(sizeof(DeletingLeaf9d4f60) == 48, "size observed from the sized delete argument");
