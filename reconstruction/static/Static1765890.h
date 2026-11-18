// Source exposure: binary-analysis; no external implementation source reused.
// Static1765890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765890*);
    virtual void release(Static1765890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765890*);
struct Static1765890 {
    void* value;
    Static1765890();
    ~Static1765890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
