// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x17c1e0 (reconstruction/unmapped/represented/F004Recovered17c1e0.cpp); no external declaration or body reused.
// DeletingLeaf878a00: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf878a00
{
public:
    DeletingLeaf878a00();
    virtual ~DeletingLeaf878a00();  // compared: 0x878a00 (scalar deleting destructor)
    unsigned char unknown08[40];
};
static_assert(sizeof(DeletingLeaf878a00) == 48, "size observed from the sized delete argument");
