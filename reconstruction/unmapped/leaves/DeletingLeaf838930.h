// Source exposure: binary-analysis
// DeletingLeaf838930, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf838930 {
public:
    virtual ~DeletingLeaf838930() {}
};
static_assert(sizeof(DeletingLeaf838930) == 8, "minimal virtual interface size");
