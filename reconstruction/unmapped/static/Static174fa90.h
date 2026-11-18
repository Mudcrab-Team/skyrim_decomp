// Source exposure: binary-analysis; no external implementation source reused.
// Static174fa90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fa90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fa90*);
    virtual void release(Static174fa90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fa90*);
struct Static174fa90 {
    void* value;
    Static174fa90();
    ~Static174fa90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
