// Source exposure: binary-analysis
// Staticb97b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb97b0;
extern void construct(Staticb97b0*, const Descriptor*);
extern void destroy(Staticb97b0*);
struct Staticb97b0 {
    void* value;
    Staticb97b0() { construct(this, &descriptor); }
    ~Staticb97b0() { destroy(this); }
};
