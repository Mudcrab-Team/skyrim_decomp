// Source exposure: binary-analysis; no external implementation source reused.
// Static1768d10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768d10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768d10*);
    virtual void release(Static1768d10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768d10*);
struct Static1768d10 {
    void* value;
    Static1768d10();
    ~Static1768d10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
