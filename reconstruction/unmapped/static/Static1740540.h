// Source exposure: binary-analysis; no external implementation source reused.
// Static1740540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740540*);
    virtual void release(Static1740540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740540*);
struct Static1740540 {
    void* value;
    Static1740540();
    ~Static1740540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
