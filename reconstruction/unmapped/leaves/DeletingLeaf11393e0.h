// Source exposure: binary-analysis
// DeletingLeaf11393e0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11393e0 {
public:
    virtual ~DeletingLeaf11393e0() {}
};
static_assert(sizeof(DeletingLeaf11393e0) == 8, "minimal virtual interface size");
