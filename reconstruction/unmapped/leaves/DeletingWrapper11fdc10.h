// Source exposure: binary-analysis
// DeletingWrapper11fdc10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper11fdc10 {
public:
    virtual ~DeletingWrapper11fdc10();
};
static_assert(sizeof(DeletingWrapper11fdc10) == 8, "interface layout");
