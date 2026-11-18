// Source exposure: binary-analysis; no external implementation source reused.
// Static177a060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a060*);
    virtual void release(Static177a060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a060*);
struct Static177a060 {
    void* value;
    Static177a060();
    ~Static177a060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
