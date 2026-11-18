// Source exposure: binary-analysis
// Static974b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static974b0;
extern void construct(Static974b0*, const Descriptor*);
extern void destroy(Static974b0*);
struct Static974b0 {
    void* value;
    Static974b0() { construct(this, &descriptor); }
    ~Static974b0() { destroy(this); }
};
