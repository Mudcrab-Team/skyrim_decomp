// Source exposure: binary-analysis
// Static8faf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8faf0;
extern void construct(Static8faf0*, const Descriptor*);
extern void destroy(Static8faf0*);
struct Static8faf0 {
    void* value;
    Static8faf0() { construct(this, &descriptor); }
    ~Static8faf0() { destroy(this); }
};
