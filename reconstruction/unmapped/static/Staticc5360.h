// Source exposure: binary-analysis
// Staticc5360, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc5360;
extern void construct(Staticc5360*, const Descriptor*);
extern void destroy(Staticc5360*);
struct Staticc5360 {
    void* value;
    Staticc5360() { construct(this, &descriptor); }
    ~Staticc5360() { destroy(this); }
};
