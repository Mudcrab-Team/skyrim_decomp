// Source exposure: binary-analysis
// DeletingWrapper14a1520, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper14a1520 {
public:
    virtual ~DeletingWrapper14a1520();
};
static_assert(sizeof(DeletingWrapper14a1520) == 8, "interface layout");
