// Source exposure: binary-analysis; no external implementation source reused.
// Static173e4b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e4b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e4b0*);
    virtual void release(Static173e4b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e4b0*);
struct Static173e4b0 {
    void* value;
    Static173e4b0();
    ~Static173e4b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
