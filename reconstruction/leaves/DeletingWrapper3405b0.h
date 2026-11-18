// Source exposure: binary-analysis
// DeletingWrapper3405b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper3405b0 {
public:
    virtual ~DeletingWrapper3405b0();
};
static_assert(sizeof(DeletingWrapper3405b0) == 8, "interface layout");
