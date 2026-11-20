// Source exposure: binary-analysis
// Staticd510, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd510;
extern void construct(Staticd510*, const Descriptor*);
extern void destroy(Staticd510*);
struct Staticd510 {
    void* value;
    Staticd510() { construct(this, &descriptor); }
    ~Staticd510() { destroy(this); }
};
