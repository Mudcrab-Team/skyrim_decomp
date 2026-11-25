// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0x11cc40 std::vector<>::erase
// CI hash: 0x11cc40 ?erase@?$vector@UP8@@V?$allocator@UP8@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UP8@@@std@@@std@@@2@V?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@UP8@@@std@@@std@@@2@@Z
#include "Std_vecalgo_P8_11cc40.h"

using V = std::vector<P8>;
void w_push(V& v, P8 const& x) { v.push_back(x); }
void w_ins(V& v, V::iterator it, P8 const& x) { v.insert(it, x); }
void w_insn(V& v, V::iterator it, size_t n, P8 const& x) { v.insert(it, n, x); }
void w_era(V& v, V::iterator it) { v.erase(it); }
void w_erar(V& v, V::iterator a, V::iterator b) { v.erase(a, b); }
void w_res(V& v, size_t n) { v.resize(n); }
void w_resv(V& v, size_t n, P8 const& x) { v.resize(n, x); }
void w_asg(V& v, size_t n, P8 const& x) { v.assign(n, x); }
void w_rsv(V& v, size_t n) { v.reserve(n); }
void w_shr(V& v) { v.shrink_to_fit(); }
void w_clr(V& v) { v.clear(); }
void w_cpy(V& a, const V& b) { a = b; }
void w_swp(V& a, V& b) { a.swap(b); }
bool w_eq(const V& a, const V& b) { return a == b; }
bool w_lt(const V& a, const V& b) { return a < b; }
void w_emp(V& v, P8&& x) { v.emplace_back(std::move(x)); }
