// Source exposure: binary-analysis
// Static8f910, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f910;
extern void construct(Static8f910*, const Descriptor*);
extern void destroy(Static8f910*);
struct Static8f910 {
    void* value;
    Static8f910() { construct(this, &descriptor); }
    ~Static8f910() { destroy(this); }
};
