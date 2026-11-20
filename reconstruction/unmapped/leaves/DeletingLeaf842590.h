// Source exposure: binary-analysis
// DeletingLeaf842590, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf842590 {
public:
    virtual ~DeletingLeaf842590() {}
};
static_assert(sizeof(DeletingLeaf842590) == 8, "minimal virtual interface size");
