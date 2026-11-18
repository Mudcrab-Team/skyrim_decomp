// Source exposure: binary-analysis; no external implementation source reused.
// Static1793780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1793780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1793780*);
    virtual void release(Static1793780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1793780*);
struct Static1793780 {
    void* value;
    Static1793780();
    ~Static1793780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
