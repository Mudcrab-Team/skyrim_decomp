// Source exposure: binary-analysis; no external implementation source reused.
// Static176ed00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ed00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ed00*);
    virtual void release(Static176ed00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ed00*);
struct Static176ed00 {
    void* value;
    Static176ed00();
    ~Static176ed00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
