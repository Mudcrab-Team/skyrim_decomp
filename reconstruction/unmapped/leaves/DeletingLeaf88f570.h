// Source exposure: binary-analysis
// DeletingLeaf88f570, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf88f570 {
public:
    virtual ~DeletingLeaf88f570() {}
};
static_assert(sizeof(DeletingLeaf88f570) == 8, "minimal virtual interface size");
