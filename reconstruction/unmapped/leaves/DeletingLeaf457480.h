// Source exposure: binary-analysis
// DeletingLeaf457480, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457480 {
public:
    virtual ~DeletingLeaf457480() {}
};
static_assert(sizeof(DeletingLeaf457480) == 8, "minimal virtual interface size");
