// Source exposure: binary-analysis
// DeletingLeaf841c20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf841c20 {
public:
    virtual ~DeletingLeaf841c20() {}
};
static_assert(sizeof(DeletingLeaf841c20) == 8, "minimal virtual interface size");
