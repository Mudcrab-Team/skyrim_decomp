// Source exposure: binary-analysis
// Staticcaa70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcaa70;
extern void construct(Staticcaa70*, const Descriptor*);
extern void destroy(Staticcaa70*);
struct Staticcaa70 {
    void* value;
    Staticcaa70() { construct(this, &descriptor); }
    ~Staticcaa70() { destroy(this); }
};
