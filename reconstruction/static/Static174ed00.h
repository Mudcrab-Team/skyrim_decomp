// Source exposure: binary-analysis; no external implementation source reused.
// Static174ed00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ed00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ed00*);
    virtual void release(Static174ed00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ed00*);
struct Static174ed00 {
    void* value;
    Static174ed00();
    ~Static174ed00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
