// Source exposure: binary-analysis
// DeletingLeaf8d5090, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8d5090 {
public:
    virtual ~DeletingLeaf8d5090() {}
};
static_assert(sizeof(DeletingLeaf8d5090) == 8, "minimal virtual interface size");
