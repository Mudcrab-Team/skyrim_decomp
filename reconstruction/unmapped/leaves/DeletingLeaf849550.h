// Source exposure: binary-analysis
// DeletingLeaf849550, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849550 {
public:
    virtual ~DeletingLeaf849550() {}
};
static_assert(sizeof(DeletingLeaf849550) == 8, "minimal virtual interface size");
