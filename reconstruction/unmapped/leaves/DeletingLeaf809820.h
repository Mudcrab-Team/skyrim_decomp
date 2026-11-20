// Source exposure: binary-analysis
// DeletingLeaf809820, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809820 {
public:
    virtual ~DeletingLeaf809820() {}
};
static_assert(sizeof(DeletingLeaf809820) == 8, "minimal virtual interface size");
