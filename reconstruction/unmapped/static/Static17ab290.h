// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab290*);
    virtual void release(Static17ab290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab290*);
struct Static17ab290 {
    void* value;
    Static17ab290();
    ~Static17ab290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
