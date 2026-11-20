// Source exposure: binary-analysis
// DeletingLeaf2fe320, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf2fe320 {
public:
    virtual ~DeletingLeaf2fe320() {}
};
static_assert(sizeof(DeletingLeaf2fe320) == 8, "minimal virtual interface size");
