// Source exposure: binary-analysis
// Staticb92d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb92d0;
extern void construct(Staticb92d0*, const Descriptor*);
extern void destroy(Staticb92d0*);
struct Staticb92d0 {
    void* value;
    Staticb92d0() { construct(this, &descriptor); }
    ~Staticb92d0() { destroy(this); }
};
