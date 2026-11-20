// Source exposure: binary-analysis; no external implementation source reused.
// Static1774250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774250*);
    virtual void release(Static1774250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774250*);
struct Static1774250 {
    void* value;
    Static1774250();
    ~Static1774250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
