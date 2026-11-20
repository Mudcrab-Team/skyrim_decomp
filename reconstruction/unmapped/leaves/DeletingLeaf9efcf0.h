// Source exposure: binary-analysis
// DeletingLeaf9efcf0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efcf0 {
public:
    virtual ~DeletingLeaf9efcf0() {}
};
static_assert(sizeof(DeletingLeaf9efcf0) == 8, "minimal virtual interface size");
