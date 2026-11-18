// Source exposure: binary-analysis
// Staticb5ca0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5ca0;
extern void construct(Staticb5ca0*, const Descriptor*);
extern void destroy(Staticb5ca0*);
struct Staticb5ca0 {
    void* value;
    Staticb5ca0() { construct(this, &descriptor); }
    ~Staticb5ca0() { destroy(this); }
};
