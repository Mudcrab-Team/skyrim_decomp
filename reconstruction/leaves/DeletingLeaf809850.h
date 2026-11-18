// Source exposure: binary-analysis
// DeletingLeaf809850, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809850 {
public:
    virtual ~DeletingLeaf809850() {}
};
static_assert(sizeof(DeletingLeaf809850) == 8, "minimal virtual interface size");
