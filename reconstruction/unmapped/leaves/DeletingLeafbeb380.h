// Source exposure: binary-analysis
// DeletingLeafbeb380, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbeb380 {
public:
    virtual ~DeletingLeafbeb380() {}
};
static_assert(sizeof(DeletingLeafbeb380) == 8, "minimal virtual interface size");
