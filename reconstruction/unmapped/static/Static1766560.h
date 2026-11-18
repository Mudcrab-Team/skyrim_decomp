// Source exposure: binary-analysis; no external implementation source reused.
// Static1766560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766560*);
    virtual void release(Static1766560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766560*);
struct Static1766560 {
    void* value;
    Static1766560();
    ~Static1766560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
