// Source exposure: binary-analysis
// DeletingLeaf47c910, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf47c910 {
public:
    virtual ~DeletingLeaf47c910() {}
};
static_assert(sizeof(DeletingLeaf47c910) == 8, "minimal virtual interface size");
