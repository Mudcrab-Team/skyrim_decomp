// Source exposure: binary-analysis; no external implementation source reused.
// Static176f610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f610*);
    virtual void release(Static176f610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f610*);
struct Static176f610 {
    void* value;
    Static176f610();
    ~Static176f610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
