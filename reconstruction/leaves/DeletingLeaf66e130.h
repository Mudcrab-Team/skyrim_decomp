// Source exposure: binary-analysis
// DeletingLeaf66e130, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66e130 {
public:
    virtual ~DeletingLeaf66e130() {}
};
static_assert(sizeof(DeletingLeaf66e130) == 8, "minimal virtual interface size");
