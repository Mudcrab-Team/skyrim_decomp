// Source exposure: binary-analysis
// DeletingWrapper7a8da0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper7a8da0 {
public:
    virtual ~DeletingWrapper7a8da0();
};
static_assert(sizeof(DeletingWrapper7a8da0) == 8, "interface layout");
