// Source exposure: binary-analysis
// DeletingLeaf84a330, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf84a330 {
public:
    virtual ~DeletingLeaf84a330() {}
};
static_assert(sizeof(DeletingLeaf84a330) == 8, "minimal virtual interface size");
