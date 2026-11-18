// Source exposure: binary-analysis
// Static23d50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23d50;
extern void construct(Static23d50*, const Descriptor*);
extern void destroy(Static23d50*);
struct Static23d50 {
    void* value;
    Static23d50() { construct(this, &descriptor); }
    ~Static23d50() { destroy(this); }
};
