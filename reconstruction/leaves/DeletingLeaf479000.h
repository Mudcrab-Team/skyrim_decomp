// Source exposure: binary-analysis
// DeletingLeaf479000, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf479000 {
public:
    virtual ~DeletingLeaf479000() {}
};
static_assert(sizeof(DeletingLeaf479000) == 8, "minimal virtual interface size");
