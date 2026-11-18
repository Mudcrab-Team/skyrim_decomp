// Source exposure: binary-analysis
// DeletingLeaf840fb0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf840fb0 {
public:
    virtual ~DeletingLeaf840fb0() {}
};
static_assert(sizeof(DeletingLeaf840fb0) == 8, "minimal virtual interface size");
