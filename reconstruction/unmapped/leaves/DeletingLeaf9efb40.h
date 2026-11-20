// Source exposure: binary-analysis
// DeletingLeaf9efb40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efb40 {
public:
    virtual ~DeletingLeaf9efb40() {}
};
static_assert(sizeof(DeletingLeaf9efb40) == 8, "minimal virtual interface size");
