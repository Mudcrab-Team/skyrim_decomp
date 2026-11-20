// Source exposure: binary-analysis
// Staticea900, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticea900;
extern void construct(Staticea900*, const Descriptor*);
extern void destroy(Staticea900*);
struct Staticea900 {
    void* value;
    Staticea900() { construct(this, &descriptor); }
    ~Staticea900() { destroy(this); }
};
