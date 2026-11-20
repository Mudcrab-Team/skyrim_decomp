// Source exposure: binary-analysis
// DeletingLeaf832a60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832a60 {
public:
    virtual ~DeletingLeaf832a60() {}
};
static_assert(sizeof(DeletingLeaf832a60) == 8, "minimal virtual interface size");
