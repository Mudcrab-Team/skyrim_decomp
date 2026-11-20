// Source exposure: binary-analysis
// DeletingLeaf461850, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf461850 {
public:
    virtual ~DeletingLeaf461850() {}
};
static_assert(sizeof(DeletingLeaf461850) == 8, "minimal virtual interface size");
