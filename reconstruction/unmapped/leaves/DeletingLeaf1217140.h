// Source exposure: binary-analysis
// DeletingLeaf1217140, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1217140 {
public:
    virtual ~DeletingLeaf1217140() {}
};
static_assert(sizeof(DeletingLeaf1217140) == 8, "minimal virtual interface size");
