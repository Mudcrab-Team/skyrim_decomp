// Source exposure: binary-analysis; no external implementation source reused.
// Static1772540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772540*);
    virtual void release(Static1772540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772540*);
struct Static1772540 {
    void* value;
    Static1772540();
    ~Static1772540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
