// Source exposure: binary-analysis
// Static8b210, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b210;
extern void construct(Static8b210*, const Descriptor*);
extern void destroy(Static8b210*);
struct Static8b210 {
    void* value;
    Static8b210() { construct(this, &descriptor); }
    ~Static8b210() { destroy(this); }
};
