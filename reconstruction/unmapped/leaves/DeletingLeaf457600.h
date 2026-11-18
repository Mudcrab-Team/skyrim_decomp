// Source exposure: binary-analysis
// DeletingLeaf457600, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457600 {
public:
    virtual ~DeletingLeaf457600() {}
};
static_assert(sizeof(DeletingLeaf457600) == 8, "minimal virtual interface size");
