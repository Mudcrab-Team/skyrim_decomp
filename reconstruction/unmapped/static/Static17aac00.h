// Source exposure: binary-analysis; no external implementation source reused.
// Static17aac00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aac00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aac00*);
    virtual void release(Static17aac00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aac00*);
struct Static17aac00 {
    void* value;
    Static17aac00();
    ~Static17aac00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
