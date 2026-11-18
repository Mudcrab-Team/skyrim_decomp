// Source exposure: binary-analysis
// DeletingLeaf7db130, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7db130 {
public:
    virtual ~DeletingLeaf7db130() {}
};
static_assert(sizeof(DeletingLeaf7db130) == 8, "minimal virtual interface size");
