// Source exposure: binary-analysis
// DeletingLeaf457b10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf457b10 {
public:
    virtual ~DeletingLeaf457b10() {}
};
static_assert(sizeof(DeletingLeaf457b10) == 8, "minimal virtual interface size");
