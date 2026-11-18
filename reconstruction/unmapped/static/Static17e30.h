// Source exposure: binary-analysis
// Static17e30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static17e30;
extern void construct(Static17e30*, const Descriptor*);
extern void destroy(Static17e30*);
struct Static17e30 {
    void* value;
    Static17e30() { construct(this, &descriptor); }
    ~Static17e30() { destroy(this); }
};
