// Source exposure: binary-analysis
// Static17e00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static17e00;
extern void construct(Static17e00*, const Descriptor*);
extern void destroy(Static17e00*);
struct Static17e00 {
    void* value;
    Static17e00() { construct(this, &descriptor); }
    ~Static17e00() { destroy(this); }
};
