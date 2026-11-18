// Source exposure: binary-analysis
// DeletingLeaf7aaa50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf7aaa50 {
public:
    virtual ~DeletingLeaf7aaa50() {}
};
static_assert(sizeof(DeletingLeaf7aaa50) == 8, "minimal virtual interface size");
