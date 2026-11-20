// Source exposure: binary-analysis
// Static21880, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21880;
extern void construct(Static21880*, const Descriptor*);
extern void destroy(Static21880*);
struct Static21880 {
    void* value;
    Static21880() { construct(this, &descriptor); }
    ~Static21880() { destroy(this); }
};
