// Source exposure: binary-analysis; no external implementation source reused.
// Static17b8290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b8290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b8290*);
    virtual void release(Static17b8290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b8290*);
struct Static17b8290 {
    void* value;
    Static17b8290();
    ~Static17b8290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
