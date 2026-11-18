// Source exposure: binary-analysis
// DeletingLeaf32ba70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf32ba70 {
public:
    virtual ~DeletingLeaf32ba70() {}
};
static_assert(sizeof(DeletingLeaf32ba70) == 8, "minimal virtual interface size");
