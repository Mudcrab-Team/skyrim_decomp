// Source exposure: binary-analysis
// Staticb4d70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4d70;
extern void construct(Staticb4d70*, const Descriptor*);
extern void destroy(Staticb4d70*);
struct Staticb4d70 {
    void* value;
    Staticb4d70() { construct(this, &descriptor); }
    ~Staticb4d70() { destroy(this); }
};
