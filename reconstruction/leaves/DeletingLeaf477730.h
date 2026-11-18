// Source exposure: binary-analysis
// DeletingLeaf477730, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf477730 {
public:
    virtual ~DeletingLeaf477730() {}
};
static_assert(sizeof(DeletingLeaf477730) == 8, "minimal virtual interface size");
