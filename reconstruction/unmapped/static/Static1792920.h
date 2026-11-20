// Source exposure: binary-analysis; no external implementation source reused.
// Static1792920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792920*);
    virtual void release(Static1792920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792920*);
struct Static1792920 {
    void* value;
    Static1792920();
    ~Static1792920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
