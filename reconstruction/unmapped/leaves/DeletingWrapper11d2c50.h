// Source exposure: binary-analysis
// DeletingWrapper11d2c50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper11d2c50 {
public:
    virtual ~DeletingWrapper11d2c50();
};
static_assert(sizeof(DeletingWrapper11d2c50) == 8, "interface layout");
