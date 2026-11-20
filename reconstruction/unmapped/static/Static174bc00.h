// Source exposure: binary-analysis; no external implementation source reused.
// Static174bc00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bc00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bc00*);
    virtual void release(Static174bc00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bc00*);
struct Static174bc00 {
    void* value;
    Static174bc00();
    ~Static174bc00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
