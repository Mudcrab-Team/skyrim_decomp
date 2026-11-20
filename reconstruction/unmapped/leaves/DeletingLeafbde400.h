// Source exposure: binary-analysis
// DeletingLeafbde400, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafbde400 {
public:
    virtual ~DeletingLeafbde400() {}
};
static_assert(sizeof(DeletingLeafbde400) == 8, "minimal virtual interface size");
