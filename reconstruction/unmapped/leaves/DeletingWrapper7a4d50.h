// Source exposure: binary-analysis
// DeletingWrapper7a4d50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper7a4d50 {
public:
    virtual ~DeletingWrapper7a4d50();
};
static_assert(sizeof(DeletingWrapper7a4d50) == 8, "interface layout");
