// Source exposure: binary-analysis
// DeletingLeaf893570, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893570 {
public:
    virtual ~DeletingLeaf893570() {}
};
static_assert(sizeof(DeletingLeaf893570) == 8, "minimal virtual interface size");
