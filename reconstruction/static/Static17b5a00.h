// Source exposure: binary-analysis; no external implementation source reused.
// Static17b5a00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b5a00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b5a00*);
    virtual void release(Static17b5a00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b5a00*);
struct Static17b5a00 {
    void* value;
    Static17b5a00();
    ~Static17b5a00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
