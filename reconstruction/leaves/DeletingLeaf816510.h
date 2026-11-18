// Source exposure: binary-analysis
// DeletingLeaf816510, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf816510 {
public:
    virtual ~DeletingLeaf816510() {}
};
static_assert(sizeof(DeletingLeaf816510) == 8, "minimal virtual interface size");
