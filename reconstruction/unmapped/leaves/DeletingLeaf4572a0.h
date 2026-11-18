// Source exposure: binary-analysis
// DeletingLeaf4572a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4572a0 {
public:
    virtual ~DeletingLeaf4572a0() {}
};
static_assert(sizeof(DeletingLeaf4572a0) == 8, "minimal virtual interface size");
