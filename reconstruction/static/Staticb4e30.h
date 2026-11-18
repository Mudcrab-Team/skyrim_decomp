// Source exposure: binary-analysis
// Staticb4e30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4e30;
extern void construct(Staticb4e30*, const Descriptor*);
extern void destroy(Staticb4e30*);
struct Staticb4e30 {
    void* value;
    Staticb4e30() { construct(this, &descriptor); }
    ~Staticb4e30() { destroy(this); }
};
