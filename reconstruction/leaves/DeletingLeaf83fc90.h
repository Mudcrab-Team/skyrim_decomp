// Source exposure: binary-analysis
// DeletingLeaf83fc90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83fc90 {
public:
    virtual ~DeletingLeaf83fc90() {}
};
static_assert(sizeof(DeletingLeaf83fc90) == 8, "minimal virtual interface size");
