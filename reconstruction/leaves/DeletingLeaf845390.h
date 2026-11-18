// Source exposure: binary-analysis
// DeletingLeaf845390, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf845390 {
public:
    virtual ~DeletingLeaf845390() {}
};
static_assert(sizeof(DeletingLeaf845390) == 8, "minimal virtual interface size");
