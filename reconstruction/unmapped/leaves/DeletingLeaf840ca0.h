// Source exposure: binary-analysis
// DeletingLeaf840ca0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf840ca0 {
public:
    virtual ~DeletingLeaf840ca0() {}
};
static_assert(sizeof(DeletingLeaf840ca0) == 8, "minimal virtual interface size");
