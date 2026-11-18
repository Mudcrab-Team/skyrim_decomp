// Source exposure: binary-analysis
// DeletingLeaf8ec680, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8ec680 {
public:
    virtual ~DeletingLeaf8ec680() {}
};
static_assert(sizeof(DeletingLeaf8ec680) == 8, "minimal virtual interface size");
