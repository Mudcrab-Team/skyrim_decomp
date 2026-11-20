// Source exposure: binary-analysis; no external implementation source reused.
// Static174e410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e410*);
    virtual void release(Static174e410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e410*);
struct Static174e410 {
    void* value;
    Static174e410();
    ~Static174e410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
