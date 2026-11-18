// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab510*);
    virtual void release(Static17ab510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab510*);
struct Static17ab510 {
    void* value;
    Static17ab510();
    ~Static17ab510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
