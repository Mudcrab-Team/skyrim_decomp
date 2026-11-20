// Source exposure: binary-analysis; no external implementation source reused.
// Static179a790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179a790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179a790*);
    virtual void release(Static179a790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179a790*);
struct Static179a790 {
    void* value;
    Static179a790();
    ~Static179a790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
