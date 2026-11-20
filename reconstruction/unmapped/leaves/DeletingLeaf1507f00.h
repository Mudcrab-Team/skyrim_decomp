// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1507e00 (reconstruction/bsshader/BSImagespaceShaderBlur3.cpp); no external declaration or body reused.
// DeletingLeaf1507f00: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1507f00
{
public:
    DeletingLeaf1507f00();
    virtual ~DeletingLeaf1507f00();  // compared: 0x1507f00 (scalar deleting destructor)
    unsigned char unknown08[416];
};
static_assert(sizeof(DeletingLeaf1507f00) == 424, "size observed from the sized delete argument");
