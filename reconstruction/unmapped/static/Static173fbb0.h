// Source exposure: binary-analysis; no external implementation source reused.
// Static173fbb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173fbb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173fbb0*);
    virtual void release(Static173fbb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173fbb0*);
struct Static173fbb0 {
    void* value;
    Static173fbb0();
    ~Static173fbb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
