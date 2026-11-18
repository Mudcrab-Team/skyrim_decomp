// Source exposure: binary-analysis; no external implementation source reused.
// Static174f030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f030*);
    virtual void release(Static174f030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f030*);
struct Static174f030 {
    void* value;
    Static174f030();
    ~Static174f030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
