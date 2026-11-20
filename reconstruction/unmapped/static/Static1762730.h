// Source exposure: binary-analysis; no external implementation source reused.
// Static1762730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762730*);
    virtual void release(Static1762730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762730*);
struct Static1762730 {
    void* value;
    Static1762730();
    ~Static1762730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
