// Source exposure: binary-analysis
// DeletingLeaf830500, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830500 {
public:
    virtual ~DeletingLeaf830500() {}
};
static_assert(sizeof(DeletingLeaf830500) == 8, "minimal virtual interface size");
