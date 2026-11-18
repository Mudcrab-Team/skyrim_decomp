// Source exposure: binary-analysis; no external implementation source reused.
// Static1766790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766790*);
    virtual void release(Static1766790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766790*);
struct Static1766790 {
    void* value;
    Static1766790();
    ~Static1766790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
