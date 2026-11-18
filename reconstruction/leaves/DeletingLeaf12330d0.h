// Source exposure: binary-analysis
// DeletingLeaf12330d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf12330d0 {
public:
    virtual ~DeletingLeaf12330d0() {}
};
static_assert(sizeof(DeletingLeaf12330d0) == 8, "minimal virtual interface size");
