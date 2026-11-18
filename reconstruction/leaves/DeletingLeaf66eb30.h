// Source exposure: binary-analysis
// DeletingLeaf66eb30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66eb30 {
public:
    virtual ~DeletingLeaf66eb30() {}
};
static_assert(sizeof(DeletingLeaf66eb30) == 8, "minimal virtual interface size");
