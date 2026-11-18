// Source exposure: binary-analysis; no external implementation source reused.
// Static179ef90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ef90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ef90*);
    virtual void release(Static179ef90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ef90*);
struct Static179ef90 {
    void* value;
    Static179ef90();
    ~Static179ef90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
