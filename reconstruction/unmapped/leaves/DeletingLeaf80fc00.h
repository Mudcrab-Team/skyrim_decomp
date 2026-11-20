// Source exposure: binary-analysis
// DeletingLeaf80fc00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf80fc00 {
public:
    virtual ~DeletingLeaf80fc00() {}
};
static_assert(sizeof(DeletingLeaf80fc00) == 8, "minimal virtual interface size");
