#!/usr/bin/env python3
"""Lead statistics: counts by threshold and length band, and name agreement on named functions as a precision proxy."""
import collections, json, pickle, re, sys

def f3name(sym):
    m = re.match(r'^\?(?:\?[0-9A-Z]|)([^@]+)@([^@]+)@@', sym)
    return (m.group(2), m.group(1)) if m else (None, sym)

def load(root):
    A = pickle.load(open(f'{root}/f3sigs.pkl', 'rb'))
    B = pickle.load(open(f'{root}/skysigs.pkl', 'rb'))
    H = pickle.load(open(f'{root}/hits.pkl', 'rb'))
    return A, B, H

def sky_names(table):
    out = {}
    for l in open(table):
        f = json.loads(l)
        if f['kind'] == 'ordinary':
            out[f['rva']] = [n['name'] for n in f['names']]
    return out

def agree(sname, sym):
    cls, meth = f3name(sym)
    if cls is None or meth.startswith('FUN_'):
        return None
    sn = sname.split('::')
    return len(sn) >= 2 and sn[-1] == meth and sn[-2].split('<')[0] == cls
