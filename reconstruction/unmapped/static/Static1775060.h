// Source exposure: binary-analysis; no external implementation source reused.
// Static1775060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775060*);
    virtual void release(Static1775060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775060*);
struct Static1775060 {
    void* value;
    Static1775060();
    ~Static1775060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
