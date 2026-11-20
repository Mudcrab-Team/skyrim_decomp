// Source exposure: binary-analysis; no external implementation source reused.
// Static1785230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785230*);
    virtual void release(Static1785230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785230*);
struct Static1785230 {
    void* value;
    Static1785230();
    ~Static1785230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
