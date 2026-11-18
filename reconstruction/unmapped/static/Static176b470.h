// Source exposure: binary-analysis; no external implementation source reused.
// Static176b470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b470*);
    virtual void release(Static176b470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b470*);
struct Static176b470 {
    void* value;
    Static176b470();
    ~Static176b470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
