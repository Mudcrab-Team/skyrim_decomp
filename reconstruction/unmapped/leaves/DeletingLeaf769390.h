// Source exposure: binary-analysis
// DeletingLeaf769390, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf769390 {
public:
    virtual ~DeletingLeaf769390() {}
};
static_assert(sizeof(DeletingLeaf769390) == 8, "minimal virtual interface size");
