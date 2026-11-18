// Source exposure: binary-analysis
// Staticef550, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef550;
extern void construct(Staticef550*, const Descriptor*);
extern void destroy(Staticef550*);
struct Staticef550 {
    void* value;
    Staticef550() { construct(this, &descriptor); }
    ~Staticef550() { destroy(this); }
};
