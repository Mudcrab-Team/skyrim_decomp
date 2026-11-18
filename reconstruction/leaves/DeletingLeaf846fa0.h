// Source exposure: binary-analysis
// DeletingLeaf846fa0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf846fa0 {
public:
    virtual ~DeletingLeaf846fa0() {}
};
static_assert(sizeof(DeletingLeaf846fa0) == 8, "minimal virtual interface size");
