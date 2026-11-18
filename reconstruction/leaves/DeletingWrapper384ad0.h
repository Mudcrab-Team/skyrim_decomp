// Source exposure: binary-analysis
// DeletingWrapper384ad0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper384ad0 {
public:
    virtual ~DeletingWrapper384ad0();
};
static_assert(sizeof(DeletingWrapper384ad0) == 8, "interface layout");
