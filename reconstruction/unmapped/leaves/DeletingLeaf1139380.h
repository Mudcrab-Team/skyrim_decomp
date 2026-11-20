// Source exposure: binary-analysis
// DeletingLeaf1139380, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1139380 {
public:
    virtual ~DeletingLeaf1139380() {}
};
static_assert(sizeof(DeletingLeaf1139380) == 8, "minimal virtual interface size");
