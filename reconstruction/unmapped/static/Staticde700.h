// Source exposure: binary-analysis
// Staticde700, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticde700;
extern void construct(Staticde700*, const Descriptor*);
extern void destroy(Staticde700*);
struct Staticde700 {
    void* value;
    Staticde700() { construct(this, &descriptor); }
    ~Staticde700() { destroy(this); }
};
