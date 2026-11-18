// Source exposure: binary-analysis
// DeletingLeaf840db0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf840db0 {
public:
    virtual ~DeletingLeaf840db0() {}
};
static_assert(sizeof(DeletingLeaf840db0) == 8, "minimal virtual interface size");
