// Source exposure: binary-analysis
// DeletingLeaf12235a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf12235a0 {
public:
    virtual ~DeletingLeaf12235a0() {}
};
static_assert(sizeof(DeletingLeaf12235a0) == 8, "minimal virtual interface size");
