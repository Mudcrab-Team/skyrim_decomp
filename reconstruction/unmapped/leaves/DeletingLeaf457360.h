// Source exposure: binary-analysis
// DeletingLeaf457360, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457360 {
public:
    virtual ~DeletingLeaf457360() {}
};
static_assert(sizeof(DeletingLeaf457360) == 8, "minimal virtual interface size");
