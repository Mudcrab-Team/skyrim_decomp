// Source exposure: binary-analysis
// DeletingLeaf457390, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457390 {
public:
    virtual ~DeletingLeaf457390() {}
};
static_assert(sizeof(DeletingLeaf457390) == 8, "minimal virtual interface size");
