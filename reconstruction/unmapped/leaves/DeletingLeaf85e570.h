// Source exposure: binary-analysis
// DeletingLeaf85e570, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf85e570 {
public:
    virtual ~DeletingLeaf85e570() {}
};
static_assert(sizeof(DeletingLeaf85e570) == 8, "minimal virtual interface size");
