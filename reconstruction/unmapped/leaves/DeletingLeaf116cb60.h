// Source exposure: binary-analysis
// DeletingLeaf116cb60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf116cb60 {
public:
    virtual ~DeletingLeaf116cb60() {}
};
static_assert(sizeof(DeletingLeaf116cb60) == 8, "minimal virtual interface size");
