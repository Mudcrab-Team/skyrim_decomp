// Source exposure: binary-analysis
// DeletingLeaf473090, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf473090 {
public:
    virtual ~DeletingLeaf473090() {}
};
static_assert(sizeof(DeletingLeaf473090) == 8, "minimal virtual interface size");
