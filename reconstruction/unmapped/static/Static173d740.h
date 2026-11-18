// Source exposure: binary-analysis; no external implementation source reused.
// Static173d740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d740*);
    virtual void release(Static173d740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d740*);
struct Static173d740 {
    void* value;
    Static173d740();
    ~Static173d740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
