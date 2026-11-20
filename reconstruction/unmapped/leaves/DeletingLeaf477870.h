// Source exposure: binary-analysis
// DeletingLeaf477870, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf477870 {
public:
    virtual ~DeletingLeaf477870() {}
};
static_assert(sizeof(DeletingLeaf477870) == 8, "minimal virtual interface size");
