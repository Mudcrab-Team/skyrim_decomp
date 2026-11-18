// Source exposure: binary-analysis
// DeletingLeaf458630, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458630 {
public:
    virtual ~DeletingLeaf458630() {}
};
static_assert(sizeof(DeletingLeaf458630) == 8, "minimal virtual interface size");
