// Source exposure: binary-analysis; no external implementation source reused.
// Static179a830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179a830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179a830*);
    virtual void release(Static179a830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179a830*);
struct Static179a830 {
    void* value;
    Static179a830();
    ~Static179a830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
