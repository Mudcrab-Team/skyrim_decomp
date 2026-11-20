// Source exposure: binary-analysis
// Static8b120, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b120;
extern void construct(Static8b120*, const Descriptor*);
extern void destroy(Static8b120*);
struct Static8b120 {
    void* value;
    Static8b120() { construct(this, &descriptor); }
    ~Static8b120() { destroy(this); }
};
