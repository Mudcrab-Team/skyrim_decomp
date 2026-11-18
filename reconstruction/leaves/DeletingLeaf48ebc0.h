// Source exposure: binary-analysis
// DeletingLeaf48ebc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf48ebc0 {
public:
    virtual ~DeletingLeaf48ebc0() {}
};
static_assert(sizeof(DeletingLeaf48ebc0) == 8, "minimal virtual interface size");
