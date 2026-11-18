// Source exposure: binary-analysis
// Staticf630, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf630;
extern void construct(Staticf630*, const Descriptor*);
extern void destroy(Staticf630*);
struct Staticf630 {
    void* value;
    Staticf630() { construct(this, &descriptor); }
    ~Staticf630() { destroy(this); }
};
