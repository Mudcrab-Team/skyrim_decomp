// Source exposure: binary-analysis
// DeletingLeaf11cb7d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11cb7d0 {
public:
    virtual ~DeletingLeaf11cb7d0() {}
};
static_assert(sizeof(DeletingLeaf11cb7d0) == 8, "minimal virtual interface size");
