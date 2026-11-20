// Source exposure: binary-analysis
// DeletingLeaf1237540, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1237540 {
public:
    virtual ~DeletingLeaf1237540() {}
};
static_assert(sizeof(DeletingLeaf1237540) == 8, "minimal virtual interface size");
