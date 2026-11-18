// Source exposure: binary-analysis
// DeletingLeaf83b210, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83b210 {
public:
    virtual ~DeletingLeaf83b210() {}
};
static_assert(sizeof(DeletingLeaf83b210) == 8, "minimal virtual interface size");
