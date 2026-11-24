#!/usr/bin/env python3
"""Controlled spelling experiments for the matching cookbook, compiled on the Windows runner.

Each experiment is a claim of the form "spelling X gives codegen Y, spelling Z does not", a few toy
variants of one function and an `expect` predicate over features of the compiled variants (written from
the cookbook's wording before the first compile). Toy sources only; nothing game-derived.

    lab_experiments.py run --out DIR [--only r16,r29]     compile and judge
    lab_experiments.py list
"""
import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lab_compile  # noqa: E402


def count(ins, rx):
    return sum(1 for i in ins if re.search(rx, i))


def has(ins, rx):
    return count(ins, rx) > 0


def pick(funcs, name='fn'):
    """The function under test: exact symbol, else the first symbol that contains the name."""
    if name in funcs:
        return funcs[name]
    for sym, ins in funcs.items():
        if name in sym:
            return ins
    return []


def syms(funcs):
    return sorted(funcs)


class Exp:
    def __init__(self, ident, rules, claim, variants, expect, flags=None, compile_fail=()):
        self.ident, self.rules, self.claim = ident, rules, claim
        self.variants, self.expect, self.flags = variants, expect, flags or {}
        self.compile_fail = compile_fail


E = []


def add(*a, **k):
    E.append(Exp(*a, **k))


PRE = 'extern "C" { void use(int); void sink(void*); int next(); }\n'

# rule 1: a reloaded member keeps its null test after a dereference; a cached local does not
add('r01-reload', [1], 'a member re-read after a call keeps the null test; a cached local that was dereferenced loses it', {
    'cached': PRE + 'struct O{int v;}; struct E{O* o;};\nextern "C" int fn(E* e){ O* o=e->o; use(o->v); if(o) return 1; return 0; }\n',
    'reload': PRE + 'struct O{int v;}; struct E{O* o;};\nextern "C" int fn(E* e){ use(e->o->v); if(e->o) return 1; return 0; }\n',
}, lambda R: not has(R['cached'], r'^(test|cmp|setne)') and has(R['reload'], r'^(test|cmp)'))

# rule 3: helper called in condition and body
add('r03-helper-twice', [3], 'calling a null-checking helper in both the loop condition and the body differs from one cached call', {
    'twice': PRE + 'struct N{N* parent;}; inline N* Root(N* p){ return p ? p->parent : nullptr; }\nextern "C" N* fn(N* p){ while(Root(p)) p=Root(p); return p; }\n',
    'cached': PRE + 'struct N{N* parent;}; inline N* Root(N* p){ return p ? p->parent : nullptr; }\nextern "C" N* fn(N* p){ N* r; while((r=Root(p))) p=r; return p; }\n',
}, lambda R: R['twice'] != R['cached'])

# rule 6: switch operand width
add('r06-switch-width', [6], 'switching on a byte enum and on a uint32 cast of it allocate registers differently', {
    'byte': PRE + 'enum K:unsigned char{a,b,c,d}; struct S{K k;};\nextern "C" int fn(S* s){ switch(s->k){case a:use(1);return 1;case b:use(2);return 2;case c:return 3;default:return 0;} }\n',
    'u32': PRE + 'enum K:unsigned char{a,b,c,d}; struct S{K k;};\nextern "C" int fn(S* s){ switch((unsigned)s->k){case a:use(1);return 1;case b:use(2);return 2;case c:return 3;default:return 0;} }\n',
}, lambda R: R['byte'] != R['u32'])

# rule 9: uninitialised local
add('r09-uninit-local', [9], 'dropping the initialiser of a local filled by a callee removes a zero store', {
    'init': PRE + 'extern "C" void fill(char**); extern "C" void rel(char*);\nextern "C" void fn(){ char* m=nullptr; fill(&m); rel(m); }\n',
    'bare': PRE + 'extern "C" void fill(char**); extern "C" void rel(char*);\nextern "C" void fn(){ char* m; fill(&m); rel(m); }\n',
}, lambda R: len(R['bare']) < len(R['init']))

# rules 10, 14, 18, 25: deleting destructors
add('r10-class-delete', [10], 'with a class-scope operator delete and a non-virtual destructor, delete p is destructor then operator delete; a virtual destructor makes it one deleting-destructor call with edx=1', {
    'plain': PRE + 'struct X{ ~X(); int a; };\nextern "C" void fn(X* p){ delete p; }\n',
    'ownop': PRE + 'struct X{ ~X(); int a; static void operator delete(void*, size_t); };\nextern "C" void fn(X* p){ delete p; }\n',
    'virt': PRE + 'struct X{ virtual ~X(); int a; static void operator delete(void*, size_t); };\nextern "C" void fn(X* p){ delete p; }\n',
}, lambda R: has(R['virt'], r'mov\s+edx, 1') and has(R['virt'], r'jmp') and not has(R['ownop'], r'mov\s+edx, 1') and has(R['ownop'], r'call\s+\?\?3'))

add('r14-deleting-dtor', [14], '??_G is emitted only beside the vftable: a unit that never constructs the class has none', {
    'noctor': PRE + 'struct X{ virtual ~X(){} virtual void f(); int a; };\nextern "C" void fn(X* p){ p->f(); }\n',
    'ctor': PRE + 'struct X{ virtual ~X(){} virtual void f(); int a; X():a(0){} };\nextern "C" X* fn(){ return new X(); }\n',
}, lambda R: not any('??_G' in s for s in R['noctor_syms']) and any('??_G' in s for s in R['ctor_syms']))

add('r18-dtor-outofline', [18], 'an undefined out-of-line ~X makes ??_G call it instead of inlining the vptr store', {
    'inline': PRE + 'struct X{ virtual ~X(){} virtual void f(); int a; X():a(0){} };\nextern "C" X* fn(){ return new X(); }\n',
    'outofline': PRE + 'struct X{ virtual ~X(); virtual void f(); int a; X():a(0){} };\nextern "C" X* fn(){ return new X(); }\n',
}, lambda R: any(re.search(r'call\s+\?\?1X', i) for i in pick(R['outofline_all'], '??_G'))
          and not any(re.search(r'call\s+\?\?1X', i) for i in pick(R['inline_all'], '??_G')))

add('r25-adjustor-thunk', [25], 'a ??_E ... W7 thunk appears only when the class has a secondary base and its vftable is emitted', {
    'single': PRE + 'struct A{ virtual ~A(){} int a; }; struct X: A{ ~X(){} X(){} int b; };\nextern "C" X* fn(){ return new X(); }\n',
    'multi': PRE + 'struct A{ virtual ~A(){} int a; }; struct C{ virtual ~C(){} int c; }; struct X: A, C{ ~X(){} X(){} int b; };\nextern "C" X* fn(){ return new X(); }\n',
}, lambda R: not any('@@W' in s for s in R['single_syms']) and any('??_E' in s and '@@W' in s for s in R['multi_syms']))

# rule 11
add('r11-vslot', [11], 'a call through the Nth virtual reads offset 8*(N-1) of the vftable', {
    'slot3': PRE + 'struct X{ virtual void a(); virtual void b(); virtual int c(); };\nextern "C" int fn(X* p){ return p->c(); }\n',
    'slot1': PRE + 'struct X{ virtual int c(); virtual void a(); virtual void b(); };\nextern "C" int fn(X* p){ return p->c(); }\n',
}, lambda R: has(R['slot3'], r'\[rax\+16\]') and not has(R['slot1'], r'\[rax\+\d+\]') or (has(R['slot3'], r'\[rax\+16\]') and has(R['slot1'], r'rax\]|\[rax\]|jmp\s+QWORD PTR \[rax\]')))

# rule 15
add('r15-find-out', [15], 'a bool Find with an out-parameter writes the out only on a hit; a value-returning lookup stores on both paths', {
    'value': PRE + 'struct T{int k[4]; int v[4];};\nstatic int Get(const T& t,int key){ for(int i=0;i<4;++i) if(t.k[i]==key) return t.v[i]; return 0; }\nextern "C" void fn(T* t,int key,int* out){ *out = Get(*t,key); }\n',
    'bool': PRE + 'struct T{int k[4]; int v[4];};\nstatic bool Find(const T& t,int key,int& o){ for(int i=0;i<4;++i) if(t.k[i]==key){ o=t.v[i]; return true;} return false; }\nextern "C" void fn(T* t,int key,int* out){ int v=*out; if(Find(*t,key,v)) *out=v; }\n',
}, lambda R: R['value'] != R['bool'])

# rule 16
H16 = PRE + 'struct F{ int pad; unsigned flags; };\n'
add('r16-bit-helper', [16], 'direct bit spellings of a flag member test in memory; only a by-value bit-index helper keeps load, shr, test al,1', {
    'mask': H16 + 'extern "C" void fn(F* f){ if(f->flags & 8) use(1); }\n',
    'shift': H16 + 'extern "C" void fn(F* f){ if((f->flags >> 3) & 1) use(1); }\n',
    'bitfield': PRE + 'struct F{ int pad; unsigned a:3; unsigned bit:1; };\nextern "C" void fn(F* f){ if(f->bit) use(1); }\n',
    'helper': H16 + 'inline bool TestBit(unsigned fl,unsigned b){ return ((fl>>b)&1)!=0; }\nextern "C" void fn(F* f){ if(TestBit(f->flags,3)) use(1); }\n',
}, lambda R: not any(has(R[v], r'^shr') for v in ('mask', 'shift', 'bitfield')) and has(R['helper'], r'^shr') and has(R['helper'], r'test\s+al, 1'))

# rule 17
add('r17-static-assert', [17], 'a message-less static_assert is a compile error without /std:c++17', {
    'bare': PRE + 'struct X{int a;}; static_assert(sizeof(X)==4);\nextern "C" int fn(X* x){ return x->a; }\n',
    'msg': PRE + 'struct X{int a;}; static_assert(sizeof(X)==4,"size");\nextern "C" int fn(X* x){ return x->a; }\n',
}, lambda R: R['bare_rc'] != 0 and R['msg_rc'] == 0)

# rule 21
add('r21-tls', [21], 'a __declspec(thread) read goes through _tls_index and gs:[0x58]; an ordinary global does not', {
    'tls': PRE + 'extern __declspec(thread) int tag;\nextern "C" int fn(){ return tag + 1; }\n',
    'global': PRE + 'extern int tag;\nextern "C" int fn(){ return tag + 1; }\n',
}, lambda R: has(R['tls'], r'_tls_index') and has(R['tls'], r'gs:88') and not has(R['global'], r'_tls_index'))

# rule 22
add('r22-small-slot', [22], 'a small out-parameter local sits in a lower slot than an 8-byte key regardless of declaration order', {
    'bool_first': PRE + 'extern "C" void put(unsigned long long*, bool*);\nextern "C" void fn(){ bool ins; unsigned long long key=1; put(&key,&ins); }\n',
    'bool_second': PRE + 'extern "C" void put(unsigned long long*, bool*);\nextern "C" void fn(){ unsigned long long key=1; bool ins; put(&key,&ins); }\n',
    'ptr_out': PRE + 'extern "C" void put(unsigned long long*, void**);\nextern "C" void fn(){ unsigned long long key=1; void* ins; put(&key,&ins); }\n',
}, lambda R: R['bool_first'] == R['bool_second'] and R['bool_first'] != R['ptr_out'])

# rule 23
add('r23-read-after-test', [23], 'a member cached before a null test is loaded before it; reading inside the test loads after', {
    'cached': PRE + 'struct E{int z; int v;};\nextern "C" int fn(int* r, E* e){ int c=e->v; if(!*r && e){ return c; } return 0; }\n',
    'after': PRE + 'struct E{int z; int v;};\nextern "C" int fn(int* r, E* e){ if(!*r && e){ return e->v; } return 0; }\n',
}, lambda R: R['cached'] != R['after'])

# rule 24
add('r24-copy3', [24], 'two memcpy of 2 and 1 bytes from one source pointer give a word and a byte move; three byte assignments index off the base', {
    'memcpy': '#include <string.h>\n' + PRE + 'struct Id{ unsigned char a,b,c; };\nextern "C" void fn(Id* o,const unsigned char* base,int pos){ const unsigned char* s=base+pos; memcpy(o,s,2); memcpy(&o->c,s+2,1); }\n',
    'bytes': PRE + 'struct Id{ unsigned char a,b,c; };\nextern "C" void fn(Id* o,const unsigned char* base,int pos){ o->a=base[pos]; o->b=base[pos+1]; o->c=base[pos+2]; }\n',
}, lambda R: has(R['memcpy'], r'movzx\s+\w+, WORD PTR') and not has(R['bytes'], r'WORD PTR'))

# rule 29
add('r29-named-count', [29], 'a named decremented count reserves the first home slot; the one-expression release saves into it', {
    'named': PRE + '#include <intrin.h>\nstruct R{ virtual void D(); long rc; };\nextern "C" void fn(R* a,R* b,R* c){ unsigned n; n=_InterlockedDecrement(&a->rc); if(n==0) a->D(); n=_InterlockedDecrement(&b->rc); if(n==0) b->D(); n=_InterlockedDecrement(&c->rc); if(n==0) c->D(); }\n',
    'expr': PRE + '#include <intrin.h>\nstruct R{ virtual void D(); long rc; };\nextern "C" void fn(R* a,R* b,R* c){ if(_InterlockedDecrement(&a->rc)==0) a->D(); if(_InterlockedDecrement(&b->rc)==0) b->D(); if(_InterlockedDecrement(&c->rc)==0) c->D(); }\n',
}, lambda R: R['named'] != R['expr'])

def this_and_minus1(ins):
    """Family letters of the callee-saved register that receives rcx and of the one that receives -1."""
    fam = {'rbx': 'b', 'ebx': 'b', 'rdi': 'd', 'edi': 'd', 'rsi': 's', 'esi': 's', 'rbp': 'p', 'ebp': 'p'}
    this = minus = None
    for i in ins:
        m = re.match(r'mov\s+(r\w+), rcx$', i)
        if m and this is None:
            this = fam.get(m.group(1))
        m = re.match(r'mov\s+(e\w+), -1$', i)
        if m and minus is None:
            minus = fam.get(m.group(1))
    return this, minus


# rule 30
SP = ('struct R{ long rc; void Inc(){ _InterlockedIncrement(&rc); } void Dec(); };\n'
      'template<class T> struct P{ T* _ptr; %s '
      'P& operator=(T* p){ if(_ptr!=p){ if(p) p->Inc(); T* old=_ptr; _ptr=p; if(old){ long n=_InterlockedDecrement(&old->rc); if(n==0) old->Dec(); } } return *this; } };\n')
add('r30-null-assign', [30], 'clearing through the generic raw-pointer assignment gives a different register shape from a nullptr_t overload', {
    'raw': '#include <intrin.h>\n' + PRE + SP % '' + 'struct M{ P<R> a,b,c; };\nextern "C" void fn(M* m){ m->a=(R*)nullptr; m->b=(R*)nullptr; m->c=(R*)nullptr; }\n',
    'nullt': '#include <intrin.h>\n' + PRE + SP % 'P& operator=(decltype(nullptr)){ if(_ptr){ T* old=_ptr; _ptr=nullptr; long n=_InterlockedDecrement(&old->rc); if(n==0) old->Dec(); } return *this; }' + 'struct M{ P<R> a,b,c; };\nextern "C" void fn(M* m){ m->a=nullptr; m->b=nullptr; m->c=nullptr; }\n',
}, lambda R: this_and_minus1(R['raw']) == tuple(reversed(this_and_minus1(R['nullt']))) and None not in this_and_minus1(R['raw']))

# rule 31
add('r31-default-ctor', [31], 'member{} on an aggregate smart pointer lowers differently from a pointer with its own default constructor', {
    'aggregate': '#include <new>\n' + PRE + 'struct P{ void* p; }; struct M{ virtual void f(); P a; P b; float x; float y; M():a{},b{},x(1.0f),y(1.0f){} };\nextern "C" void fn(M* m){ ::new((void*)m) M(); }\n',
    'ctor': '#include <new>\n' + PRE + 'struct P{ void* p{nullptr}; }; struct M{ virtual void f(); P a; P b; float x; float y; M():x(1.0f),y(1.0f){} };\nextern "C" void fn(M* m){ ::new((void*)m) M(); }\n',
}, lambda R: R['aggregate'] != R['ctor'])

# rule 32
add('r32-imm16', [32], 'two adjacent byte members clear with one immediate word store; a uint16 member clears from a zeroed register', {
    'bytes': PRE + 'struct S{ int a; unsigned char x,y; int b; };\nextern "C" void fn(S* s){ s->a=1; s->x=0; s->y=0; s->b=2; }\n',
    'u16': PRE + 'struct S{ int a; unsigned short xy; int b; };\nextern "C" void fn(S* s){ s->a=1; s->xy=0; s->b=2; }\n',
}, lambda R: has(R['bytes'], r'WORD PTR \[rcx\+\d+\], 0') and not has(R['u16'], r'WORD PTR \[rcx\+\d+\], 0'))

# rule 33
add('r33-byvalue-return', [33], 'a by-value return hands the next call rax; a constructor-like call re-passes the temporary address', {
    'ctor': PRE + 'struct S{ void* p; void* q; void* r; }; struct O{ S s; }; extern "C" void Init(S*, const char*); extern "C" void Take(void*, S*);\nextern "C" void fn(O* o,const char* n){ Init(&o->s,n); Take(o,&o->s); }\n',
    'byval': PRE + 'struct S{ void* p; void* q; void* r; }; struct O{ S s; }; extern "C" S Make(const char*); extern "C" void Take(void*, S*);\nextern "C" void fn(O* o,const char* n){ o->s=Make(n); Take(o,&o->s); }\n',
}, lambda R: has(R['byval'], r'mov\s+rdx, rax') and not has(R['ctor'], r'mov\s+rdx, rax'))

# rule 34
add('r34-one-result', [34], 'one result local and one return versus early returns give different exits', {
    'early': PRE + 'struct O{int t; O* n;};\nextern "C" bool fn(O* o,int st){ if(st==1) return true; if(o && o->t==2) return true; return false; }\n',
    'result': PRE + 'struct O{int t; O* n;};\nextern "C" bool fn(O* o,int st){ bool r=false; if(st==1){ r=true; } else if(o && o->t==2){ r=true; } return r; }\n',
}, lambda R: R['early'] != R['result'])

# rule 35
add('r35-found-in-cond', [35], 'a loop with the found result in its condition differs from an early-return loop', {
    'early': PRE + 'struct E{int id; int snd;};\nextern "C" int fn(E* e,int n,int id){ for(int i=0;i<n;++i) if(e[i].id==id) return e[i].snd; return 0; }\n',
    'cond': PRE + 'struct E{int id; int snd;};\nextern "C" int fn(E* e,int n,int id){ int s=0; for(int i=0; !s && i<n; ++i){ if(e[i].id==id) s=e[i].snd; } return s; }\n',
}, lambda R: R['early'] != R['cond'])

# rule 36
add('r36-list-walk', [36, 'A'], 'taking the element reference, advancing, then calling keeps the element address; call-then-advance does not', {
    'after': PRE + 'struct V{int a;}; struct N{ V v; N* next; }; extern "C" void Visit(V&,int);\nextern "C" void fn(N* n,int c){ while(n){ Visit(n->v,c); n=n->next; } }\n',
    'ref': PRE + 'struct V{int a;}; struct N{ V v; N* next; }; extern "C" void Visit(V&,int);\nextern "C" void fn(N* n,int c){ while(n){ V& i=n->v; n=n->next; Visit(i,c); } }\n',
}, lambda R: R['after'] != R['ref'])

# rule 37
add('r37-flag-edit', [37], 'a volatile flag word edited in one expression is loaded and stored once; the non-volatile read-modify-write sequence differs', {
    'plain': PRE + 'struct S{ unsigned flags; };\nextern "C" void fn(S* s){ s->flags &= ~4u; s->flags |= 2u; }\n',
    'volatile': PRE + 'struct S{ volatile unsigned flags; };\nextern "C" void fn(S* s){ s->flags = (s->flags & ~4u) | 2u; }\n',
}, lambda R: count(R['volatile'], r'PTR \[rcx\]') <= 2 and R['plain'] != R['volatile'])

# rule 38
add('r38-compare-width', [38], 'a 16-bit cast of a masked value compares differently from a helper taking mask and value', {
    'cast': PRE + 'struct S{ unsigned flags; };\nextern "C" bool fn(S* s){ return static_cast<unsigned short>(s->flags & 0x300) == 0x100; }\n',
    'plain': PRE + 'struct S{ unsigned flags; };\nextern "C" bool fn(S* s){ return (s->flags & 0x300) == 0x100; }\n',
}, lambda R: R['cast'] != R['plain'])

# rule 39
add('r39-delete-local', [39], 'deleting through a local copy removes the null test before operator delete', {
    'member': PRE + 'struct O{ long rc; ~O(); void Dec(); }; struct H{ O* p; };\nextern "C" int fn(H* h){ if(h->p && h->p->rc==1) delete h->p; return 0; }\n',
    'local': PRE + 'struct O{ long rc; ~O(); void Dec(); }; struct H{ O* p; };\nextern "C" int fn(H* h){ O* o=h->p; if(o && o->rc==1) delete o; return 0; }\n',
}, lambda R: count(R['local'], r'^test') < count(R['member'], r'^test'))

# rule 47
add('r47-null-first-ternary', [47], 'p == nullptr ? fallback : p gives another jump shape from p ? p : fallback', {
    'a': PRE + 'struct C{int z;};\nextern "C" C* fn(C* p,C* f){ return p ? p : f; }\n',
    'b': PRE + 'struct C{int z;};\nextern "C" C* fn(C* p,C* f){ return p == nullptr ? f : p; }\n',
}, lambda R: R['a'] != R['b'])

# rule 48
add('r48-fpfast', [48], 'under /fp:fast a compare of a float with zero loses its parity branch, fabsf is not widened', {
    'precise': PRE + '#include <math.h>\nextern "C" float fn(float d,float x){ if(d!=0.0f) return fabsf(x)*d; return 0.0f; }\n',
    'fast': PRE + '#include <math.h>\nextern "C" float fn(float d,float x){ if(d!=0.0f) return fabsf(x)*d; return 0.0f; }\n',
}, lambda R: has(R['precise'], r'^jp') and not has(R['fast'], r'^jp'), flags={'fast': ['/fp:fast']})

# rule 49
add('r49-param-local', [49], 'assigning a constant into a parameter and passing its address uses the incoming home slot instead of a new local', {
    'local': PRE + 'extern "C" void io(void*,void*,unsigned,unsigned*,int);\nextern "C" void fn(void* t,void* b,unsigned count){ unsigned total=count*4; unsigned four=4; io(t,b,total,&four,1); }\n',
    'param': PRE + 'extern "C" void io(void*,void*,unsigned,unsigned*,int);\nextern "C" void fn(void* t,void* b,unsigned count){ const unsigned total=count*4; count=4; io(t,b,total,&count,1); }\n',
}, lambda R: R['local'] != R['param'] and len(R['param']) <= len(R['local']))

# rule 50
add('r50-struct-assign', [50], 'a plain struct assignment of 0x34 bytes folds the tail scalars into wide moves; a memcpy of the head plus scalars does not', {
    'assign': '#include <string.h>\n' + PRE + 'struct T{ float h[8]; int a; int b; int c; };\nextern "C" void fn(T* d,const T* s){ *d=*s; }\n',
    'split': '#include <string.h>\n' + PRE + 'struct T{ float h[8]; int a; int b; int c; };\nextern "C" void fn(T* d,const T* s){ memcpy(d->h,s->h,32); d->a=s->a; d->b=s->b; d->c=s->c; }\n',
}, lambda R: R['assign'] != R['split'])

# rule 51
add('r51-m128-rows', [51], '__m128 rows copy as aligned vector moves; float rows copy as unaligned ones', {
    'm128': '#include <intrin.h>\n' + PRE + 'struct M{ __m128 r[3]; };\nextern "C" void fn(M* d,const M* s){ *d=*s; }\n',
    'floats': PRE + 'struct M{ float r[12]; };\nextern "C" void fn(M* d,const M* s){ *d=*s; }\n',
}, lambda R: has(R['m128'], r'movaps') and not has(R['floats'], r'movaps'))

# rule 52
add('r52-bitfields', [52], 'a && !b over adjacent bits folds to one mask test; byte bit-fields keep two tests', {
    'mask': PRE + 'struct F{ unsigned flags; };\nextern "C" bool fn(F* f){ return (f->flags & 1) && !(f->flags & 2); }\n',
    'bits': PRE + 'struct F{ unsigned char a:1; unsigned char b:1; };\nextern "C" bool fn(F* f){ return f->a && !f->b; }\n',
}, lambda R: count(R['bits'], r'^test') > count(R['mask'], r'^test') or R['bits'] != R['mask'])

# rule 53
add('r53-clamp', [53], 'reading both members first changes the load order of a double clamp', {
    'direct': PRE + 'struct C{ float lo,hi; };\nextern "C" void fn(C* p,float v){ p->lo = p->lo < v ? v : p->lo; p->hi = v < p->hi ? p->hi : v; }\n',
    'both': PRE + 'struct C{ float lo,hi; };\nextern "C" void fn(C* p,float v){ float b=p->hi; float a=p->lo; p->lo=(a<v)?v:a; p->hi=(v<b)?b:v; }\n',
}, lambda R: R['direct'] != R['both'])

# rule 54
add('r54-else-null', [54], 'else out = nullptr then testing the out differs from an early return on null', {
    'early': PRE + 'struct S{ void* m; };\nextern "C" bool fn(S* s,void** out){ if(!s) return false; *out=s->m; return *out!=nullptr; }\n',
    'else': PRE + 'struct S{ void* m; };\nextern "C" bool fn(S* s,void** out){ if(s) *out=s->m; else *out=nullptr; return *out!=nullptr; }\n',
}, lambda R: R['early'] != R['else'])

# rule 59
add('r59-remainder-helper', [59], 'a byte-truncating remainder helper keeps two bit tests of one snapshot in separate branches', {
    'mask': PRE + 'struct F{ unsigned f; void* p; };\nextern "C" int fn(F* x){ unsigned s=x->f; if(s&4){ if(s&16) use(1); } return x->p!=nullptr; }\n',
    'rem': PRE + 'inline bool B(unsigned s,unsigned b){ return static_cast<unsigned char>(s>>b)%2==1; }\nstruct F{ unsigned f; void* p; };\nextern "C" int fn(F* x){ unsigned s=x->f; if(B(s,2)){ if(B(s,4)) use(1); } return x->p!=nullptr; }\n',
}, lambda R: R['mask'] != R['rem'])

# rule 60
add('r60-byvalue-ctor', [60], 'a by-value 16-byte constructor parameter is loaded before the vtable store', {
    'ref': PRE + 'struct Q{ float v[4]; }; struct B{ virtual void f(); int a; B(); }; struct D: B{ Q q; D(const Q& x); virtual void f(); };\nD::D(const Q& x):q(x){}\n',
    'val': PRE + 'struct Q{ float v[4]; }; struct B{ virtual void f(); int a; B(); }; struct D: B{ Q q; D(Q x); virtual void f(); };\nD::D(Q x):q(x){}\n',
}, lambda R: R['ref_all'] != R['val_all'])

# rule 62/63
add('r63-memset-member', [63], 'memset of a returned member stores a zero register; assignment stores an immediate', {
    'assign': '#include <string.h>\n' + PRE + 'struct S{ int a; unsigned long long m; };\nextern "C" unsigned long long fn(S* s){ s->a=1; s->m=0; return s->m; }\n',
    'memset': '#include <string.h>\n' + PRE + 'struct S{ int a; unsigned long long m; };\nextern "C" unsigned long long fn(S* s){ s->a=1; memset(&s->m,0,sizeof(s->m)); return s->m; }\n',
}, lambda R: R['assign'] != R['memset'])

# rule 64
add('r64-moving-out', [64], 'stores through a moving output pointer schedule differently from indexed stores', {
    'index': PRE + 'extern "C" void fn(void** o,void* a,void* b,void* c){ o[0]=a; o[1]=b; o[2]=c; }\n',
    'moving': PRE + 'extern "C" void* fn(void** o,void* a,void* b,void* c){ void** s=o; *o++=a; *o++=b; *o++=c; return s; }\n',
}, lambda R: [i for i in R['moving'] if i != 'mov rax, rcx'] != R['index'])

# rule 66
add('r66-uint32-return', [66], 'returning the compare as uint32 builds the result in a full register', {
    'bool': PRE + 'struct S{ unsigned char f; };\nextern "C" bool fn(S* s){ return s->f == 3; }\n',
    'u32': PRE + 'struct S{ unsigned char f; };\nextern "C" unsigned fn(S* s){ return s->f == 3; }\n',
}, lambda R: R['bool'] != R['u32'])

# unsolved: rule 46 tail call, rule 20 counted loop, rule 13 UnwindHelp
add('u46-tail-call', ['46'], 'a call in return position is a tail call (jmp) unless a destructor-bearing local or a different type forces a call', {
    'tail': PRE + 'struct S{ void* c; }; extern "C" void* get(void*);\nextern "C" void* fn(S* s){ return get(s->c); }\n',
    'notail': PRE + 'struct S{ void* c; }; extern "C" void* get(void*);\nextern "C" void* fn(S* s){ void* r=get(s->c); return r; }\n',
}, lambda R: has(R['tail'], r'^jmp\s+get') and R['tail'] == R['notail'])

add('u20-pointer-loop', ['20'], 'a raw pointer loop (it != end) compiles to a counted loop in this recipe', {
    'derived': PRE + 'struct E{ void* a; void* b; void* c; }; struct V{ E* items; unsigned n; };\nextern "C" void fn(V* v){ for(E* it=v->items, *end=v->items+v->n; it!=end; ++it) sink(it->a); }\n',
    'ptr': PRE + 'struct E{ void* a; void* b; };\nextern "C" void fn(E* it,E* end){ for(; it!=end; ++it) sink(it->a); }\n',
    'idx': PRE + 'struct E{ void* a; void* b; };\nextern "C" void fn(E* b,unsigned n){ for(unsigned i=0;i<n;++i) sink(b[i].a); }\n',
}, lambda R: has(R['ptr'], r'^(shr|cmova)') or has(R['ptr'], r'^sub\s+r\w+, 1$'))


# rule 7
add('r07-shared-constant', [7], 'putting the value-producing branch in a helper shares one -1 for compare and result', {
    'inline': PRE + 'extern int table[10];\nextern "C" int fn(int slot,int kind){ if(slot==-1) return -1; if(slot<10) return table[slot]; return -1; }\n',
    'helper': PRE + 'extern int table[10];\nstatic int Mask(int slot){ int m=-1; if(slot!=-1 && slot<10) m=table[slot]; return m; }\nextern "C" int fn(int slot,int kind){ return Mask(slot); }\n',
}, lambda R: R['inline'] != R['helper'] and count(R['helper'], r'-1') < count(R['inline'], r'-1'))

# rule 13: UnwindHelp store with no handler
GUARD = 'struct G{ int* v; int s; G(int* p); ~G(); };\n'
add('u13-unwindhelp', ['13'], 'a destructor-bearing local around a throwing call keeps a handler; nothrow variants either drop the -2 store or keep the handler', {
    'throwing': PRE + GUARD + 'int may();\nint fn(int* p){ G g(p); return may(); }\n',
    'throw0': PRE + GUARD + 'int may() throw();\nint fn(int* p){ G g(p); return may(); }\n',
    'noexcept': PRE + GUARD + 'int may() noexcept;\nint fn(int* p){ G g(p); return may(); }\n',
    'early': PRE + GUARD + 'int may() noexcept;\nint fn(int* p,int q){ if(q==0) return 0; G g(p); return may(); }\n',
}, lambda R: has(R['throwing_text'], r'__CxxFrameHandler3') and has(R['throwing'], r'(, -2)$')
          and not any(has(R[v], r', -2$') and not has(R[v + '_text'], r'__CxxFrameHandler3') for v in ('throw0', 'noexcept', 'early')))

# rule 20 probe: which loop spellings are counted (a trip count in a register) and which stay pointer loops
L20 = PRE + 'struct E{ void* a; void* b; void* c; }; struct V{ E* b; E* e; unsigned n; E* items; E* begin(){return b;} E* end(){return e;} };\n'
add('u20-loop-spellings', ['20'], 'a raw pointer loop and a range-for over begin()/end() both compile to the counted form (lea, shr, cmova trip count)', {
    'index': L20 + 'void fn(V* v){ for(unsigned i=0;i<v->n;++i) sink(v->items[i].a); }\n',
    'ptr_ne': L20 + 'void fn(V* v){ for(E* it=v->b; it!=v->e; ++it) sink(it->a); }\n',
    'ptr_lt': L20 + 'void fn(V* v){ for(E* it=v->b; it<v->e; ++it) sink(it->a); }\n',
    'range_for': L20 + 'void fn(V* v){ for(E& x : *v) sink(x.a); }\n',
    'locals': L20 + 'void fn(V* v){ E* it=v->b; E* end=v->e; for(; it!=end; ++it) sink(it->a); }\n',
    'do_while': L20 + 'void fn(V* v){ E* it=v->b; E* end=v->e; if(it==end) return; do { sink(it->a); ++it; } while(it!=end); }\n',
    'count_diff': L20 + 'void fn(V* v){ unsigned n=(unsigned)(v->e - v->b); for(E* it=v->b; n; --n, ++it) sink(it->a); }\n',
}, lambda R: any(has(R[v], r'^(shr|cmova)') for v in ('ptr_ne', 'ptr_lt', 'range_for', 'locals', 'do_while')))

# rule 13 probe: do other flags give the UnwindHelp store without a handler
G13 = PRE + GUARD + 'int may() noexcept;\nint fn(int* p,int q){ if(q==0) return 0; G g(p); return may(); }\n'
add('u13-flag-sweep', ['13'], 'no compiler flag in a short sweep gives the -2 store without a handler', {
    'base': G13, 'eha': G13, 'ehs': G13, 'o1': G13, 'osz': G13, 'gl': G13, 'gz': G13, 'ehsc_throw': G13.replace('noexcept', 'throw()'),
}, lambda R: not any(has(R[v], r', -2$') and not has(R[v + '_text'], r'__CxxFrameHandler3') for v in ('base', 'eha', 'ehs', 'o1', 'osz', 'gl', 'gz', 'ehsc_throw')),
    flags={'eha': ['/EHa'], 'ehs': ['/EHs'], 'o1': ['/O1'], 'osz': ['/Os'], 'gl': ['/GL'], 'gz': ['/Gz']})

# rule 19
add('r19-bound-copy', [19], 'a bound copy loading the radius first and storing it last differs from field-order copying', {
    'order': PRE + 'struct B{ float x,y,z,r; }; struct N{ int pad; B b; };\nextern "C" void fn(N* d,const N* s){ d->b.x=s->b.x; d->b.y=s->b.y; d->b.z=s->b.z; d->b.r=s->b.r; }\n',
    'radius_first': PRE + 'struct B{ float x,y,z,r; }; struct N{ int pad; B b; };\nextern "C" void fn(N* d,const N* s){ const float r=s->b.r; d->b.x=s->b.x; d->b.y=s->b.y; d->b.z=s->b.z; d->b.r=r; }\n',
    'struct': PRE + 'struct B{ float x,y,z,r; }; struct N{ int pad; B b; };\nextern "C" void fn(N* d,const N* s){ d->b=s->b; }\n',
}, lambda R: R['order'] != R['radius_first'] and R['order'] != R['struct'])

# rule 43
add('r43-cmov-vs-set', [43], 'a ternary of two constants yields cmov or setcc depending on form', {
    'ternary': PRE + 'extern "C" int fn(int a,int b){ return a<b ? 5 : 9; }\n',
    'ifelse': PRE + 'extern "C" int fn(int a,int b){ int r; if(a<b) r=5; else r=9; return r; }\n',
}, lambda R: R['ternary'] != R['ifelse'])

# rule 57
add('r57-zero-fill', [57], 'a zero-initialised local array is filled by a rolled loop or stores', {
    'braces': PRE + 'extern "C" void fn(){ int a[16]={}; sink(a); }\n',
    'memset': '#include <string.h>\n' + PRE + 'extern "C" void fn(){ int a[16]; memset(a,0,sizeof a); sink(a); }\n',
    'loop': PRE + 'extern "C" void fn(){ int a[16]; for(int i=0;i<16;++i) a[i]=0; sink(a); }\n',
}, lambda R: len({tuple(R[v]) for v in ('braces', 'memset', 'loop')}) == 1)

# rule 12 probe: does the choice of this-holding callee-saved register depend on source spelling
add('u12-this-register', ['12'], 'about 45 spellings never move this out of rbx; a spelling that changes which callee-saved register holds this would contradict that', {
    'a': '#include <intrin.h>\n' + PRE + 'struct L{ long w; void Yield(); };\nextern "C" void fn(L* l){ long o=_InterlockedCompareExchange(&l->w,1,0); while(o!=0){ l->Yield(); o=_InterlockedCompareExchange(&l->w,1,0); } l->w=2; }\n',
    'b': '#include <intrin.h>\n' + PRE + 'struct L{ long w; void Yield(); };\nextern "C" void fn(L* l){ while(_InterlockedCompareExchange(&l->w,1,0)!=0) l->Yield(); l->w=2; }\n',
    'c': '#include <intrin.h>\n' + PRE + 'struct L{ long w; void Yield(); };\nextern "C" void fn(L* l){ for(;;){ if(_InterlockedCompareExchange(&l->w,1,0)==0) break; l->Yield(); } l->w=2; }\n',
}, lambda R: len({this_and_minus1(R[v])[0] for v in ('a', 'b', 'c')}) == 1)


# rule 46 probe: which source spellings suppress a tail call
T46 = PRE + 'struct S{ void* c; int k; }; void* get(void*); int geti(void*); struct D{ D(); ~D(); };\n'
add('u46-tail-suppressors', ['46'], 'a call in return position is a jmp, and at least one ordinary spelling (a narrowing return, an address-taken local, a destructor local) turns it into call and ret', {
    'base': T46 + 'void* fn(S* s){ return get(s->c); }\n',
    'narrow': T46 + 'bool fn(S* s){ return geti(s->c) != 0; }\n',
    'addr_local': T46 + 'void sink2(int*); void* fn(S* s){ int t=s->k; sink2(&t); return get(s->c); }\n',
    'dtor_local': T46 + 'void* fn(S* s){ D d; return get(s->c); }\n',
    'result_local': T46 + 'void* fn(S* s){ void* r=get(s->c); return r; }\n',
    'cast_return': T46 + 'char fn(S* s){ return (char)geti(s->c); }\n',
}, lambda R: has(R['base'], r'^jmp') and sum(not has(R[v], r'^(jmp|rex_jmp)\s+\S*get') for v in ('narrow', 'addr_local', 'dtor_local', 'result_local', 'cast_return')) >= 2)

# mined from near pairs: operand width of a forwarded parameter
add('n01-param-width', ['mined'], 'a parameter copied into a callee-saved register is a 32-bit move for int/unsigned and a 64-bit move for size_t or a pointer', {
    'u32': PRE + 'void use2(unsigned,unsigned);\nextern "C" void fn(void* t,unsigned a){ use2(a,a); use2(a,2); }\n',
    'u64': PRE + 'void use2(size_t,size_t);\nextern "C" void fn(void* t,size_t a){ use2(a,a); use2(a,2); }\n',
}, lambda R: has(R['u32'], r'mov\s+ebx, edx') and has(R['u64'], r'mov\s+rbx, rdx'))

add('n02-stack-param-width', ['mined'], 'the fifth and later parameters are forwarded with a dword or a qword home-slot copy according to their type', {
    'int': PRE + 'int f8(int,int,int,int,int,int,int,int);\nextern "C" int fn(int a,int b,int c,int d,int e,int f,int g,int h){ return f8(a,b,c,d,e,f,g,h)+1; }\n',
    'i64': PRE + 'long long f8(long long,long long,long long,long long,long long,long long,long long,long long);\nextern "C" long long fn(long long a,long long b,long long c,long long d,long long e,long long f,long long g,long long h){ return f8(a,b,c,d,e,f,g,h)+1; }\n',
}, lambda R: has(R['int'], r'mov\s+eax, DWORD PTR') and has(R['i64'], r'mov\s+rax, QWORD PTR'))

add('n03-size-clamp-width', ['mined'], 'a zero-size clamp on an unsigned parameter tests and selects 32-bit registers; on size_t it uses 64-bit ones', {
    'u32': PRE + 'void* alloc(unsigned,int);\nextern "C" void* fn(unsigned n){ if(n==0) n=1; return alloc(n,4); }\n',
    'u64': PRE + 'void* alloc(size_t,int);\nextern "C" void* fn(size_t n){ if(n==0) n=1; return alloc(n,4); }\n',
}, lambda R: has(R['u32'], r'test\s+ecx, ecx') and has(R['u64'], r'test\s+rcx, rcx'))

add('n04-member-width', ['mined'], 'a count stored through a pointer-sized member versus a 32-bit member is a qword or dword store of the same register family', {
    'u32': PRE + 'struct M{ int a; unsigned n; unsigned m; };\nextern "C" void fn(M* x,unsigned v){ x->n=0; x->m=v; }\n',
    'u64': PRE + 'struct M{ int a; size_t n; size_t m; };\nextern "C" void fn(M* x,size_t v){ x->n=0; x->m=v; }\n',
}, lambda R: has(R['u32'], r'DWORD PTR \[rcx\+\d+\], 0') and has(R['u64'], r'QWORD PTR \[rcx\+\d+\], 0'))


def streams(src_dir_results, rc, exp, text_of=None):
    text_of = text_of or {}
    """R for one experiment: main stream, symbol list, all streams and compile status per variant."""
    R = {}
    for var in exp.variants:
        stem = f'{exp.ident}__{var}'
        funcs = src_dir_results.get(stem, {})
        R[var] = pick(funcs)
        R[var + '_syms'] = syms(funcs)
        R[var + '_all'] = funcs
        R[var + '_text'] = text_of.get(stem, '').splitlines()
        R[var + '_rc'] = rc.get(stem, 99)
    return R


def judge(exp, R):
    for var in exp.variants:
        if R[var + '_rc'] != 0 and var not in exp.compile_fail and exp.ident != 'r17-static-assert':
            return 'error', f'variant {var} failed to compile'
    try:
        ok = bool(exp.expect(R))
    except Exception as err:  # a malformed expectation is reported, never counted as a pass
        return 'error', f'{type(err).__name__}: {err}'
    return ('confirmed' if ok else 'contradicted'), ''


def stage(exps, src_dir):
    src_dir = Path(src_dir)
    src_dir.mkdir(parents=True, exist_ok=True)
    for exp in exps:
        for var, text in exp.variants.items():
            (src_dir / f'{exp.ident}__{var}.cpp').write_text(text)
            if var in exp.flags:
                (src_dir / f'{exp.ident}__{var}.flags').write_text(' '.join(exp.flags[var]))


def run(out, only=None, jobs=4, runners=None):
    out = Path(out)
    exps = [e for e in E if not only or e.ident.split('-')[0] in only or e.ident in only]
    stage(exps, out / 'src')
    rc = lab_compile.compile_remote(out / 'src', out / 'lst', jobs, runners or lab_compile.default_runners())
    results = lab_compile.load_results(out / 'lst')
    texts = {a.stem: a.read_text(errors='replace') for a in (out / 'lst').glob('*.asm')}
    report = []
    for exp in exps:
        R = streams(results, rc, exp, texts)
        verdict, note = judge(exp, R)
        report.append({'id': exp.ident, 'rules': exp.rules, 'claim': exp.claim, 'verdict': verdict, 'note': note,
                       'variants': {v: {'instructions': len(R[v]), 'compile_rc': R[v + '_rc'], 'symbols': R[v + '_syms']} for v in exp.variants}})
    (out / 'report.json').write_text(json.dumps(report, indent=1))
    return report


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest='cmd', required=True)
    r = sub.add_parser('run')
    r.add_argument('--out', required=True)
    r.add_argument('--only', default='')
    r.add_argument('--jobs', type=int, default=4)
    sub.add_parser('list')
    a = ap.parse_args()
    if a.cmd == 'list':
        for e in E:
            print(e.ident, e.rules, e.claim)
        return
    only = {s for s in a.only.split(',') if s}
    for row in run(a.out, only):
        print(f"{row['verdict']:<13} {row['id']:<24} {row['note']}")


if __name__ == '__main__':
    main()
