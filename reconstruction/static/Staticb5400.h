// Source exposure: binary-analysis
// Staticb5400, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5400;
extern void construct(Staticb5400*, const Descriptor*);
extern void destroy(Staticb5400*);
struct Staticb5400 {
    void* value;
    Staticb5400() { construct(this, &descriptor); }
    ~Staticb5400() { destroy(this); }
};
