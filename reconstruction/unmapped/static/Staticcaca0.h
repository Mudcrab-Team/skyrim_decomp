// Source exposure: binary-analysis
// Staticcaca0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcaca0;
extern void construct(Staticcaca0*, const Descriptor*);
extern void destroy(Staticcaca0*);
struct Staticcaca0 {
    void* value;
    Staticcaca0() { construct(this, &descriptor); }
    ~Staticcaca0() { destroy(this); }
};
