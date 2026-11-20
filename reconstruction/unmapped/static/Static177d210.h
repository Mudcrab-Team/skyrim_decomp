// Source exposure: binary-analysis; no external implementation source reused.
// Static177d210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d210*);
    virtual void release(Static177d210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d210*);
struct Static177d210 {
    void* value;
    Static177d210();
    ~Static177d210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
