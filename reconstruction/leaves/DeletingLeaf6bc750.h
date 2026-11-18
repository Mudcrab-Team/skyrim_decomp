// Source exposure: binary-analysis
// DeletingLeaf6bc750, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf6bc750 {
public:
    virtual ~DeletingLeaf6bc750() {}
};
static_assert(sizeof(DeletingLeaf6bc750) == 8, "minimal virtual interface size");
