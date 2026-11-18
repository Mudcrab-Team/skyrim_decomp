// Source exposure: binary-analysis
// DeletingLeaf849c00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849c00 {
public:
    virtual ~DeletingLeaf849c00() {}
};
static_assert(sizeof(DeletingLeaf849c00) == 8, "minimal virtual interface size");
