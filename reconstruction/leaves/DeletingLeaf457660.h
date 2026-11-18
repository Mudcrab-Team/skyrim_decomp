// Source exposure: binary-analysis
// DeletingLeaf457660, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457660 {
public:
    virtual ~DeletingLeaf457660() {}
};
static_assert(sizeof(DeletingLeaf457660) == 8, "minimal virtual interface size");
