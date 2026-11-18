// Source exposure: binary-analysis
// Staticb91b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb91b0;
extern void construct(Staticb91b0*, const Descriptor*);
extern void destroy(Staticb91b0*);
struct Staticb91b0 {
    void* value;
    Staticb91b0() { construct(this, &descriptor); }
    ~Staticb91b0() { destroy(this); }
};
