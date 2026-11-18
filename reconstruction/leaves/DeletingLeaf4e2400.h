// Source exposure: binary-analysis
// DeletingLeaf4e2400, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4e2400 {
public:
    virtual ~DeletingLeaf4e2400() {}
};
static_assert(sizeof(DeletingLeaf4e2400) == 8, "minimal virtual interface size");
