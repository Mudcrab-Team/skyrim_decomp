// Source exposure: binary-analysis
// Staticcaa10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcaa10;
extern void construct(Staticcaa10*, const Descriptor*);
extern void destroy(Staticcaa10*);
struct Staticcaa10 {
    void* value;
    Staticcaa10() { construct(this, &descriptor); }
    ~Staticcaa10() { destroy(this); }
};
