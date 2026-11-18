// Source exposure: binary-analysis
// DeletingLeafcebde0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafcebde0 {
public:
    virtual ~DeletingLeafcebde0() {}
};
static_assert(sizeof(DeletingLeafcebde0) == 8, "minimal virtual interface size");
