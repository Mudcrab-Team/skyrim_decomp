// Source exposure: binary-analysis; no external implementation source reused.
// Static176a110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a110*);
    virtual void release(Static176a110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a110*);
struct Static176a110 {
    void* value;
    Static176a110();
    ~Static176a110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
