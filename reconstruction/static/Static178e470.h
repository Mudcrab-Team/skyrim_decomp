// Source exposure: binary-analysis; no external implementation source reused.
// Static178e470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178e470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178e470*);
    virtual void release(Static178e470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178e470*);
struct Static178e470 {
    void* value;
    Static178e470();
    ~Static178e470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
