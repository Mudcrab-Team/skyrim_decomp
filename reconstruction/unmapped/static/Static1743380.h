// Source exposure: binary-analysis; no external implementation source reused.
// Static1743380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743380*);
    virtual void release(Static1743380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743380*);
struct Static1743380 {
    void* value;
    Static1743380();
    ~Static1743380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
