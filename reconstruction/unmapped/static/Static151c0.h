// Source exposure: binary-analysis
// Static151c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static151c0;
extern void construct(Static151c0*, const Descriptor*);
extern void destroy(Static151c0*);
struct Static151c0 {
    void* value;
    Static151c0() { construct(this, &descriptor); }
    ~Static151c0() { destroy(this); }
};
