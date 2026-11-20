// Source exposure: binary-analysis
// Static8aad0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8aad0;
extern void construct(Static8aad0*, const Descriptor*);
extern void destroy(Static8aad0*);
struct Static8aad0 {
    void* value;
    Static8aad0() { construct(this, &descriptor); }
    ~Static8aad0() { destroy(this); }
};
