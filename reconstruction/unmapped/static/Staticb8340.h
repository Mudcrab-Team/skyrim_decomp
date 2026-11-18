// Source exposure: binary-analysis
// Staticb8340, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb8340;
extern void construct(Staticb8340*, const Descriptor*);
extern void destroy(Staticb8340*);
struct Staticb8340 {
    void* value;
    Staticb8340() { construct(this, &descriptor); }
    ~Staticb8340() { destroy(this); }
};
