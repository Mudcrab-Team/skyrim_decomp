// Source exposure: binary-analysis
// DeletingLeaf858620, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf858620 {
public:
    virtual ~DeletingLeaf858620() {}
};
static_assert(sizeof(DeletingLeaf858620) == 8, "minimal virtual interface size");
