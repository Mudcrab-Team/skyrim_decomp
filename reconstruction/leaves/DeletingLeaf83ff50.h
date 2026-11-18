// Source exposure: binary-analysis
// DeletingLeaf83ff50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83ff50 {
public:
    virtual ~DeletingLeaf83ff50() {}
};
static_assert(sizeof(DeletingLeaf83ff50) == 8, "minimal virtual interface size");
