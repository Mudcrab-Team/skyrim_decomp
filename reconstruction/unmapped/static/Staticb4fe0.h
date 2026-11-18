// Source exposure: binary-analysis
// Staticb4fe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4fe0;
extern void construct(Staticb4fe0*, const Descriptor*);
extern void destroy(Staticb4fe0*);
struct Staticb4fe0 {
    void* value;
    Staticb4fe0() { construct(this, &descriptor); }
    ~Staticb4fe0() { destroy(this); }
};
