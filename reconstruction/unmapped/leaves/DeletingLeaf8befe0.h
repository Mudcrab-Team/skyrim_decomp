// Source exposure: binary-analysis
// DeletingLeaf8befe0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8befe0 {
public:
    virtual ~DeletingLeaf8befe0() {}
};
static_assert(sizeof(DeletingLeaf8befe0) == 8, "minimal virtual interface size");
