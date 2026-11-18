// Source exposure: binary-analysis
// DeletingLeaf83bf10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83bf10 {
public:
    virtual ~DeletingLeaf83bf10() {}
};
static_assert(sizeof(DeletingLeaf83bf10) == 8, "minimal virtual interface size");
