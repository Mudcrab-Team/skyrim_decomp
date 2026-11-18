// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab560*);
    virtual void release(Static17ab560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab560*);
struct Static17ab560 {
    void* value;
    Static17ab560();
    ~Static17ab560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
