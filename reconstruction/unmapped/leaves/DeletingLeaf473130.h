// Source exposure: binary-analysis
// DeletingLeaf473130, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf473130 {
public:
    virtual ~DeletingLeaf473130() {}
};
static_assert(sizeof(DeletingLeaf473130) == 8, "minimal virtual interface size");
