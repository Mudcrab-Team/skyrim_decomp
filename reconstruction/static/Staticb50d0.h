// Source exposure: binary-analysis
// Staticb50d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb50d0;
extern void construct(Staticb50d0*, const Descriptor*);
extern void destroy(Staticb50d0*);
struct Staticb50d0 {
    void* value;
    Staticb50d0() { construct(this, &descriptor); }
    ~Staticb50d0() { destroy(this); }
};
