// Source exposure: binary-analysis
// Staticbd360, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbd360;
extern void construct(Staticbd360*, const Descriptor*);
extern void destroy(Staticbd360*);
struct Staticbd360 {
    void* value;
    Staticbd360() { construct(this, &descriptor); }
    ~Staticbd360() { destroy(this); }
};
