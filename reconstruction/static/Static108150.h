// Source exposure: binary-analysis
// Static108150, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108150;
extern void construct(Static108150*, const Descriptor*);
extern void destroy(Static108150*);
struct Static108150 {
    void* value;
    Static108150() { construct(this, &descriptor); }
    ~Static108150() { destroy(this); }
};
