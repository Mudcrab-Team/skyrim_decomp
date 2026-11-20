// Source exposure: binary-analysis
// DeletingLeaf122b530, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122b530 {
public:
    virtual ~DeletingLeaf122b530() {}
};
static_assert(sizeof(DeletingLeaf122b530) == 8, "minimal virtual interface size");
