// Source exposure: binary-analysis
// Staticcabf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcabf0;
extern void construct(Staticcabf0*, const Descriptor*);
extern void destroy(Staticcabf0*);
struct Staticcabf0 {
    void* value;
    Staticcabf0() { construct(this, &descriptor); }
    ~Staticcabf0() { destroy(this); }
};
