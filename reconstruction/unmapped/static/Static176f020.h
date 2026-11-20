// Source exposure: binary-analysis; no external implementation source reused.
// Static176f020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f020*);
    virtual void release(Static176f020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f020*);
struct Static176f020 {
    void* value;
    Static176f020();
    ~Static176f020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
