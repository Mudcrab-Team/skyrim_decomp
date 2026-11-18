// Source exposure: binary-analysis
// DeletingLeaf473e50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf473e50 {
public:
    virtual ~DeletingLeaf473e50() {}
};
static_assert(sizeof(DeletingLeaf473e50) == 8, "minimal virtual interface size");
