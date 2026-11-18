// Source exposure: binary-analysis; no external implementation source reused.
// Static174ba00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ba00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ba00*);
    virtual void release(Static174ba00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ba00*);
struct Static174ba00 {
    void* value;
    Static174ba00();
    ~Static174ba00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
