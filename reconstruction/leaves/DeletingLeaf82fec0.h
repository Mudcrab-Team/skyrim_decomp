// Source exposure: binary-analysis
// DeletingLeaf82fec0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf82fec0 {
public:
    virtual ~DeletingLeaf82fec0() {}
};
static_assert(sizeof(DeletingLeaf82fec0) == 8, "minimal virtual interface size");
