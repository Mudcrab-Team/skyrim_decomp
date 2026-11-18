// Source exposure: binary-analysis; no external implementation source reused.
// Static177db20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177db20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177db20*);
    virtual void release(Static177db20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177db20*);
struct Static177db20 {
    void* value;
    Static177db20();
    ~Static177db20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
