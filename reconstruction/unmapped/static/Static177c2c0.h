// Source exposure: binary-analysis; no external implementation source reused.
// Static177c2c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c2c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c2c0*);
    virtual void release(Static177c2c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c2c0*);
struct Static177c2c0 {
    void* value;
    Static177c2c0();
    ~Static177c2c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
