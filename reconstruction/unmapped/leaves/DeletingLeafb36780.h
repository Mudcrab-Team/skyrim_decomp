// Source exposure: binary-analysis
// DeletingLeafb36780, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafb36780 {
public:
    virtual ~DeletingLeafb36780() {}
};
static_assert(sizeof(DeletingLeafb36780) == 8, "minimal virtual interface size");
