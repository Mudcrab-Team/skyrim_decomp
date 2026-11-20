// Source exposure: binary-analysis; no external implementation source reused.
// Static1748500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748500*);
    virtual void release(Static1748500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748500*);
struct Static1748500 {
    void* value;
    Static1748500();
    ~Static1748500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
