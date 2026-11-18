// Source exposure: binary-analysis
// DeletingLeaf8389d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8389d0 {
public:
    virtual ~DeletingLeaf8389d0() {}
};
static_assert(sizeof(DeletingLeaf8389d0) == 8, "minimal virtual interface size");
