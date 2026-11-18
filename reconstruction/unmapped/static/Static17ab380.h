// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab380*);
    virtual void release(Static17ab380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab380*);
struct Static17ab380 {
    void* value;
    Static17ab380();
    ~Static17ab380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
