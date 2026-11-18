// Source exposure: binary-analysis
// DeletingLeaf3cbb10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf3cbb10 {
public:
    virtual ~DeletingLeaf3cbb10() {}
};
static_assert(sizeof(DeletingLeaf3cbb10) == 8, "minimal virtual interface size");
