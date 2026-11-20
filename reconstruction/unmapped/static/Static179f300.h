// Source exposure: binary-analysis; no external implementation source reused.
// Static179f300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f300*);
    virtual void release(Static179f300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f300*);
struct Static179f300 {
    void* value;
    Static179f300();
    ~Static179f300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
