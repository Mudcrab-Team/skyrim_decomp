// Source exposure: binary-analysis
// DeletingLeaf14dc900, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf14dc900 {
public:
    virtual ~DeletingLeaf14dc900() {}
};
static_assert(sizeof(DeletingLeaf14dc900) == 8, "minimal virtual interface size");
