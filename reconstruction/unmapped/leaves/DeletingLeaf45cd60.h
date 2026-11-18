// Source exposure: binary-analysis
// DeletingLeaf45cd60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf45cd60 {
public:
    virtual ~DeletingLeaf45cd60() {}
};
static_assert(sizeof(DeletingLeaf45cd60) == 8, "minimal virtual interface size");
