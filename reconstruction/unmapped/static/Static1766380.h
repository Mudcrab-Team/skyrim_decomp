// Source exposure: binary-analysis; no external implementation source reused.
// Static1766380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766380*);
    virtual void release(Static1766380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766380*);
struct Static1766380 {
    void* value;
    Static1766380();
    ~Static1766380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
