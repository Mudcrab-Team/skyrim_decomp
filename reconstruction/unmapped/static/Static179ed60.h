// Source exposure: binary-analysis; no external implementation source reused.
// Static179ed60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ed60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ed60*);
    virtual void release(Static179ed60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ed60*);
struct Static179ed60 {
    void* value;
    Static179ed60();
    ~Static179ed60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
