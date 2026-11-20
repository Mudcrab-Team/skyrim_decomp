// Source exposure: binary-analysis
// Staticb3e30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb3e30;
extern void construct(Staticb3e30*, const Descriptor*);
extern void destroy(Staticb3e30*);
struct Staticb3e30 {
    void* value;
    Staticb3e30() { construct(this, &descriptor); }
    ~Staticb3e30() { destroy(this); }
};
