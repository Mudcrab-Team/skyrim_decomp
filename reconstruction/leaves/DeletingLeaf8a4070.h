// Source exposure: binary-analysis
// DeletingLeaf8a4070, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8a4070 {
public:
    virtual ~DeletingLeaf8a4070() {}
};
static_assert(sizeof(DeletingLeaf8a4070) == 8, "minimal virtual interface size");
