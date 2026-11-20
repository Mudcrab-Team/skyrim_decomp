// Source exposure: binary-analysis; no external implementation source reused.
// Static177fd30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fd30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fd30*);
    virtual void release(Static177fd30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fd30*);
struct Static177fd30 {
    void* value;
    Static177fd30();
    ~Static177fd30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
