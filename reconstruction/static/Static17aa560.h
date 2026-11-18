// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa560*);
    virtual void release(Static17aa560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa560*);
struct Static17aa560 {
    void* value;
    Static17aa560();
    ~Static17aa560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
