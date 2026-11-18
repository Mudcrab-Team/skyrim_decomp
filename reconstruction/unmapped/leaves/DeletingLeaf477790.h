// Source exposure: binary-analysis
// DeletingLeaf477790, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf477790 {
public:
    virtual ~DeletingLeaf477790() {}
};
static_assert(sizeof(DeletingLeaf477790) == 8, "minimal virtual interface size");
