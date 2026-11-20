// Source exposure: binary-analysis; no external implementation source reused.
// Static1773940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773940*);
    virtual void release(Static1773940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773940*);
struct Static1773940 {
    void* value;
    Static1773940();
    ~Static1773940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
