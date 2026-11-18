// Source exposure: binary-analysis
// DeletingLeaf843850, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf843850 {
public:
    virtual ~DeletingLeaf843850() {}
};
static_assert(sizeof(DeletingLeaf843850) == 8, "minimal virtual interface size");
