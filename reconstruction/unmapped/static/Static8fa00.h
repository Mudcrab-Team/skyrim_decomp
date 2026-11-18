// Source exposure: binary-analysis
// Static8fa00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fa00;
extern void construct(Static8fa00*, const Descriptor*);
extern void destroy(Static8fa00*);
struct Static8fa00 {
    void* value;
    Static8fa00() { construct(this, &descriptor); }
    ~Static8fa00() { destroy(this); }
};
