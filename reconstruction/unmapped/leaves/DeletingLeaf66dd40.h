// Source exposure: binary-analysis
// DeletingLeaf66dd40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66dd40 {
public:
    virtual ~DeletingLeaf66dd40() {}
};
static_assert(sizeof(DeletingLeaf66dd40) == 8, "minimal virtual interface size");
