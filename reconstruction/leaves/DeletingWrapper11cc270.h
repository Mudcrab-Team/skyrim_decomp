// Source exposure: binary-analysis
// DeletingWrapper11cc270, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper11cc270 {
public:
    virtual ~DeletingWrapper11cc270();
};
static_assert(sizeof(DeletingWrapper11cc270) == 8, "interface layout");
