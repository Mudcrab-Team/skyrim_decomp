// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1507e00 (reconstruction/bsshader/BSImagespaceShaderBlur3.cpp); no external declaration or body reused.
// DeletingLeaf1508d10: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1508d10
{
public:
    DeletingLeaf1508d10();
    virtual ~DeletingLeaf1508d10();  // compared: 0x1508d10 (scalar deleting destructor)
    unsigned char unknown08[416];
};
static_assert(sizeof(DeletingLeaf1508d10) == 424, "size observed from the sized delete argument");
