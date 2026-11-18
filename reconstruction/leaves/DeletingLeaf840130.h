// Source exposure: binary-analysis
// DeletingLeaf840130, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf840130 {
public:
    virtual ~DeletingLeaf840130() {}
};
static_assert(sizeof(DeletingLeaf840130) == 8, "minimal virtual interface size");
