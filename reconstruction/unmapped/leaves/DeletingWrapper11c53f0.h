// Source exposure: binary-analysis
// DeletingWrapper11c53f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper11c53f0 {
public:
    virtual ~DeletingWrapper11c53f0();
};
static_assert(sizeof(DeletingWrapper11c53f0) == 8, "interface layout");
