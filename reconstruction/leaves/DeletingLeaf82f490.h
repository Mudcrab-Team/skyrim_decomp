// Source exposure: binary-analysis
// DeletingLeaf82f490, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf82f490 {
public:
    virtual ~DeletingLeaf82f490() {}
};
static_assert(sizeof(DeletingLeaf82f490) == 8, "minimal virtual interface size");
