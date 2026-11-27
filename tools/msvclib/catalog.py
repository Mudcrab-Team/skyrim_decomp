#!/usr/bin/env python3
"""Generate instantiation translation units for a library-shape index.

The index holds code shapes of std:: template instances and small CRT-adjacent wrappers compiled with the
project's recipe, so unmatched target functions that are library code can be found by shape. The sources
written here are explicit instantiations of the standard headers the compiler ships; no library source text
is copied, and nothing here is game-derived.

    catalog.py gen --out DIR [--only SUBSTR]     write prelude.h, one .cpp per unit and units.json
"""
import argparse
import json
from pathlib import Path

# Value types: arithmetic, pointers, and plain structs of the sizes game code tends to store by value.
SCALARS = ['char', 'wchar_t', 'short', 'unsigned short', 'int', 'unsigned int', 'long long',
           'unsigned long long', 'float', 'double', 'void*', 'char*', 'const char*']
STRUCTS = ['P8', 'P12', 'P16', 'P24', 'P32', 'P40']
# Composite element types: pairs and nested containers appear as stored elements in game code
NESTED = ['std::pair<int, int>', 'std::pair<float, float>', 'std::pair<void*, int>', 'std::pair<unsigned int, void*>',
          'std::pair<unsigned int, unsigned int>', 'std::shared_ptr<void>', 'std::vector<int>', 'std::vector<void*>',
          'std::vector<std::string>', 'std::list<int>', 'std::map<int, int>', 'std::wstring']
KEYS = ['P8', 'std::wstring', 'int', 'unsigned int', 'unsigned long long', 'void*', 'const char*', 'std::string', 'float']
VALUES = ['std::pair<int, int>', 'std::shared_ptr<void>', 'std::wstring', 'std::list<int>', 'P8', 'P12', 'P32', 'P40',
          'char', 'bool', 'double', 'int', 'unsigned int', 'float', 'unsigned long long', 'void*', 'std::string', 'P16', 'P24',
          'std::vector<int>', 'std::vector<void*>']

PRELUDE = """\
#pragma once
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

struct P8  { int a, b; };
struct P12 { int a, b, c; };
struct P16 { float a, b, c, d; };
struct P24 { void* p; int a, b; void* q; };
struct P32 { float a[8]; };
struct P40 { void* p[5]; };
// memcmp on the object bytes gives the structs a total order without naming any member
#define MSVCLIB_ORDER(T) \\
    inline bool operator<(T const& l, T const& r) { return memcmp(&l, &r, sizeof(T)) < 0; } \\
    inline bool operator==(T const& l, T const& r) { return memcmp(&l, &r, sizeof(T)) == 0; }
"""
PRELUDE = PRELUDE.replace('#include <algorithm>', '#include <string.h>\n#include <algorithm>')
PRELUDE += ''.join(f'MSVCLIB_ORDER({t})\n' for t in STRUCTS)
PRELUDE += '''namespace std {
template<> struct hash<P8> { size_t operator()(P8 const& v) const { return (size_t)v.a * 31u + (size_t)v.b; } };
}
'''

ALGOS = [
    'sort(T*, T*)', 'stable_sort(T*, T*)', 'reverse(T*, T*)', 'unique(T*, T*)', 'rotate(T*, T*, T*)',
    'lower_bound(T*, T*, T const&)', 'upper_bound(T*, T*, T const&)', 'find(T*, T*, T const&)',
    'count(T*, T*, T const&)', 'fill(T*, T*, T const&)', 'min_element(T*, T*)', 'max_element(T*, T*)',
    'make_heap(T*, T*)', 'push_heap(T*, T*)', 'pop_heap(T*, T*)', 'sort_heap(T*, T*)',
    'nth_element(T*, T*, T*)', 'partial_sort(T*, T*, T*)', 'swap_ranges(T*, T*, T*)', 'copy(T*, T*, T*)',
    'copy_backward(T*, T*, T*)', 'remove(T*, T*, T const&)', 'equal(T*, T*, T*)', 'mismatch(T*, T*, T*)',
    'search(T*, T*, T*, T*)', 'find_end(T*, T*, T*, T*)', 'binary_search(T*, T*, T const&)',
    'equal_range(T*, T*, T const&)', 'is_sorted(T*, T*)', 'inplace_merge(T*, T*, T*)',
]
ALGO_TYPES = ['char', 'wchar_t', 'short', 'int', 'unsigned int', 'long long', 'unsigned long long', 'float',
              'double', 'void*', 'P8', 'P16', 'P24']


def safe(text):
    # '*' must stay visible: char and char* would otherwise share a unit name
    return ''.join(c if c.isalnum() else '_' for c in text.replace('*', 'ptr')).strip('_')


def units():
    """Yield (unit name, source text) pairs."""
    cls = [('vector', 'std::vector<{}>'), ('deque', 'std::deque<{}>'), ('list', 'std::list<{}>'),
           ('flist', 'std::forward_list<{}>'), ('set', 'std::set<{}>'), ('uptr', 'std::unique_ptr<{}>'),
           ('sptr', 'std::shared_ptr<{}>'), ('wptr', 'std::weak_ptr<{}>'), ('array4', 'std::array<{}, 4>'),
           ('pqueue', 'std::priority_queue<{}>')]
    for tag, pat in cls:
        for t in SCALARS + STRUCTS + ['std::string'] + NESTED:
            if tag in ('set', 'pqueue') and t in ('std::shared_ptr<void>', 'std::vector<std::string>', 'std::list<int>', 'std::map<int, int>'):
                continue
            body = f'template class {pat.format(t)};\n'
            if tag == 'uptr':
                body = f'template class std::unique_ptr<{t}>;\ntemplate class std::unique_ptr<{t}[]>;\n'
            if tag == 'sptr':
                body += f'template std::shared_ptr<{t}> std::make_shared<{t}>();\n'
            yield f'{tag}_{safe(t)}', body
    for k in KEYS:
        for v in VALUES:
            yield f'map_{safe(k)}_{safe(v)}', f'template class std::map<{k}, {v}>;\n'
            yield f'umap_{safe(k)}_{safe(v)}', f'template class std::unordered_map<{k}, {v}>;\n'
        yield f'uset_{safe(k)}', f'template class std::unordered_set<{k}>;\n'
        yield f'mset_{safe(k)}', f'template class std::multiset<{k}>;\n'
    for sig in ('void()', 'void(int)', 'void(void*)', 'bool(void*)', 'int(int)', 'void(void*, int)', 'bool(int, int)',
                'void(const std::string&)', 'float(float)', 'void(unsigned int, void*)'):
        yield f'function_{safe(sig)}', f'template class std::function<{sig}>;\n'
    for n in (8, 16, 32, 64, 128, 256):
        yield f'bitset_{n}', f'template class std::bitset<{n}>;\n'
    for ch in ('char', 'wchar_t', 'char16_t', 'char32_t'):
        yield f'string_{ch}', f'template class std::basic_string<{ch}>;\n'
    for t in ALGO_TYPES:
        lines = []
        for sig in ALGOS:
            name, args = sig.split('(', 1)
            args = args[:-1].replace('T', t)
            lines.append(f'template auto std::{name}({args});'.replace('template auto', 'template ' + _ret(name, t)))
        yield f'algo_{safe(t)}', '\n'.join(lines) + '\n'
    for t in ALGO_TYPES:
        yield f'vecalgo_{safe(t)}', _vector_algos(t)


def _ret(name, t):
    p = f'{t}*'
    return {
        'sort': 'void', 'stable_sort': 'void', 'reverse': 'void', 'unique': p, 'rotate': p, 'lower_bound': p,
        'upper_bound': p, 'find': p, 'count': 'ptrdiff_t', 'fill': 'void', 'min_element': p, 'max_element': p,
        'make_heap': 'void', 'push_heap': 'void', 'pop_heap': 'void', 'sort_heap': 'void',
        'nth_element': 'void', 'partial_sort': 'void', 'swap_ranges': p, 'copy': p, 'copy_backward': p,
        'remove': p, 'equal': 'bool', 'mismatch': f'std::pair<{p}, {p}>', 'search': p, 'find_end': p,
        'binary_search': 'bool', 'equal_range': f'std::pair<{p}, {p}>', 'is_sorted': 'bool', 'inplace_merge': 'void',
    }[name]


def _vector_algos(t):
    # Instantiated through small functions: the wrappers pin down which container operations the
    # optimiser keeps as separate COMDAT functions (growth, insert, erase, assign).
    return f"""\
using V = std::vector<{t}>;
void w_push(V& v, {t} const& x) {{ v.push_back(x); }}
void w_ins(V& v, V::iterator it, {t} const& x) {{ v.insert(it, x); }}
void w_insn(V& v, V::iterator it, size_t n, {t} const& x) {{ v.insert(it, n, x); }}
void w_era(V& v, V::iterator it) {{ v.erase(it); }}
void w_erar(V& v, V::iterator a, V::iterator b) {{ v.erase(a, b); }}
void w_res(V& v, size_t n) {{ v.resize(n); }}
void w_resv(V& v, size_t n, {t} const& x) {{ v.resize(n, x); }}
void w_asg(V& v, size_t n, {t} const& x) {{ v.assign(n, x); }}
void w_rsv(V& v, size_t n) {{ v.reserve(n); }}
void w_shr(V& v) {{ v.shrink_to_fit(); }}
void w_clr(V& v) {{ v.clear(); }}
void w_cpy(V& a, const V& b) {{ a = b; }}
void w_swp(V& a, V& b) {{ a.swap(b); }}
bool w_eq(const V& a, const V& b) {{ return a == b; }}
bool w_lt(const V& a, const V& b) {{ return a < b; }}
void w_emp(V& v, {t}&& x) {{ v.emplace_back(std::move(x)); }}
"""


def main():
    ap = argparse.ArgumentParser()
    sp = ap.add_subparsers(dest='cmd', required=True)
    g = sp.add_parser('gen')
    g.add_argument('--out', required=True)
    g.add_argument('--only', default='')
    a = ap.parse_args()
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    (out / 'prelude.h').write_text(PRELUDE)
    seen, listing = set(), []
    for name, body in units():
        if a.only and a.only not in name or name in seen:
            continue
        seen.add(name)
        (out / f'{name}.cpp').write_text('#include "prelude.h"\n' + body)
        listing.append(name)
    (out / 'units.json').write_text(json.dumps({'units': [{'source': f'{n}.cpp'} for n in listing]}, indent=1))
    print(len(listing), 'units')


if __name__ == '__main__':
    main()
