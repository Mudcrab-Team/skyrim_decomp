// Source exposure: binary-analysis; no external implementation source reused.
// Static177f290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f290*);
    virtual void release(Static177f290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f290*);
struct Static177f290 {
    void* value;
    Static177f290();
    ~Static177f290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
