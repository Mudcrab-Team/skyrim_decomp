// Source exposure: binary-analysis
// DeletingLeaf5b9260, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5b9260 {
public:
    virtual ~DeletingLeaf5b9260() {}
};
static_assert(sizeof(DeletingLeaf5b9260) == 8, "minimal virtual interface size");
