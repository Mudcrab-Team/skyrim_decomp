// Source exposure: binary-analysis
// DeletingLeaf1223600, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1223600 {
public:
    virtual ~DeletingLeaf1223600() {}
};
static_assert(sizeof(DeletingLeaf1223600) == 8, "minimal virtual interface size");
