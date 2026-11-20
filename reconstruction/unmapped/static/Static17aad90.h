// Source exposure: binary-analysis; no external implementation source reused.
// Static17aad90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aad90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aad90*);
    virtual void release(Static17aad90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aad90*);
struct Static17aad90 {
    void* value;
    Static17aad90();
    ~Static17aad90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
