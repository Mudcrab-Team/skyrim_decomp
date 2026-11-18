// Source exposure: binary-analysis
// DeletingLeaf4778a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4778a0 {
public:
    virtual ~DeletingLeaf4778a0() {}
};
static_assert(sizeof(DeletingLeaf4778a0) == 8, "minimal virtual interface size");
