// Source exposure: binary-analysis
// Static97a20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97a20;
extern void construct(Static97a20*, const Descriptor*);
extern void destroy(Static97a20*);
struct Static97a20 {
    void* value;
    Static97a20() { construct(this, &descriptor); }
    ~Static97a20() { destroy(this); }
};
