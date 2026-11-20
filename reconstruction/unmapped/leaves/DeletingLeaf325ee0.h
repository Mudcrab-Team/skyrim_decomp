// Source exposure: binary-analysis
// DeletingLeaf325ee0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf325ee0 {
public:
    virtual ~DeletingLeaf325ee0() {}
};
static_assert(sizeof(DeletingLeaf325ee0) == 8, "minimal virtual interface size");
