// Source exposure: binary-analysis; no external implementation source reused.
// Static1767780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767780*);
    virtual void release(Static1767780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767780*);
struct Static1767780 {
    void* value;
    Static1767780();
    ~Static1767780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
