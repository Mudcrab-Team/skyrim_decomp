// Source exposure: binary-analysis
// DeletingLeaf1216c40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1216c40 {
public:
    virtual ~DeletingLeaf1216c40() {}
};
static_assert(sizeof(DeletingLeaf1216c40) == 8, "minimal virtual interface size");
