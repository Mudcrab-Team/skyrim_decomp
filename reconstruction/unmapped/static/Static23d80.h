// Source exposure: binary-analysis
// Static23d80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23d80;
extern void construct(Static23d80*, const Descriptor*);
extern void destroy(Static23d80*);
struct Static23d80 {
    void* value;
    Static23d80() { construct(this, &descriptor); }
    ~Static23d80() { destroy(this); }
};
