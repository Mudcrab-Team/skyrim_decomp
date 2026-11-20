// Source exposure: binary-analysis
// DeletingLeaf457960, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457960 {
public:
    virtual ~DeletingLeaf457960() {}
};
static_assert(sizeof(DeletingLeaf457960) == 8, "minimal virtual interface size");
