// Source exposure: binary-analysis
// DeletingLeaf84a490, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf84a490 {
public:
    virtual ~DeletingLeaf84a490() {}
};
static_assert(sizeof(DeletingLeaf84a490) == 8, "minimal virtual interface size");
