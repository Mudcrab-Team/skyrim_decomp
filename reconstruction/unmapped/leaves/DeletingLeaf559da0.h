// Source exposure: binary-analysis
// DeletingLeaf559da0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf559da0 {
public:
    virtual ~DeletingLeaf559da0() {}
};
static_assert(sizeof(DeletingLeaf559da0) == 8, "minimal virtual interface size");
