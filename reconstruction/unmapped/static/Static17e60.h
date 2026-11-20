// Source exposure: binary-analysis
// Static17e60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static17e60;
extern void construct(Static17e60*, const Descriptor*);
extern void destroy(Static17e60*);
struct Static17e60 {
    void* value;
    Static17e60() { construct(this, &descriptor); }
    ~Static17e60() { destroy(this); }
};
