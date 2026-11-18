// Source exposure: binary-analysis
// Staticcacd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcacd0;
extern void construct(Staticcacd0*, const Descriptor*);
extern void destroy(Staticcacd0*);
struct Staticcacd0 {
    void* value;
    Staticcacd0() { construct(this, &descriptor); }
    ~Staticcacd0() { destroy(this); }
};
