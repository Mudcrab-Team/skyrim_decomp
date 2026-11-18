// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa740*);
    virtual void release(Static17aa740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa740*);
struct Static17aa740 {
    void* value;
    Static17aa740();
    ~Static17aa740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
