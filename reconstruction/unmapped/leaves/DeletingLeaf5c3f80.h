// Source exposure: binary-analysis
// DeletingLeaf5c3f80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5c3f80 {
public:
    virtual ~DeletingLeaf5c3f80() {}
};
static_assert(sizeof(DeletingLeaf5c3f80) == 8, "minimal virtual interface size");
