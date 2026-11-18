// Source exposure: binary-analysis
// DeletingLeaf838860, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf838860 {
public:
    virtual ~DeletingLeaf838860() {}
};
static_assert(sizeof(DeletingLeaf838860) == 8, "minimal virtual interface size");
