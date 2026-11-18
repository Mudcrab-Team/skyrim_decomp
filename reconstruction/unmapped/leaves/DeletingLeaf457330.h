// Source exposure: binary-analysis
// DeletingLeaf457330, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457330 {
public:
    virtual ~DeletingLeaf457330() {}
};
static_assert(sizeof(DeletingLeaf457330) == 8, "minimal virtual interface size");
