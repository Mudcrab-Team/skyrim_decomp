// Source exposure: binary-analysis
// DeletingLeaf4587b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4587b0 {
public:
    virtual ~DeletingLeaf4587b0() {}
};
static_assert(sizeof(DeletingLeaf4587b0) == 8, "minimal virtual interface size");
