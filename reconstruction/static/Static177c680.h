// Source exposure: binary-analysis; no external implementation source reused.
// Static177c680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c680*);
    virtual void release(Static177c680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c680*);
struct Static177c680 {
    void* value;
    Static177c680();
    ~Static177c680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
