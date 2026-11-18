// Source exposure: binary-analysis
// DeletingLeaf450880, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf450880 {
public:
    virtual ~DeletingLeaf450880() {}
};
static_assert(sizeof(DeletingLeaf450880) == 8, "minimal virtual interface size");
