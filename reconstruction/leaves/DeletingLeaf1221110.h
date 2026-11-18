// Source exposure: binary-analysis
// DeletingLeaf1221110, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1221110 {
public:
    virtual ~DeletingLeaf1221110() {}
};
static_assert(sizeof(DeletingLeaf1221110) == 8, "minimal virtual interface size");
