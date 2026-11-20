// Source exposure: binary-analysis
// DeletingWrapper11d2df0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper11d2df0 {
public:
    virtual ~DeletingWrapper11d2df0();
};
static_assert(sizeof(DeletingWrapper11d2df0) == 8, "interface layout");
