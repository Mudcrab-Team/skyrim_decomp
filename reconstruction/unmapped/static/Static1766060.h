// Source exposure: binary-analysis; no external implementation source reused.
// Static1766060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766060*);
    virtual void release(Static1766060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766060*);
struct Static1766060 {
    void* value;
    Static1766060();
    ~Static1766060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
