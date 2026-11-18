// Source exposure: binary-analysis
// DeletingLeaf11726a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11726a0 {
public:
    virtual ~DeletingLeaf11726a0() {}
};
static_assert(sizeof(DeletingLeaf11726a0) == 8, "minimal virtual interface size");
