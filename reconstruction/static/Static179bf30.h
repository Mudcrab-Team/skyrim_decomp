// Source exposure: binary-analysis; no external implementation source reused.
// Static179bf30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179bf30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179bf30*);
    virtual void release(Static179bf30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179bf30*);
struct Static179bf30 {
    void* value;
    Static179bf30();
    ~Static179bf30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
