// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa420, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa420;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa420*);
    virtual void release(Static17aa420*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa420*);
struct Static17aa420 {
    void* value;
    Static17aa420();
    ~Static17aa420() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
