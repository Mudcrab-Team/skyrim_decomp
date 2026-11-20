// Source exposure: binary-analysis; no external implementation source reused.
// Static179b060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179b060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179b060*);
    virtual void release(Static179b060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179b060*);
struct Static179b060 {
    void* value;
    Static179b060();
    ~Static179b060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
