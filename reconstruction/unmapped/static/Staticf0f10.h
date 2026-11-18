// Source exposure: binary-analysis
// Staticf0f10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf0f10;
extern void construct(Staticf0f10*, const Descriptor*);
extern void destroy(Staticf0f10*);
struct Staticf0f10 {
    void* value;
    Staticf0f10() { construct(this, &descriptor); }
    ~Staticf0f10() { destroy(this); }
};
