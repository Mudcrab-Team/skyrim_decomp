// Source exposure: binary-analysis; no external implementation source reused.
// Static1773170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773170*);
    virtual void release(Static1773170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773170*);
struct Static1773170 {
    void* value;
    Static1773170();
    ~Static1773170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
