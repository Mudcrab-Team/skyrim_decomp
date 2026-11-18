// Source exposure: binary-analysis
// DeletingLeaf48eb20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf48eb20 {
public:
    virtual ~DeletingLeaf48eb20() {}
};
static_assert(sizeof(DeletingLeaf48eb20) == 8, "minimal virtual interface size");
