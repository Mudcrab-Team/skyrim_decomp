// Source exposure: binary-analysis
// DeletingLeaf242650, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf242650 {
public:
    virtual ~DeletingLeaf242650() {}
};
static_assert(sizeof(DeletingLeaf242650) == 8, "minimal virtual interface size");
