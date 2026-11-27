// Source exposure: binary-analysis
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of standard templates, compared members listed below
// Adapted bodies: none
// 0x15a72e4 std::_Swap_ranges_unchecked<>
// CI hash: 0x15a72e4 ??$_Swap_ranges_unchecked@D$0A@@std@@YAPEADQEAD00@Z
#include "Std_algo_char.h"

template void std::sort(char*, char*);
template void std::stable_sort(char*, char*);
template void std::reverse(char*, char*);
template char* std::unique(char*, char*);
template char* std::rotate(char*, char*, char*);
template char* std::lower_bound(char*, char*, char const&);
template char* std::upper_bound(char*, char*, char const&);
template char* std::find(char*, char*, char const&);
template ptrdiff_t std::count(char*, char*, char const&);
template void std::fill(char*, char*, char const&);
template char* std::min_element(char*, char*);
template char* std::max_element(char*, char*);
template void std::make_heap(char*, char*);
template void std::push_heap(char*, char*);
template void std::pop_heap(char*, char*);
template void std::sort_heap(char*, char*);
template void std::nth_element(char*, char*, char*);
template void std::partial_sort(char*, char*, char*);
template char* std::swap_ranges(char*, char*, char*);
template char* std::copy(char*, char*, char*);
template char* std::copy_backward(char*, char*, char*);
template char* std::remove(char*, char*, char const&);
template bool std::equal(char*, char*, char*);
template std::pair<char*, char*> std::mismatch(char*, char*, char*);
template char* std::search(char*, char*, char*, char*);
template char* std::find_end(char*, char*, char*, char*);
template bool std::binary_search(char*, char*, char const&);
template std::pair<char*, char*> std::equal_range(char*, char*, char const&);
template bool std::is_sorted(char*, char*);
template void std::inplace_merge(char*, char*, char*);
