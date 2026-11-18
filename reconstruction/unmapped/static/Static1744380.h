// Source exposure: binary-analysis; no external implementation source reused.
// Static1744380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744380*);
    virtual void release(Static1744380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744380*);
struct Static1744380 {
    void* value;
    Static1744380();
    ~Static1744380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
