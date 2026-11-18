// Source exposure: binary-analysis
// DeletingLeaf14a3f50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf14a3f50 {
public:
    virtual ~DeletingLeaf14a3f50() {}
};
static_assert(sizeof(DeletingLeaf14a3f50) == 8, "minimal virtual interface size");
