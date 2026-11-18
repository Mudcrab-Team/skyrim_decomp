// Source exposure: binary-analysis
// DeletingLeaf2fe2f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf2fe2f0 {
public:
    virtual ~DeletingLeaf2fe2f0() {}
};
static_assert(sizeof(DeletingLeaf2fe2f0) == 8, "minimal virtual interface size");
