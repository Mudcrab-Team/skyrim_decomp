// Source exposure: binary-analysis
// Staticca130, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca130;
extern void construct(Staticca130*, const Descriptor*);
extern void destroy(Staticca130*);
struct Staticca130 {
    void* value;
    Staticca130() { construct(this, &descriptor); }
    ~Staticca130() { destroy(this); }
};
