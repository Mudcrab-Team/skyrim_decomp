// Source exposure: binary-analysis
// DeletingWrapper8e3980, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper8e3980 {
public:
    virtual ~DeletingWrapper8e3980();
};
static_assert(sizeof(DeletingWrapper8e3980) == 8, "interface layout");
