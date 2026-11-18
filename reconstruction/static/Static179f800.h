// Source exposure: binary-analysis; no external implementation source reused.
// Static179f800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f800*);
    virtual void release(Static179f800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f800*);
struct Static179f800 {
    void* value;
    Static179f800();
    ~Static179f800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
