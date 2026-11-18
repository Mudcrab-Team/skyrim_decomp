// Source exposure: binary-analysis
// DeletingLeaf62dd00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf62dd00 {
public:
    virtual ~DeletingLeaf62dd00() {}
};
static_assert(sizeof(DeletingLeaf62dd00) == 8, "minimal virtual interface size");
