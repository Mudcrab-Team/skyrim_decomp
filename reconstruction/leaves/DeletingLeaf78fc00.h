// Source exposure: binary-analysis
// DeletingLeaf78fc00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf78fc00 {
public:
    virtual ~DeletingLeaf78fc00() {}
};
static_assert(sizeof(DeletingLeaf78fc00) == 8, "minimal virtual interface size");
