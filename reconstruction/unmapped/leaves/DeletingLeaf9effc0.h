// Source exposure: binary-analysis
// DeletingLeaf9effc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9effc0 {
public:
    virtual ~DeletingLeaf9effc0() {}
};
static_assert(sizeof(DeletingLeaf9effc0) == 8, "minimal virtual interface size");
