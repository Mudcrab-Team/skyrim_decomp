// Source exposure: binary-analysis
// Staticb79d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb79d0;
extern void construct(Staticb79d0*, const Descriptor*);
extern void destroy(Staticb79d0*);
struct Staticb79d0 {
    void* value;
    Staticb79d0() { construct(this, &descriptor); }
    ~Staticb79d0() { destroy(this); }
};
