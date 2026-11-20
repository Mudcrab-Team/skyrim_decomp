// Source exposure: binary-analysis
// DeletingLeaf457570, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457570 {
public:
    virtual ~DeletingLeaf457570() {}
};
static_assert(sizeof(DeletingLeaf457570) == 8, "minimal virtual interface size");
