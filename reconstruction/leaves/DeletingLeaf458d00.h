// Source exposure: binary-analysis
// DeletingLeaf458d00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458d00 {
public:
    virtual ~DeletingLeaf458d00() {}
};
static_assert(sizeof(DeletingLeaf458d00) == 8, "minimal virtual interface size");
