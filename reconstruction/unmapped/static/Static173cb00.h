// Source exposure: binary-analysis; no external implementation source reused.
// Static173cb00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cb00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cb00*);
    virtual void release(Static173cb00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cb00*);
struct Static173cb00 {
    void* value;
    Static173cb00();
    ~Static173cb00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
