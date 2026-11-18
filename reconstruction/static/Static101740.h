// Source exposure: binary-analysis
// Static101740, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101740;
extern void construct(Static101740*, const Descriptor*);
extern void destroy(Static101740*);
struct Static101740 {
    void* value;
    Static101740() { construct(this, &descriptor); }
    ~Static101740() { destroy(this); }
};
