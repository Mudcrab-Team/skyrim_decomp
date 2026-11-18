// Source exposure: binary-analysis; no external implementation source reused.
// Static177a380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a380*);
    virtual void release(Static177a380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a380*);
struct Static177a380 {
    void* value;
    Static177a380();
    ~Static177a380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
