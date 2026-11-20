// Source exposure: binary-analysis
// Static97a50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97a50;
extern void construct(Static97a50*, const Descriptor*);
extern void destroy(Static97a50*);
struct Static97a50 {
    void* value;
    Static97a50() { construct(this, &descriptor); }
    ~Static97a50() { destroy(this); }
};
