// Source exposure: binary-analysis; no external implementation source reused.
// Static177a0b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a0b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a0b0*);
    virtual void release(Static177a0b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a0b0*);
struct Static177a0b0 {
    void* value;
    Static177a0b0();
    ~Static177a0b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
