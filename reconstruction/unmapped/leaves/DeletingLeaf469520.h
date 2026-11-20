// Source exposure: binary-analysis
// DeletingLeaf469520, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf469520 {
public:
    virtual ~DeletingLeaf469520() {}
};
static_assert(sizeof(DeletingLeaf469520) == 8, "minimal virtual interface size");
