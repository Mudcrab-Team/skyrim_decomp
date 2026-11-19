// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x10fd30 (reconstruction/bscore/ArrayAllocatorLeafLayout.cpp); no external declaration or body reused.
// DeletingLeaf1139200: GUESS(low) STANDIN
// unknown08: GUESS(low) STANDIN
#pragma once

class DeletingLeaf1139200
{
public:
    DeletingLeaf1139200();
    virtual ~DeletingLeaf1139200();  // compared: 0x1139200
    void* unknown08;
};
static_assert(sizeof(DeletingLeaf1139200) == 16, "size observed from the sized delete argument");
