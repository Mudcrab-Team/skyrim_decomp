// Source exposure: binary-analysis
// DeletingLeaf47d260, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf47d260 {
public:
    virtual ~DeletingLeaf47d260() {}
};
static_assert(sizeof(DeletingLeaf47d260) == 8, "minimal virtual interface size");
