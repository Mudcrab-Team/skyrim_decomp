// Source exposure: binary-analysis
// DeletingLeaf83b650, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83b650 {
public:
    virtual ~DeletingLeaf83b650() {}
};
static_assert(sizeof(DeletingLeaf83b650) == 8, "minimal virtual interface size");
