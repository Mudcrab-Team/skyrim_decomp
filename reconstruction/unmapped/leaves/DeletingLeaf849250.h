// Source exposure: binary-analysis
// DeletingLeaf849250, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849250 {
public:
    virtual ~DeletingLeaf849250() {}
};
static_assert(sizeof(DeletingLeaf849250) == 8, "minimal virtual interface size");
