// Source exposure: binary-analysis; no external implementation source reused.
// Static179ce60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ce60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ce60*);
    virtual void release(Static179ce60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ce60*);
struct Static179ce60 {
    void* value;
    Static179ce60();
    ~Static179ce60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
