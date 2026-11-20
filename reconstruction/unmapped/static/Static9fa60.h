// Source exposure: binary-analysis
// Static9fa60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fa60;
extern void construct(Static9fa60*, const Descriptor*);
extern void destroy(Static9fa60*);
struct Static9fa60 {
    void* value;
    Static9fa60() { construct(this, &descriptor); }
    ~Static9fa60() { destroy(this); }
};
