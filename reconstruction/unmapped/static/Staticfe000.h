// Source exposure: binary-analysis
// Staticfe000, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticfe000;
extern void construct(Staticfe000*, const Descriptor*);
extern void destroy(Staticfe000*);
struct Staticfe000 {
    void* value;
    Staticfe000() { construct(this, &descriptor); }
    ~Staticfe000() { destroy(this); }
};
