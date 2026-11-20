// Source exposure: binary-analysis
// Staticb8400, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb8400;
extern void construct(Staticb8400*, const Descriptor*);
extern void destroy(Staticb8400*);
struct Staticb8400 {
    void* value;
    Staticb8400() { construct(this, &descriptor); }
    ~Staticb8400() { destroy(this); }
};
