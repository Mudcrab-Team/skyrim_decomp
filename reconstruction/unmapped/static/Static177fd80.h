// Source exposure: binary-analysis; no external implementation source reused.
// Static177fd80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fd80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fd80*);
    virtual void release(Static177fd80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fd80*);
struct Static177fd80 {
    void* value;
    Static177fd80();
    ~Static177fd80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
