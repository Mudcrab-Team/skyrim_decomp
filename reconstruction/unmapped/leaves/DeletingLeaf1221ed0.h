// Source exposure: binary-analysis
// DeletingLeaf1221ed0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1221ed0 {
public:
    virtual ~DeletingLeaf1221ed0() {}
};
static_assert(sizeof(DeletingLeaf1221ed0) == 8, "minimal virtual interface size");
