// Source exposure: binary-analysis
// DeletingLeaf4f7820, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4f7820 {
public:
    virtual ~DeletingLeaf4f7820() {}
};
static_assert(sizeof(DeletingLeaf4f7820) == 8, "minimal virtual interface size");
