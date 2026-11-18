// Source exposure: binary-analysis
// DeletingLeaf862ec0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf862ec0 {
public:
    virtual ~DeletingLeaf862ec0() {}
};
static_assert(sizeof(DeletingLeaf862ec0) == 8, "minimal virtual interface size");
