// Source exposure: binary-analysis; no external implementation source reused.
// Static176e210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e210*);
    virtual void release(Static176e210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e210*);
struct Static176e210 {
    void* value;
    Static176e210();
    ~Static176e210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
