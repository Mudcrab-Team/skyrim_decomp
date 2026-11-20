// Source exposure: binary-analysis
// Staticbd330, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbd330;
extern void construct(Staticbd330*, const Descriptor*);
extern void destroy(Staticbd330*);
struct Staticbd330 {
    void* value;
    Staticbd330() { construct(this, &descriptor); }
    ~Staticbd330() { destroy(this); }
};
