// Source exposure: binary-analysis; no external implementation source reused.
// Static1779340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779340*);
    virtual void release(Static1779340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779340*);
struct Static1779340 {
    void* value;
    Static1779340();
    ~Static1779340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
