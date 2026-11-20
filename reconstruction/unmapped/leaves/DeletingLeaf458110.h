// Source exposure: binary-analysis
// DeletingLeaf458110, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458110 {
public:
    virtual ~DeletingLeaf458110() {}
};
static_assert(sizeof(DeletingLeaf458110) == 8, "minimal virtual interface size");
