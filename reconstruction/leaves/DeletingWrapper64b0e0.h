// Source exposure: binary-analysis
// DeletingWrapper64b0e0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper64b0e0 {
public:
    virtual ~DeletingWrapper64b0e0();
};
static_assert(sizeof(DeletingWrapper64b0e0) == 8, "interface layout");
