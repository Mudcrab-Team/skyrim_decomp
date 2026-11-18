// Source exposure: binary-analysis
// DeletingWrapper7b67b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper7b67b0 {
public:
    virtual ~DeletingWrapper7b67b0();
};
static_assert(sizeof(DeletingWrapper7b67b0) == 8, "interface layout");
