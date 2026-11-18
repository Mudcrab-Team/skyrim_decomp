// Source exposure: binary-analysis; no external implementation source reused.
// Static179dc00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179dc00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179dc00*);
    virtual void release(Static179dc00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179dc00*);
struct Static179dc00 {
    void* value;
    Static179dc00();
    ~Static179dc00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
