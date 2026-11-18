// Source exposure: binary-analysis
// DeletingLeaf494190, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf494190 {
public:
    virtual ~DeletingLeaf494190() {}
};
static_assert(sizeof(DeletingLeaf494190) == 8, "minimal virtual interface size");
