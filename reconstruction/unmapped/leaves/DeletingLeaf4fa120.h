// Source exposure: binary-analysis
// DeletingLeaf4fa120, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf4fa120 {
public:
    virtual ~DeletingLeaf4fa120() {}
};
static_assert(sizeof(DeletingLeaf4fa120) == 8, "minimal virtual interface size");
