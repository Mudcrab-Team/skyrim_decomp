// Source exposure: binary-analysis; no external implementation source reused.
// Static176ac00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ac00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ac00*);
    virtual void release(Static176ac00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ac00*);
struct Static176ac00 {
    void* value;
    Static176ac00();
    ~Static176ac00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
