// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1507e00 (reconstruction/bsshader/BSImagespaceShaderBlur3.cpp); no external declaration or body reused.
// DeletingLeaf15081c0: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf15081c0
{
public:
    DeletingLeaf15081c0();
    virtual ~DeletingLeaf15081c0();  // compared: 0x15081c0 (scalar deleting destructor)
    unsigned char unknown08[416];
};
static_assert(sizeof(DeletingLeaf15081c0) == 424, "size observed from the sized delete argument");
