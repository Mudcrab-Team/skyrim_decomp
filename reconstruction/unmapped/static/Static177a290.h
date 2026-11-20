// Source exposure: binary-analysis; no external implementation source reused.
// Static177a290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a290*);
    virtual void release(Static177a290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a290*);
struct Static177a290 {
    void* value;
    Static177a290();
    ~Static177a290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
