// Source exposure: binary-analysis; no external implementation source reused.
// Static176ed50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ed50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ed50*);
    virtual void release(Static176ed50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ed50*);
struct Static176ed50 {
    void* value;
    Static176ed50();
    ~Static176ed50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
