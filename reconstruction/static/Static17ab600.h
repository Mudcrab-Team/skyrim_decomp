// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab600*);
    virtual void release(Static17ab600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab600*);
struct Static17ab600 {
    void* value;
    Static17ab600();
    ~Static17ab600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
