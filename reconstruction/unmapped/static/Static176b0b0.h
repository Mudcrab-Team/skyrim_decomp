// Source exposure: binary-analysis; no external implementation source reused.
// Static176b0b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b0b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b0b0*);
    virtual void release(Static176b0b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b0b0*);
struct Static176b0b0 {
    void* value;
    Static176b0b0();
    ~Static176b0b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
