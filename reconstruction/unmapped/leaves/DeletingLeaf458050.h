// Source exposure: binary-analysis
// DeletingLeaf458050, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458050 {
public:
    virtual ~DeletingLeaf458050() {}
};
static_assert(sizeof(DeletingLeaf458050) == 8, "minimal virtual interface size");
