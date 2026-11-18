// Source exposure: binary-analysis
// Staticba770, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticba770;
extern void construct(Staticba770*, const Descriptor*);
extern void destroy(Staticba770*);
struct Staticba770 {
    void* value;
    Staticba770() { construct(this, &descriptor); }
    ~Staticba770() { destroy(this); }
};
