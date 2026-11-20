// Source exposure: binary-analysis
// DeletingWrapper11cc230, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper11cc230 {
public:
    virtual ~DeletingWrapper11cc230();
};
static_assert(sizeof(DeletingWrapper11cc230) == 8, "interface layout");
