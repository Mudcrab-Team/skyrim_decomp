// Source exposure: binary-analysis
// DeletingLeaf32bb00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf32bb00 {
public:
    virtual ~DeletingLeaf32bb00() {}
};
static_assert(sizeof(DeletingLeaf32bb00) == 8, "minimal virtual interface size");
