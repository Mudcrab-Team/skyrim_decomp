// Source exposure: binary-analysis
// DeletingWrapper14c8af0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper14c8af0 {
public:
    virtual ~DeletingWrapper14c8af0();
};
static_assert(sizeof(DeletingWrapper14c8af0) == 8, "interface layout");
