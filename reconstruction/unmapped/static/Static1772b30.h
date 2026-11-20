// Source exposure: binary-analysis; no external implementation source reused.
// Static1772b30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772b30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772b30*);
    virtual void release(Static1772b30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772b30*);
struct Static1772b30 {
    void* value;
    Static1772b30();
    ~Static1772b30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
