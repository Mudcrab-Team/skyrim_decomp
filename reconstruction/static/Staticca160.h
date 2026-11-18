// Source exposure: binary-analysis
// Staticca160, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca160;
extern void construct(Staticca160*, const Descriptor*);
extern void destroy(Staticca160*);
struct Staticca160 {
    void* value;
    Staticca160() { construct(this, &descriptor); }
    ~Staticca160() { destroy(this); }
};
