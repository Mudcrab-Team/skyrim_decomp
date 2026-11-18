// Source exposure: binary-analysis
// DeletingLeaf19bf60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf19bf60 {
public:
    virtual ~DeletingLeaf19bf60() {}
};
static_assert(sizeof(DeletingLeaf19bf60) == 8, "minimal virtual interface size");
