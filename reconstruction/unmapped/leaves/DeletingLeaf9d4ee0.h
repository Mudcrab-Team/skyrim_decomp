// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x17c1e0 (reconstruction/unmapped/represented/F004Recovered17c1e0.cpp); no external declaration or body reused.
// DeletingLeaf9d4ee0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf9d4ee0
{
public:
    DeletingLeaf9d4ee0();
    virtual ~DeletingLeaf9d4ee0();  // compared: 0x9d4ee0 (scalar deleting destructor)
    unsigned char unknown08[40];
};
static_assert(sizeof(DeletingLeaf9d4ee0) == 48, "size observed from the sized delete argument");
