// Source exposure: binary-analysis
// DeletingLeaf7aaae0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7aaae0 {
public:
    virtual ~DeletingLeaf7aaae0() {}
};
static_assert(sizeof(DeletingLeaf7aaae0) == 8, "minimal virtual interface size");
