// Source exposure: binary-analysis
// DeletingWrapper2dc9d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper2dc9d0 {
public:
    virtual ~DeletingWrapper2dc9d0();
};
static_assert(sizeof(DeletingWrapper2dc9d0) == 8, "interface layout");
