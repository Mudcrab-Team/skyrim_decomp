// Source exposure: binary-analysis
// DeletingLeaf216330, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf216330 {
public:
    virtual ~DeletingLeaf216330() {}
};
static_assert(sizeof(DeletingLeaf216330) == 8, "minimal virtual interface size");
