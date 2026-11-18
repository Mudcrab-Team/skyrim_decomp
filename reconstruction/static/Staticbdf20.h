// Source exposure: binary-analysis
// Staticbdf20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbdf20;
extern void construct(Staticbdf20*, const Descriptor*);
extern void destroy(Staticbdf20*);
struct Staticbdf20 {
    void* value;
    Staticbdf20() { construct(this, &descriptor); }
    ~Staticbdf20() { destroy(this); }
};
