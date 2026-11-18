// Source exposure: binary-analysis; no external implementation source reused.
// Static1772720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772720*);
    virtual void release(Static1772720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772720*);
struct Static1772720 {
    void* value;
    Static1772720();
    ~Static1772720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
