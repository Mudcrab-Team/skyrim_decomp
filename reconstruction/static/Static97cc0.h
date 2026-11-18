// Source exposure: binary-analysis
// Static97cc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static97cc0;
extern void construct(Static97cc0*, const Descriptor*);
extern void destroy(Static97cc0*);
struct Static97cc0 {
    void* value;
    Static97cc0() { construct(this, &descriptor); }
    ~Static97cc0() { destroy(this); }
};
