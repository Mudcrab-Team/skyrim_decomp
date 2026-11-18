// Source exposure: binary-analysis
// Static8f850, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f850;
extern void construct(Static8f850*, const Descriptor*);
extern void destroy(Static8f850*);
struct Static8f850 {
    void* value;
    Static8f850() { construct(this, &descriptor); }
    ~Static8f850() { destroy(this); }
};
