// Source exposure: binary-analysis; no external implementation source reused.
// Static176f110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f110*);
    virtual void release(Static176f110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f110*);
struct Static176f110 {
    void* value;
    Static176f110();
    ~Static176f110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
