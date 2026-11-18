// Source exposure: binary-analysis
// Staticca340, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca340;
extern void construct(Staticca340*, const Descriptor*);
extern void destroy(Staticca340*);
struct Staticca340 {
    void* value;
    Staticca340() { construct(this, &descriptor); }
    ~Staticca340() { destroy(this); }
};
