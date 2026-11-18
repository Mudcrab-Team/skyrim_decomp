// Source exposure: binary-analysis
// DeletingLeaf84a080, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf84a080 {
public:
    virtual ~DeletingLeaf84a080() {}
};
static_assert(sizeof(DeletingLeaf84a080) == 8, "minimal virtual interface size");
