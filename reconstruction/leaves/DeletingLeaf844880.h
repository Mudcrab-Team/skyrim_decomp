// Source exposure: binary-analysis
// DeletingLeaf844880, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf844880 {
public:
    virtual ~DeletingLeaf844880() {}
};
static_assert(sizeof(DeletingLeaf844880) == 8, "minimal virtual interface size");
