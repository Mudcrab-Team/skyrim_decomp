// Source exposure: binary-analysis; no external implementation source reused.
// Static179db10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179db10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179db10*);
    virtual void release(Static179db10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179db10*);
struct Static179db10 {
    void* value;
    Static179db10();
    ~Static179db10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
