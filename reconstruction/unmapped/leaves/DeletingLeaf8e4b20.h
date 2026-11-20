// Source exposure: binary-analysis
// DeletingLeaf8e4b20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8e4b20 {
public:
    virtual ~DeletingLeaf8e4b20() {}
};
static_assert(sizeof(DeletingLeaf8e4b20) == 8, "minimal virtual interface size");
