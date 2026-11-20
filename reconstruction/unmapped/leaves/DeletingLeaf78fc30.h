// Source exposure: binary-analysis
// DeletingLeaf78fc30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf78fc30 {
public:
    virtual ~DeletingLeaf78fc30() {}
};
static_assert(sizeof(DeletingLeaf78fc30) == 8, "minimal virtual interface size");
