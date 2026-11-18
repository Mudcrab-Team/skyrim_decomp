// Source exposure: binary-analysis
// DeletingLeaf832250, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832250 {
public:
    virtual ~DeletingLeaf832250() {}
};
static_assert(sizeof(DeletingLeaf832250) == 8, "minimal virtual interface size");
