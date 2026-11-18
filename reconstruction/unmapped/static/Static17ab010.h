// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab010*);
    virtual void release(Static17ab010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab010*);
struct Static17ab010 {
    void* value;
    Static17ab010();
    ~Static17ab010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
