// Source exposure: binary-analysis; no external implementation source reused.
// Static179a580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179a580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179a580*);
    virtual void release(Static179a580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179a580*);
struct Static179a580 {
    void* value;
    Static179a580();
    ~Static179a580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
