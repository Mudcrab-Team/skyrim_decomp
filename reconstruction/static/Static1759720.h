// Source exposure: binary-analysis; no external implementation source reused.
// Static1759720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759720*);
    virtual void release(Static1759720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759720*);
struct Static1759720 {
    void* value;
    Static1759720();
    ~Static1759720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
