// Source exposure: binary-analysis
// DeletingLeaf844380, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf844380 {
public:
    virtual ~DeletingLeaf844380() {}
};
static_assert(sizeof(DeletingLeaf844380) == 8, "minimal virtual interface size");
