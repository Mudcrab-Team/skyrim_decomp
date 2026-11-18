// Source exposure: binary-analysis
// DeletingLeaf457e10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457e10 {
public:
    virtual ~DeletingLeaf457e10() {}
};
static_assert(sizeof(DeletingLeaf457e10) == 8, "minimal virtual interface size");
