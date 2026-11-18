// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab970*);
    virtual void release(Static17ab970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab970*);
struct Static17ab970 {
    void* value;
    Static17ab970();
    ~Static17ab970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
