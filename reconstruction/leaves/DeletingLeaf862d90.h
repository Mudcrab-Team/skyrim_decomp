// Source exposure: binary-analysis
// DeletingLeaf862d90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf862d90 {
public:
    virtual ~DeletingLeaf862d90() {}
};
static_assert(sizeof(DeletingLeaf862d90) == 8, "minimal virtual interface size");
