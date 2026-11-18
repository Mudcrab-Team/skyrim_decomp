// Source exposure: binary-analysis
// Staticb65c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb65c0;
extern void construct(Staticb65c0*, const Descriptor*);
extern void destroy(Staticb65c0*);
struct Staticb65c0 {
    void* value;
    Staticb65c0() { construct(this, &descriptor); }
    ~Staticb65c0() { destroy(this); }
};
