// Source exposure: binary-analysis
// DeletingLeaf9efab0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efab0 {
public:
    virtual ~DeletingLeaf9efab0() {}
};
static_assert(sizeof(DeletingLeaf9efab0) == 8, "minimal virtual interface size");
