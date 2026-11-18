// Source exposure: binary-analysis
// Static198c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static198c0;
extern void construct(Static198c0*, const Descriptor*);
extern void destroy(Static198c0*);
struct Static198c0 {
    void* value;
    Static198c0() { construct(this, &descriptor); }
    ~Static198c0() { destroy(this); }
};
