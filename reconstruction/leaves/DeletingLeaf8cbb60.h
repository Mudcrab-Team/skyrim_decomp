// Source exposure: binary-analysis
// DeletingLeaf8cbb60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8cbb60 {
public:
    virtual ~DeletingLeaf8cbb60() {}
};
static_assert(sizeof(DeletingLeaf8cbb60) == 8, "minimal virtual interface size");
