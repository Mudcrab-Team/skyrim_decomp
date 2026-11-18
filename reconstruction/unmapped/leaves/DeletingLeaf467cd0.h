// Source exposure: binary-analysis
// DeletingLeaf467cd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf467cd0 {
public:
    virtual ~DeletingLeaf467cd0() {}
};
static_assert(sizeof(DeletingLeaf467cd0) == 8, "minimal virtual interface size");
