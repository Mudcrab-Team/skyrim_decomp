// Source exposure: binary-analysis
// DeletingLeaf1221140, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1221140 {
public:
    virtual ~DeletingLeaf1221140() {}
};
static_assert(sizeof(DeletingLeaf1221140) == 8, "minimal virtual interface size");
