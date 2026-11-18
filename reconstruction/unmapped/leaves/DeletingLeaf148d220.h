// Source exposure: binary-analysis
// DeletingLeaf148d220, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf148d220 {
public:
    virtual ~DeletingLeaf148d220() {}
};
static_assert(sizeof(DeletingLeaf148d220) == 8, "minimal virtual interface size");
