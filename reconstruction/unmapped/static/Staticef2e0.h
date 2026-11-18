// Source exposure: binary-analysis
// Staticef2e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef2e0;
extern void construct(Staticef2e0*, const Descriptor*);
extern void destroy(Staticef2e0*);
struct Staticef2e0 {
    void* value;
    Staticef2e0() { construct(this, &descriptor); }
    ~Staticef2e0() { destroy(this); }
};
