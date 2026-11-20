// Source exposure: binary-analysis
// DeletingLeaf1172380, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1172380 {
public:
    virtual ~DeletingLeaf1172380() {}
};
static_assert(sizeof(DeletingLeaf1172380) == 8, "minimal virtual interface size");
