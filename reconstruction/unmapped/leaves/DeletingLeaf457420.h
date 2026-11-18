// Source exposure: binary-analysis
// DeletingLeaf457420, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457420 {
public:
    virtual ~DeletingLeaf457420() {}
};
static_assert(sizeof(DeletingLeaf457420) == 8, "minimal virtual interface size");
