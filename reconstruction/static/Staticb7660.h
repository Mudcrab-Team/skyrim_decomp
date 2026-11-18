// Source exposure: binary-analysis
// Staticb7660, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7660;
extern void construct(Staticb7660*, const Descriptor*);
extern void destroy(Staticb7660*);
struct Staticb7660 {
    void* value;
    Staticb7660() { construct(this, &descriptor); }
    ~Staticb7660() { destroy(this); }
};
