// Source exposure: binary-analysis
// DeletingLeaf83bda0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83bda0 {
public:
    virtual ~DeletingLeaf83bda0() {}
};
static_assert(sizeof(DeletingLeaf83bda0) == 8, "minimal virtual interface size");
