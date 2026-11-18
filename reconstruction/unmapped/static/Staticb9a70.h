// Source exposure: binary-analysis
// Staticb9a70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9a70;
extern void construct(Staticb9a70*, const Descriptor*);
extern void destroy(Staticb9a70*);
struct Staticb9a70 {
    void* value;
    Staticb9a70() { construct(this, &descriptor); }
    ~Staticb9a70() { destroy(this); }
};
