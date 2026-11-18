// Source exposure: binary-analysis
// Staticb4ef0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4ef0;
extern void construct(Staticb4ef0*, const Descriptor*);
extern void destroy(Staticb4ef0*);
struct Staticb4ef0 {
    void* value;
    Staticb4ef0() { construct(this, &descriptor); }
    ~Staticb4ef0() { destroy(this); }
};
