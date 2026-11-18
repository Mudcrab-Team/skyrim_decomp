// Source exposure: binary-analysis
// DeletingLeaf457900, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457900 {
public:
    virtual ~DeletingLeaf457900() {}
};
static_assert(sizeof(DeletingLeaf457900) == 8, "minimal virtual interface size");
