// Source exposure: binary-analysis
// Static8ae80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8ae80;
extern void construct(Static8ae80*, const Descriptor*);
extern void destroy(Static8ae80*);
struct Static8ae80 {
    void* value;
    Static8ae80() { construct(this, &descriptor); }
    ~Static8ae80() { destroy(this); }
};
