// Source exposure: binary-analysis
// Staticd600, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd600;
extern void construct(Staticd600*, const Descriptor*);
extern void destroy(Staticd600*);
struct Staticd600 {
    void* value;
    Staticd600() { construct(this, &descriptor); }
    ~Staticd600() { destroy(this); }
};
