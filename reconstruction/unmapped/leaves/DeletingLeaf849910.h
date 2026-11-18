// Source exposure: binary-analysis
// DeletingLeaf849910, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849910 {
public:
    virtual ~DeletingLeaf849910() {}
};
static_assert(sizeof(DeletingLeaf849910) == 8, "minimal virtual interface size");
