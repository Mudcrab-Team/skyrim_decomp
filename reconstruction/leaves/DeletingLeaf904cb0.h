// Source exposure: binary-analysis
// DeletingLeaf904cb0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf904cb0 {
public:
    virtual ~DeletingLeaf904cb0() {}
};
static_assert(sizeof(DeletingLeaf904cb0) == 8, "minimal virtual interface size");
