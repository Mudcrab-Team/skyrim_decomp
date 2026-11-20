// Source exposure: binary-analysis; no external implementation source reused.
// Static1743060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743060*);
    virtual void release(Static1743060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743060*);
struct Static1743060 {
    void* value;
    Static1743060();
    ~Static1743060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
