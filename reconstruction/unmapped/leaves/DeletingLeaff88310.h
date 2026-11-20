// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x17c1e0 (reconstruction/unmapped/represented/F004Recovered17c1e0.cpp); no external declaration or body reused.
// DeletingLeaff88310: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaff88310
{
public:
    DeletingLeaff88310();
    virtual ~DeletingLeaff88310();  // compared: 0xf88310 (scalar deleting destructor)
    unsigned char unknown08[40];
};
static_assert(sizeof(DeletingLeaff88310) == 48, "size observed from the sized delete argument");
