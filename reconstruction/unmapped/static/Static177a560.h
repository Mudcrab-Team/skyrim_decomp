// Source exposure: binary-analysis; no external implementation source reused.
// Static177a560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a560*);
    virtual void release(Static177a560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a560*);
struct Static177a560 {
    void* value;
    Static177a560();
    ~Static177a560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
