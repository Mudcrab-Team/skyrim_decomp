// Source exposure: binary-analysis; no external implementation source reused.
// Static178d600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d600*);
    virtual void release(Static178d600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d600*);
struct Static178d600 {
    void* value;
    Static178d600();
    ~Static178d600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
