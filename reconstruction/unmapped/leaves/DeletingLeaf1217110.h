// Source exposure: binary-analysis
// DeletingLeaf1217110, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1217110 {
public:
    virtual ~DeletingLeaf1217110() {}
};
static_assert(sizeof(DeletingLeaf1217110) == 8, "minimal virtual interface size");
