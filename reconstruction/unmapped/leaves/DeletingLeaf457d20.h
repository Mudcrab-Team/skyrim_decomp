// Source exposure: binary-analysis
// DeletingLeaf457d20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457d20 {
public:
    virtual ~DeletingLeaf457d20() {}
};
static_assert(sizeof(DeletingLeaf457d20) == 8, "minimal virtual interface size");
