// Source exposure: binary-analysis; no external implementation source reused.
// Static176dbd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176dbd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176dbd0*);
    virtual void release(Static176dbd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176dbd0*);
struct Static176dbd0 {
    void* value;
    Static176dbd0();
    ~Static176dbd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
