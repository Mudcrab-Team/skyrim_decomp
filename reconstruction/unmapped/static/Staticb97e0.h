// Source exposure: binary-analysis
// Staticb97e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb97e0;
extern void construct(Staticb97e0*, const Descriptor*);
extern void destroy(Staticb97e0*);
struct Staticb97e0 {
    void* value;
    Staticb97e0() { construct(this, &descriptor); }
    ~Staticb97e0() { destroy(this); }
};
