// Source exposure: binary-analysis
// Static8f790, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f790;
extern void construct(Static8f790*, const Descriptor*);
extern void destroy(Static8f790*);
struct Static8f790 {
    void* value;
    Static8f790() { construct(this, &descriptor); }
    ~Static8f790() { destroy(this); }
};
