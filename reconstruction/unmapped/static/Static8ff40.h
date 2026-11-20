// Source exposure: binary-analysis
// Static8ff40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8ff40;
extern void construct(Static8ff40*, const Descriptor*);
extern void destroy(Static8ff40*);
struct Static8ff40 {
    void* value;
    Static8ff40() { construct(this, &descriptor); }
    ~Static8ff40() { destroy(this); }
};
