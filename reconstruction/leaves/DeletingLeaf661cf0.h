// Source exposure: binary-analysis
// DeletingLeaf661cf0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf661cf0 {
public:
    virtual ~DeletingLeaf661cf0() {}
};
static_assert(sizeof(DeletingLeaf661cf0) == 8, "minimal virtual interface size");
