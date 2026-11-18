// Source exposure: binary-analysis; no external implementation source reused.
// Static179db60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179db60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179db60*);
    virtual void release(Static179db60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179db60*);
struct Static179db60 {
    void* value;
    Static179db60();
    ~Static179db60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
