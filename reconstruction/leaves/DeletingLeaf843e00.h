// Source exposure: binary-analysis
// DeletingLeaf843e00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf843e00 {
public:
    virtual ~DeletingLeaf843e00() {}
};
static_assert(sizeof(DeletingLeaf843e00) == 8, "minimal virtual interface size");
