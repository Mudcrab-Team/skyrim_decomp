// Source exposure: binary-analysis
// DeletingLeaf8e8d30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8e8d30 {
public:
    virtual ~DeletingLeaf8e8d30() {}
};
static_assert(sizeof(DeletingLeaf8e8d30) == 8, "minimal virtual interface size");
